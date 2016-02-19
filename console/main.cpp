#include "infinity.h"

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

struct Drawing : UsingUpdate, UsingRender {
	Texture rgb, hsv;
	float shift, sat;
	
	Drawing( Texture a, Texture b )
		: rgb(a), hsv(b), shift(0.f), sat(0.f) { ; }
		
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
		InfiGLActivateTrace();
		InfiConvertTexture( rgb, hsv, InfiHSVtoRGB() );
		InfiPushCamera();
		InfiDrawRect( rectf( (vec2)rgb->dimensions/2, (vec2)rgb->dimensions ), rgb );
		InfiPopCamera();
		InfiGLDeactivateTrace();
	}
};

void init( infi_parameters_t& param ) {
	Texture loadin0 = io::InfiLoadTexture( "res/test/flowers/hibiscus.jpg" );
	Texture tohsv = InfiConvertTexture( loadin0, InfiRGBtoHSV() );
	
	// create the window
	Window win = InfiCreateWindow( "HSV Represented in RGB", loadin0->dimensions );
	win->clearcolor = {.25,.25,.25,1.0};
	
	// attach objects to window
	InfiExtendWindow( win, new quit );
	InfiExtendWindow( win, new Drawing( loadin0, tohsv ) );
}

int main() {
	InfiMain( init );
	return 0;
}