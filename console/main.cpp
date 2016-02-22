#include "infinity.h"
#include <fstream>

using namespace INFI;
using namespace core;
using namespace render;

struct quit : UsingUpdate {
	quit() : infi_extension_t( "Quit Component" ) { ; }
	void Update( float64 dt ) {
		if ( Keyboard.escape.pressed() )
			InfiDestroyWindow( &this->Parent() );
	}
};

struct Drawing : virtual UsingUpdate,
				 virtual UsingRender {
	Texture rgb, hsv;
	float shift, sat;
	
	Drawing( Texture a, Texture b ) :
		UsingRender( 10 ),
		rgb(a),
		hsv(b),
		shift(0.f),
		sat(0.f) { ; }
		
	void Update( double dt ) {
		if ( Keyboard.down ) {
			shift -= 0.01;
		}
		if ( Keyboard.up ) {
			shift += 0.01;
		}
		if ( Keyboard.left ) {
			sat -= 0.01;
		}
		if ( Keyboard.right ) {
			sat += 0.01;
		}
		InfiHSVtoRGB()->uniform3f( "hsv_shift", vec3(shift,sat,0) );
	}
	
	void Render( const vec2ui& frame, double dt ) {
		InfiConvertTexture( rgb, hsv, InfiHSVtoRGB() );
		InfiPushCamera();
		InfiGLPushBlendMode( BlendMix() );
		InfiDrawRect( rgb->dimensions, rgb );
		InfiPopCamera();
	}
};

struct simplerect : UsingRender {
	Texture t;
	simplerect( Texture tt ) :
		UsingRender( 10 ),
		t(tt) { ; }
	void Render( const vec2ui& frame, double dt ) {
		InfiPushCamera();
		InfiGLPushBlendMode( BlendMix() );
		InfiDrawRect( rectf( (vec2)Mouse.position(), (vec2)t->dimensions ), t );
		InfiGLPopBlendMode();
		InfiPopCamera();
	}
};

void init( infi_parameters_t& param ) {
	Font f1 = text::InfiCreateFont( "Constantia", 64 );
	Font f2 = text::InfiCreateFont( "Constantia", 64, text::INFI_FONT_REGULAR, 8 );
	
	MultiFont f3 = text::InfiCreateMultiFont();
	text::InfiAddToMultiFont( f3, f2, vec3(0,0,0) );
	text::InfiAddToMultiFont( f3, f1, vec3(1,1,1) );
	
	Texture loadin0 = io::InfiLoadTexture( "res/test/flowers/hibiscus.jpg" );
	Texture tohsv = InfiConvertTexture( loadin0, InfiRGBtoHSV() );
	
	// create the window
	Window win = InfiCreateWindow( "HSV Represented in RGB",
									loadin0->dimensions );
	win->clearcolor = {.25,.25,.25,1.0};
	
	Label* lab = new Label( "Hi Tahsin!", f3, vec2(), 100 );
	vec2 pos = loadin0->dimensions / 2 - lab->buffer->dimensions / 2;
	lab->position = vec3( pos.x, pos.y, 0 );
	
	// attach objects to window
	InfiExtendWindow( win, new quit );
	InfiExtendWindow( win, new Drawing( loadin0, tohsv ) );
	InfiExtendWindow( win, lab );
}

int main() {
	InfiMain( init );
	return 0;
}