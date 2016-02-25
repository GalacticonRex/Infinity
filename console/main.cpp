#include "infinity.h"
#include <fstream>

using namespace INFI;
using namespace core;
using namespace render;
using namespace text;

struct Quit : UsingUpdate {
	Quit() :
		Extension( "Quit Component" ) { ; }
	Infi_Update( dt ) {
		if ( Keyboard.escape.pressed() )
			InfiDestroyWindow( &this->Parent() );
	}
};

struct Drawing : virtual UsingUpdate,
				 virtual UsingRender {
	Texture rgb, hsv;
	float32 shift, sat;
	
	Drawing( Texture a, Texture b ) :
		Extension( "Draw Image" ),
		UsingRender( 10 ),
		rgb(a),
		hsv(b),
		shift(0.f),
		sat(0.f) { ; }
		
	Infi_Update( dt ) {
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
	
	Infi_Render( frame, dt ) {
		InfiConvertTexture( rgb, hsv, InfiHSVtoRGB() );
		InfiPushCamera();
		InfiGLPushBlendMode( BlendMix() );
		InfiDrawRect( rgb->dimensions, rgb );
		InfiPopCamera();
	}
};

struct Model : UsingUpdate, UsingRender {
	Program shader;
	Vertices model;
	Camera cam;
	axisangle_t aa1, aa2;
	
	
	Model( core::vec3 v, Program s, Vertices m ) :
		Extension( "Draw Model" ),
		UsingRender( 100 ), 
		shader( s ),
		model( m ),
		cam( InfiCreateCamera(v) ),
		aa1( vec3(0,1,0), 0 ),
		aa2( vec3(0,0,1), 0 ) { ; }
	 ~Model() {
	 	delete cam;
	 }
	 
	 Infi_Update( dt ) {
	 	aa2.angle += dt;
	 	aa1.angle += dt;
	 	aa1.axis = Rotate( vec3(0,1,0), aa2 );
	 }
	 Infi_Render( frame, dt ) {
	 	InfiPushCamera( cam );
	 	InfiPushProgram( shader );
	 	InfiPushVertices( model );
	 	
	 	InfiPushTransform();
	 	InfiRotate( aa1 );
	 	InfiRotate( aa2 );
	 	InfiScale( sin( InfiGetProgramTime() ) + 2.f );
	 	
	 	InfiDraw();
	 	
	 	InfiPopTransform();
	 	
	 	InfiPopVertices();
	 	InfiPopProgram();
	 	InfiPopCamera();
	 }
};

void Init( infi_parameters_t& param ) {
	Font f1 = InfiCreateFont( "Constantia", 64 );
	Font f2 = InfiCreateFont( "Constantia", 64, INFI_FONT_REGULAR, 8 );
	
	MultiFont f3 = InfiCreateMultiFont();
	InfiAddToMultiFont( f3, f2, vec3(0,0,0) );
	InfiAddToMultiFont( f3, f1, vec3(1,1,1) );
	
	Texture loadin0 = io::InfiLoadTexture( "res/test/flowers/hibiscus.jpg" );
	Texture tohsv = InfiConvertTexture( loadin0, InfiRGBtoHSV() );
	
	Vertices cube = io::InfiLoadModel( "res/test/shapes/cube.obj" );
	
	Program prog = InfiCreateProgram();
	InfiVertexShaderFromFile( prog, "console/vertex.glsl" );
	InfiFragmentShaderFromFile( prog, "console/fragment.glsl" );
		prog->uniformMat4( "transform", InfiGetTransform );
		prog->uniformMat4( "viewport", InfiGetCamera );
		prog->uniformSampler( "teximage1", loadin0 );
	
	Model* nobj = new Model( vec3(0,0,6), prog, cube );
	
	// create the window
	Window win = InfiCreateWindow( "HSV Represented in RGB",
									loadin0->dimensions );
	
	Label* lab = new Label( "Hello World", f3, vec2(), 1000 );
	vec2 pos = loadin0->dimensions / 2 - lab->buffer->dimensions / 2;
	lab->position = vec3( pos.x, pos.y, 0 );
	
	// attach objects to window
	InfiExtendWindow( win, new Quit );
	InfiExtendWindow( win, new Drawing( loadin0, tohsv ) );
	InfiExtendWindow( win, nobj );
	InfiExtendWindow( win, lab );
}

int main() {
	InfiMain( Init );
	return 0;
}