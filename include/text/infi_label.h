#ifndef __INFI_LABEL_H__
#define __INFI_LABEL_H__

#include "text/infi_font.h"
#include "main/infi_renderable.h"

namespace INFI {
namespace text {
	
	struct infi_label_t : infi_renderable_t {
		render::infi_texture_t* buffer;
		
		infi_font_t* ft;
		core::string_t data;
		
		core::vec3 position;
		core::vec4 color;
		
		
		infi_label_t( const core::string_t&, // Text
					  const core::string_t&, // Font Name
					  core::vec2i,			 // Position
					  uint32 = 12 );			 // Font Size
		
		infi_label_t( const core::string_t&, // Text
					  const core::string_t&, // Font Name
					  INFI_fontFlags, 		 // Font Flags
					  core::vec2i,			 // Position
					  uint32 = 12 );			 // Font Size
		
		infi_label_t( const core::string_t&, // Text
					  infi_font_t*, 		 // Font
					  core::vec2i );		 // Position
		
		void Render( const core::vec2ui&, float64 );
	};
	
	INFI_FUNCTION( void, InfiRedrawLabel, ( infi_label_t* ) );
	INFI_FUNCTION( void, InfiSetLabelText, ( infi_label_t*, const core::string_t& ) );
	INFI_FUNCTION( void, InfiSetLabelFont, ( infi_label_t*, infi_font_t* ) );
	
} }

#endif//__INFI_LABEL_H__