#include "infinity.h"
#include <fstream>

using namespace INFI;
using namespace core;
using namespace render;

Program program;
Vertices rectv;

struct quit : UsingUpdate {
	quit() : infi_extension_t( "Quit Component" ) { ; }
	void Update( float64 dt ) {
		if ( Keyboard.escape.pressed() )
			InfiDestroyWindow( &this->Parent() );
		
		if ( Mouse.left.pressed() ) {
			std::cerr << (vec2i) Mouse << std::endl;
		}
	}
};

struct drawsingle : UsingUpdate, UsingRender {
	vec2 position;
	uint32 index;
	array_t<Texture> texs;
	float rotation;
	
	drawsingle( vec2 pos ) :
		infi_extension_t( "Draw Rect" ),
		position( pos ),
		rotation(0.f) { ; }
	
	void add( Texture t ) {
		texs.add( t );
	}
	void Update( float64 dt ) {
		if ( Keyboard.up.pressed() ) { 
			(++ index) %= texs.size();
		}
		if ( Keyboard.down.pressed() ) {
			(index+=texs.size()-1) %= texs.size();
		}
	}
	void Render( const vec2ui& frame, double dt ) {
		if ( index >= texs.size() )
			return;
		InfiPushCamera();
		Texture t = texs[index];
		InfiDrawRect( rectf( position, (vec2)t->dimensions ), t, rotation );
		InfiPopCamera();
	}
};

void init( infi_parameters_t& param ) {
	// load in a texture
	Texture loadin0 = io::InfiLoadTexture( "res/test/trees/tree.jpg" );
	
	// this is allowed but it shouldn't be...
	// InfiConvertTexture( loadin0, loadin0, InfiRGBtoHSV() );
	
	// applies a shader to a single texture
	Texture tohsv = InfiConvertTexture( loadin0, InfiRGBtoHSV() );
	Texture torgb = InfiConvertTexture( tohsv, InfiHSVtoRGB() );
	
	// create the window
	Window win = InfiCreateWindow( "HSV Represented in RGB", loadin0->dimensions*1.1 );
	
	// create the viewing object
	drawsingle* drawing = new drawsingle( win->dimensions / 2.f );
	drawing->add( tohsv );
	drawing->add( torgb );
	
	// attach objects to window
	InfiExtendWindow( win, new quit );
	InfiExtendWindow( win, drawing );
}

/*====================================================================================*/

const float& get_value() {
	static float mine;
	mine = ( std::sin( InfiGetTime() * 2.f ) + 1.f ) / 2.f;
	return mine;
}

struct testrender : UsingRender {
	Texture tex1, tex2, tex3;
	
	testrender( Texture t1, Texture t2, Texture t3 ) :
		infi_extension_t( "Test Render" ),
		tex1( t1 ),
		tex2( t2 ),
		tex3( t3 ) { ; }
	
	void Render( const core::vec2ui& frame, double dt ) {
		InfiPushCamera();
		InfiPushProgram( program );
		InfiPushVertices( rectv );
		
		InfiPushTransform();
		InfiScale( tex1->dimensions );
		
		program->uniformSampler( "teximage1", tex1 );
		program->uniformSampler( "teximage2", tex2 );
		program->uniformSampler( "teximage3", tex3 );
		
		InfiDraw();
		
		InfiPopTransform();
		
		InfiPopProgram();
		InfiPopVertices();
		InfiPopCamera();
	}
};

struct drawrects : UsingRender {
	Texture tex;
	
	drawrects( Texture t ) :
		infi_extension_t( "Draw 9 Rect" ),
		tex( t ) { ; }
	void Render( const core::vec2ui& frame, double dt ) {
		InfiPushCamera();
		InfiPushProgram( InfiRect2DShader() );
		InfiPushVertices( InfiRect2DVertices() );
		
		InfiRect2DShader()->uniformSampler( "teximage", tex );
		InfiRect2DShader()->uniformf( "use", 1.f );
		
		vec2 dim = tex->dimensions / 3.f;
		for ( uint32 i=0;i<9;++i ) {
			InfiPushTransform();
			InfiTranslate( dim.x*(i%3), dim.y*(i/3) );
			InfiScale( dim );
			InfiTranslate( 0.5, 0.5 );
			InfiRotate( i * MATH_PI / 2 );
			InfiTranslate( -0.5, -0.5 );
			InfiDraw();
			InfiPopTransform();
		}
		
		InfiPopProgram();
		InfiPopVertices();
		InfiPopCamera();
	}
};
void create_stuff( Texture& loadin1, Texture& loadin2 ) {
	loadin1 = io::InfiLoadTexture( "res/test/flowers/water_lily.jpg" );
	loadin2 = io::InfiLoadTexture( "res/test/flowers/orchid.jpg" ); 
	
	program = InfiCreateProgram();
	InfiVertexShaderFromFile( program, "console/vertex.glsl" );
	InfiFragmentShaderFromFile( program, "console/fragment.glsl" );
	
	program->uniformMat4( "transform", InfiGetTransform );
	program->uniformMat4( "viewport", InfiGetCamera );
	program->uniformf( "miximg", get_value );
	program->uniformf( "use", 1.f );
	
	float32 data[] = { 1.f,0.f, 1.f,0.f,
					   0.f,1.f, 0.f,1.f,
					   0.f,0.f, 0.f,0.f,
					   0.f,1.f, 0.f,1.f,
					   1.f,0.f, 1.f,0.f,
					   1.f,1.f, 1.f,1.f };
					   
	Buffer temp = new infi_buffer_t( raw_data_t<uint8>( sizeof(data), (uint8*)data ) );
	
	rectv = InfiCreateVertices();
	InfiSetFormat( rectv, Pos2Tex2() );
	InfiBindVertices( rectv, FormatBuffer( temp, Pos2Tex2() ) );
}

int main( int argc, char** argv ) {
	InfiGLActivateTrace();
	InfiMain( init );
	InfiGLDeactivateTrace();
	return 0;
}