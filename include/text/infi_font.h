#ifndef __INFI_FONT_H__
#define __INFI_FONT_H__

#include "main/infi_freetype.h"
#include "core/infi_map.h"
#include "text/infi_text.h"

namespace INFI {
namespace text {

struct infi_character_t {
	core::rectf sample;	 // location on sprite
	core::vec2i advance, // x is horizontal advance, y is unused
				before,	 // "
				after;	 // "
};

typedef std::map<char,infi_character_t*> CharMap;
typedef core::stack_t<infi_character_t*> CharCache;
typedef std::map<uint16,int32> KernMap;
typedef core::array_t<core::vec4i> spanl;
typedef core::array_t<core::vec4i>* spanlp;

struct infi_font_metrics_t {
	uint32 tabsize;
	uint32 linespace;
	uint32 spacing;
};

struct infi_font_functions_t {
	virtual void rasterize( const core::vec2i&, const core::string_t&, infi_font_functions_t* = NULL ) = 0;
	virtual infi_character_t* fetch( char ) = 0;
};

struct infi_font_fields_t {
	core::vec2i				mindim,
							maxdim;
	CharMap 				data;
	CharCache				old;
	KernMap 				kerning;
	render::infi_texture_t* buffer;
	infi_font_metrics_t* 	metrics;
	
	infi_character_t* self_get_new_char();
	void self_clear_all_chars();
};

struct infi_font_t : infi_font_functions_t,
					 infi_font_fields_t { };

struct infi_bmp_load_table_t {
	
};
struct infi_bmp_font_t : infi_font_t {
	render::infi_texture_t*	source;
	infi_bmp_load_table_t* import;
	
	void rasterize( const core::vec2i&, const core::string_t&, infi_font_functions_t* = NULL );
	infi_character_t* fetch( char );
};
struct infi_tt_font_t : infi_font_t {
	core::vec2ui	 anchor;
	uint32 			 size;
	uint32			 outline;
	FT_Face 		 source;
	FT_Raster_Params params;
	
	void rasterize( const core::vec2i&, const core::string_t&, infi_font_functions_t* = NULL );
	infi_character_t* fetch( char );
};
struct infi_font_container_t : infi_font_t {
	struct __node {
		infi_font_t* data;
		core::vec2i offset;
		core::vec3 color;
	};
	uint32 				  advance;
	core::array_t<__node> draw;
	
	void rasterize( const core::vec2i&, const core::string_t&, infi_font_functions_t* = NULL );
	infi_character_t* fetch( char );
};

INFI_FUNCTION( void, InfiLInitFonts, ( infi_font_fields_t* ) );

// create a TrueType font
INFI_FUNCTION( infi_tt_font_t*, InfiCreateFont, ( const core::string_t&, uint32, INFI_fontFlags=0, uint32=0 ) );

// create a Bitmap font
INFI_FUNCTION( infi_bmp_load_table_t*, InfiCreateBitmapFontLoader, () );
INFI_FUNCTION( infi_bmp_font_t*, InfiCreateBitmapFont, ( const render::infi_texture_t*, infi_bmp_load_table_t* ) );

// create a font container
INFI_FUNCTION( infi_font_container_t*, InfiCreateMultiFont, () );
INFI_FUNCTION( void, InfiAddToMultiFont, ( infi_font_container_t*, const core::string_t&, uint32, INFI_fontFlags=0, uint32 = 0, core::vec3=core::vec3(1,1,1), core::vec2i=core::vec2i() ) );
INFI_FUNCTION( void, InfiAddToMultiFont, ( infi_font_container_t*, infi_font_t*, core::vec3=core::vec3(1,1,1), core::vec2i=core::vec2i() ) );
INFI_FUNCTION( void, InfiSetMultiFontColor, ( infi_font_container_t*, core::vec3, uint32 = 0 ) );
INFI_FUNCTION( void, InfiSetAdvanceMultiFont, ( infi_font_container_t*, uint32 ) );

// set default font metrics
INFI_FUNCTION( void, InfiSetFontMetrics, ( const infi_font_metrics_t& ) );
INFI_FUNCTION( void, InfiSetFontMetrics, ( uint32, uint32, uint32 ) );
INFI_FUNCTION( void, InfiSetFontTabSize, ( uint32 ) );
INFI_FUNCTION( void, InfiSetFontLineSpacing, ( uint32 ) );
INFI_FUNCTION( void, InfiSetFontCharacterSpacing, ( uint32 ) );

// wrapper for font render
INFI_FUNCTION( void, InfiDrawText, ( infi_font_t*, const core::vec2i&, const core::string_t& ) );

// determine text size
INFI_FUNCTION( uint32, InfiTextWidth, ( infi_font_t*, const core::string_t& ) );
INFI_FUNCTION( core::vec2ui, InfiTextSize, ( infi_font_t*, const core::string_t& ) );

// get the kerning of two characters given a font
INFI_FUNCTION( int32, InfiGetKerning, ( infi_font_fields_t*, char, char ) );

} }

#endif//__INFI_FONT_H__