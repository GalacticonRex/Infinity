#include "main/infi_time.h"
#include "text/infi_label.h"
#include "render/infi_can_render.h"
#include "render/infi_standard_objects.h"
#include "render/infi_gl_wrapper.h"

namespace INFI {
namespace text {
	
	namespace {
		using namespace std;
		using namespace core;
		using namespace render;
	}
	
	static void generate_label( infi_label_t* lab ) {
		InfiPushCanvas( lab->buffer );
		InfiGLClearColor( 0.f,0.f,0.f,0.f );
		InfiGLClear( GL_COLOR_BUFFER_BIT |
					 GL_DEPTH_BUFFER_BIT |
					 GL_STENCIL_BUFFER_BIT );
		InfiGLPushBlendMode( BlendExact() );
		
		InfiGLSendMessage( "Rasterize Font!" );
		lab->ft->rasterize( {0,0}, lab->data );
		InfiGLSendMessage( "Rasterize Done!" );
		
		InfiGLPopBlendMode();
		InfiPopCanvas();
	}
	
	infi_label_t::infi_label_t( const string_t& txt,
				  				const string_t& fname,
				  				vec2i pos,
				  				uint32 size )
		: data( txt ), color(1,1,1,1) {
		ft = InfiCreateFont( fname, size, 0 );
		
		position.x = pos.x;
		position.y = pos.y;
		position.z = 1;
		
		int32 wid = InfiTextWidth(ft, txt);
		vec2i vv( wid, ft->maxdim.y - ft->mindim.y );
		buffer = InfiCreateTexture( vv, INFI_UBYTE, INFI_FLOAT, INFI_RGBA, true );
		
		generate_label( this );
	}
	
	infi_label_t::infi_label_t( const string_t& txt,
				  				const string_t& fname,
				  				INFI_fontFlags flags,
				  				vec2i pos,
				  				uint32 size )
		: data( txt ), color(1,1,1,1) {
		ft = InfiCreateFont( fname, size, flags );
		
		position.x = pos.x;
		position.y = pos.y;
		position.z = 1;
		
		int32 wid = InfiTextWidth(ft, txt);
		vec2i vv( wid, ft->maxdim.y - ft->mindim.y );
		buffer = InfiCreateTexture( vv, INFI_UBYTE, INFI_FLOAT, INFI_RGBA, true );
		
		generate_label( this );
	}
	
	infi_label_t::infi_label_t( const string_t& txt,
				  				infi_font_t* f,
				  				vec2i pos )
		: ft(f), data( txt ), color(1,1,1,1) {
		position.x = pos.x;
		position.y = pos.y;
		position.z = 1;
		
		int32 wid = InfiTextWidth(ft, txt);
		vec2i vv( wid, ft->maxdim.y - ft->mindim.y + 1 );
		buffer = InfiCreateTexture( vv, INFI_UBYTE, INFI_FLOAT, INFI_RGBA, true );
		
		generate_label( this );
	}

	void infi_label_t::Render( const vec2ui& frame, float64 dt ) {
		InfiGLPushBlendMode( BlendMix() );
		InfiDrawRect( position.xy(), buffer );
		InfiGLPopBlendMode();
	}
	
	void InfiRedrawLabel( infi_label_t* lab ) {
		generate_label( lab );
	}
	void InfiSetLabelText( infi_label_t* lab, const core::string_t& str ) {
		if ( lab->data == str )
			return;
		lab->data = str;
		generate_label( lab );
	}
	void InfiSetLabelFont( infi_label_t* lab, infi_font_t* ft ) {
		if ( lab->ft == ft )
			return;
		lab->ft = ft;
		generate_label( lab );
	}
		
} }