#include "text/infi_font.h"
#include "render/infi_can_render.h"
#include "render/infi_standard_objects.h"
#include "render/infi_gl_wrapper.h"
#include "main/infi_time.h"

namespace INFI {
namespace text {
	
	namespace {
		using namespace std;
		using namespace core;
		using namespace render;
	}
	
	infi_font_metrics_t glob_metrics;
	infi_orthogonal_t* view;

	void InfiLInitFonts( infi_font_fields_t* f ) {
		f->buffer = NULL;
		f->metrics = NULL;
		
		view = InfiCreateOrthogonal( vec2(), vec2(1,1) );
	}
	
	infi_character_t* infi_font_fields_t::self_get_new_char() {
		infi_character_t* nchar = NULL;
		if ( old.empty() ) {
			nchar = new infi_character_t;
		} else {
			nchar = old[0];
			old.pop();
		}
		return nchar;
	}
	void infi_font_fields_t::self_clear_all_chars() {
		CharMap::iterator iter = data.begin();
		for ( ;iter!=data.end();++iter )
			old.push( iter->second );
		data.clear();
	}
	
	void infi_tt_font_t::rasterize( const vec2i& inpen, const string_t& str, infi_font_functions_t* adv ) {
		if ( str.size() == 0 )
			return;
		
		InfiGLDepthMask( false );
		
		infi_program_t* prog;
		vec2i pen = inpen - vec2i( fetch( str[0] )->before.x, 0 );
		infi_font_metrics_t* met = (metrics) ? metrics : &glob_metrics;
		
		InfiPushCamera();
		InfiPushProgram( prog=InfiRect2DShader() );
		InfiPushVertices( InfiRect2DVertices() );
		
		prog->uniformSampler( "teximage", buffer );
		prog->uniformf( "use", 1.f );
		
		for ( uint32 i=0;i<str.size();i++ ) {
			infi_character_t* cc = fetch( str[i] );
			
			InfiPushTransform();
			
			vec2ui dim( cc->after.x - cc->before.x + 1,
						cc->after.y - cc->before.y + 1 );
			
			InfiTranslate( pen + vec2( cc->before.x, cc->before.y - mindim.y ) );
			InfiScale( dim );
			
			prog->uniform2f( "texture_shift", cc->sample.pos );
			prog->uniform2f( "texture_scale", cc->sample.dim );
			
			InfiDraw();
			
			InfiPopTransform();
			
			cc = ( adv == NULL ) ? cc : adv->fetch( str[i] );
			pen.x += cc->advance.x + met->spacing;
		}
		
		prog->uniform2f( "texture_shift", vec2(1,1) );
		prog->uniform2f( "texture_scale", vec2(1,1) );
		
		InfiPopVertices();
		InfiPopProgram();
		InfiPopCamera();
		
		InfiGLDepthMask( true );
	}
	
	void InfiSetFontMetrics( const infi_font_metrics_t& met ) {
		glob_metrics = met;
	}
	void InfiSetFontMetrics( uint32 tb, uint32 ln, uint32 sp ) {
		glob_metrics.tabsize = tb;
		glob_metrics.linespace = ln;
		glob_metrics.spacing = sp;
	}
	void InfiSetFontTabSize( uint32 tb ) {
		glob_metrics.tabsize = tb;
	}
	void InfiSetFontLineSpacing( uint32 ln ) {
		glob_metrics.linespace = ln;
	}
	void InfiSetFontCharacterSpacing( uint32 sp ) {
		glob_metrics.spacing = sp;
	}
	
	void InfiDrawText( infi_font_t* ft, const vec2i& pos, const string_t& str ) {
		if ( str.size() == 0 )
			return;
		for ( uint32 i=0;i<str.size();i++ )
			ft->fetch( str[i] );
		ft->rasterize( pos, str );
	}
	
	uint32 InfiTextWidth( infi_font_t* ft, const string_t& str ) {
		infi_font_metrics_t* met = (ft->metrics) ? ft->metrics : &glob_metrics;
		
		uint32 wid = 0;
		for ( uint32 i=0;i<str.size();i++ ) {
			if ( str[i] == '\n' )
				return wid;
			
			infi_character_t* cc = ft->fetch( str[i] );
			if ( wid == 0 ) wid += -cc->before.x;
			if ( i == str.last() )
				wid += cc->after.x;
			else
				wid += cc->advance.x + met->spacing;
		}
		return wid;
	}
	
	//vec2ui InfiTextSize( const infi_font_t*, const string_t& ) );

	//int32 InfiGetKerning( const infi_font_fields_t*, char, char ) );

} }