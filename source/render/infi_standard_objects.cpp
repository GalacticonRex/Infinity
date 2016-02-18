#ifndef __INFI_STANDARD_OBJECTS_H__
#define __INFI_STANDARD_OBJECTS_H__

#include "core/infi_raw_data.h"
#include "render/infi_standard_objects.h"
#include "render/infi_can_render.h"

namespace INFI {
namespace render {
	
static infi_program_t* __rect2dshader;
static infi_program_t* __hsvtorgb;
static infi_program_t* __rgbtohsv;
static infi_program_t* __hsvblend;
static infi_buffer_t* __rect2ddata;
static infi_vertices_t* __rect2dverts;

static core::string_t __rect2dshader_vertex =
	"#version 150\n"
	"uniform mat4 transform;"
	"uniform mat4 viewport;"
	"uniform vec2 texture_shift = vec2(0,0);"
	"uniform vec2 texture_scale = vec2(1,1);"
	"in vec2 position;"
	"in vec2 texcoord;"
	"out vec2 v_texcoord;"
	"void main() {"
	"	gl_Position = viewport * transform * vec4( position, 1,1 );"
	"	v_texcoord = ( texcoord * texture_scale ) + texture_shift;"
	"}";
static core::string_t __rect2dshader_fragment =
	"#version 150\n"
	"uniform float use = 0;"
	"uniform sampler2D teximage;"
	"uniform vec4 color = vec4(1,1,1,1);"
	"in vec2 v_texcoord;"
	"out vec4 fragout;"
	"void main() {"
	"	fragout = color*(use*texture2D(teximage,v_texcoord)+"
	"					(1-use)*vec4(1,1,1,1));"
	"}";
	
static core::string_t __rect2dshader_rgbtohsv =
	"#version 150\n"
	"#define M_PI 3.1415926535897932384626433832795\n"
	"uniform sampler2D teximage;"
	"in vec2 v_texcoord;"
	"out vec4 fragout;"
	"void main() {"
	"	vec4 c = texture2D( teximage, v_texcoord );"
	"	float mmin = min( min( c.r, c.g ), c.b );"
	"	float mmax = max( max( c.r, c.g ), c.b );"
	"	float delta = mmax - mmin;"
	"	float h = (1 - ceil( mmax - c.r ))*(0+(c.g-c.b)/delta) +"
	"			  (1 - ceil( mmax - c.g ))*(2+(c.g-c.b)/delta) +"
	"			  (1 - ceil( mmax - c.b ))*(4+(c.g-c.b)/delta);"
	"	float s = 0;"
	"	if ( mmax != 0 )"
	"		s = delta / mmax;"
	"	h *= M_PI / 3;"
	"	while ( h < 0 )"
	"		h += M_PI * 2;"
	"	fragout = vec4( h, s, mmax, c.a );"
	"}";
	
static core::string_t __rect2dshader_hsvtorgb =
	"#version 150\n"
	"#define M_PI 3.1415926535897932384626433832795\n"
	"uniform sampler2D teximage;"
	"in vec2 v_texcoord;"
	"out vec4 fragout;"
	"void main() {"
	"	vec4 c = texture2D( teximage, v_texcoord );"
	"	float h = c.r;"
	"	float s = c.g;"
	"	float v = c.b;"
	"	if ( s == 0 )"
	"		fragout = vec4( v,v,v,c.a );"
	"	else {"
	"		while ( h < 0 )"
	"			h += M_PI * 2;"
	"		h *= 3 / M_PI;"
	"		float fh = floor(h);"
	"		float f = h - fh;"
	"		float i = floor( fh/2 );"
	"		float p = v * ( 1 - s );"
	"		float q = v * ( 1 - s * f );"
	"		float t = v * ( 1 - s * (1-f) );"
	"		float r = p * (1-abs(i-1)) +"
	"				  q * (1-clamp(abs(fh-1),0,1)) +"
	"				  t * (1-clamp(abs(fh-4),0,1)) +"
	"				  v * (1-(clamp(fh,0,1)-floor(fh/5)));"
	"		float g = p * clamp(i-1,0,1) +"
	"				  q * (1-clamp(abs(fh-3),0,1)) +"
	"				  t * (1-clamp(fh,0,1)) +"
	"				  v * (1-clamp(abs(ceil( fh/2 )-1),0,1));"
	"		float b = p * clamp(1-i,0,1) +"
	"				  q * clamp(fh-4,0,1) +"
	"				  t * (1-clamp(abs(fh-2),0,1)) +"
	"				  v * (1-clamp(abs(ceil( fh/2 )-2),0,1));"
	"		fragout = vec4( r,g,b, c.a );"
	"	}"
	"}";
	
static core::string_t __rect2dshader_hsvblend =
	"#version 150\n"
	"#define M_PI 3.1415926535897932384626433832795\n"
	"uniform sampler2D teximage;"
	"uniform float use;"
	"uniform vec4 color = vec4(1,1,1,1);"
	"in vec2 v_texcoord;"
	"out vec4 fragout;"
	"void main() {"
		
	"}";

static void InfiLInitVertexFormats();
static void InfiLInitBlendModes();

void InfiLInitObjects() {
	InfiPushFunction( "Initialize Standard Objects" ); 
	InfiLInitVertexFormats();
	InfiLInitBlendModes();
	
	__rect2dshader = InfiCreateProgram();
	InfiVertexShader( __rect2dshader, __rect2dshader_vertex );
	InfiFragmentShader( __rect2dshader, __rect2dshader_fragment );
	
	__rect2dshader->uniformMat4( "transform", InfiGetTransform );
	__rect2dshader->uniformMat4( "viewport", InfiGetCamera );
	__rect2dshader->uniform4f( "color", InfiGetColor );
	
	__hsvtorgb = InfiCreateProgram();
	InfiVertexShader( __hsvtorgb, __rect2dshader_vertex );
	InfiFragmentShader( __hsvtorgb, __rect2dshader_hsvtorgb );
	
	__hsvtorgb->uniformMat4( "transform", InfiGetTransform );
	__hsvtorgb->uniformMat4( "viewport", InfiGetCamera );
	
	__rgbtohsv = InfiCreateProgram();
	InfiVertexShader( __rgbtohsv, __rect2dshader_vertex );
	InfiFragmentShader( __rgbtohsv, __rect2dshader_rgbtohsv );
	
	__rgbtohsv->uniformMat4( "transform", InfiGetTransform );
	__rgbtohsv->uniformMat4( "viewport", InfiGetCamera );
	
	__hsvblend = InfiCreateProgram();
	InfiVertexShader( __hsvblend, __rect2dshader_vertex );
	InfiFragmentShader( __hsvblend, __rect2dshader_hsvblend );
	
	__hsvblend->uniformMat4( "transform", InfiGetTransform );
	__hsvblend->uniformMat4( "viewport", InfiGetCamera );
	__hsvblend->uniform4f( "color", InfiGetColor );
	
	float32 data[] = { 1.f,0.f, 1.f,0.f,
					   0.f,1.f, 0.f,1.f,
					   0.f,0.f, 0.f,0.f,
					   0.f,1.f, 0.f,1.f,
					   1.f,0.f, 1.f,0.f,
					   1.f,1.f, 1.f,1.f };
	
	__rect2ddata = new infi_buffer_t( core::raw_data_t<uint8>( sizeof(data), (uint8*)data ) );
	
	__rect2dverts = InfiCreateVertices();
	InfiSetFormat( __rect2dverts, Pos2Tex2() );
	InfiBindVertices( __rect2dverts, infi_formatted_buffer_t( __rect2ddata, Pos2Tex2() ) );
	InfiPopFunction();
}
void InfiLQuitObjects() {
	delete __rect2ddata;
	InfiDestroyProgram( __rect2dshader );
	InfiDestroyProgram( __hsvtorgb );
	InfiDestroyProgram( __rgbtohsv );
	InfiDestroyVertices( __rect2dverts );
}

infi_program_t* InfiRect2DShader() {
	return __rect2dshader;
}
infi_program_t* InfiHSVtoRGB() {
	return __hsvtorgb;
}
infi_program_t* InfiRGBtoHSV() {
	return __rgbtohsv;
}
infi_program_t* InfiHSVBlend() {
	return __hsvblend;
}

infi_vertices_t* InfiRect2DVertices() {
	return __rect2dverts;
}

void InfiDrawRect( core::rectf rt, infi_texture_t* tex, float32 rotation ) {
	InfiPushProgram( InfiRect2DShader() );
	InfiPushVertices( InfiRect2DVertices() );
	
	if ( tex != NULL ) {
		InfiRect2DShader()->uniformSampler( "teximage", tex );
		InfiRect2DShader()->uniformf( "use", .7f );
	} else
		InfiRect2DShader()->uniformf( "use", .7f );
	
	InfiPushTransform();
		InfiTranslate( rt.pos );
		InfiScale( rt.dim );
		if ( rotation != 0.f )
			InfiRotate( rotation );
		InfiTranslate( -0.5, -0.5 );
		InfiDraw();
	InfiPopTransform();
	
	InfiPopProgram();
	InfiPopVertices();
}

infi_texture_t* InfiConvertTexture( infi_texture_t* input, infi_program_t* prog, const char* name ) {
	infi_texture_t* output = InfiCopyTexture( input );
	InfiConvertTexture( output, input, prog, name );
	return output;
}
void InfiConvertTexture( infi_texture_t* output, infi_texture_t* input, infi_program_t* prog, const char* name ) {
	InfiPushCanvas( output );
	
	InfiPushCamera();
	InfiPushProgram( prog );
	InfiPushVertices( InfiRect2DVertices() );
	
	prog->uniformSampler( name, input );
	
	InfiPushTransform();
	InfiScale( output->dimensions );
	InfiDraw();
	InfiPopTransform();
	
	InfiPopCamera();
	InfiPopProgram();
	InfiPopVertices();
	
	InfiPopCanvas();
}

#define GET_FORMAT( name ) \
		static infi_format_t* __ ## name = NULL; \
		infi_format_t const* name() { \
			return __ ## name; \
		}

GET_FORMAT( Position2 );
GET_FORMAT( Position3 );
GET_FORMAT( Position4 );
GET_FORMAT( Pos2Tex2 );
GET_FORMAT( Pos2Tex3 );
GET_FORMAT( Pos2Tex4 );
GET_FORMAT( Pos3Tex2 );
GET_FORMAT( Pos3Tex3 );
GET_FORMAT( Pos3Tex4 );
GET_FORMAT( Pos4Tex2 );
GET_FORMAT( Pos4Tex3 );
GET_FORMAT( Pos4Tex4 );
GET_FORMAT( Position2Norm );
GET_FORMAT( Position3Norm );
GET_FORMAT( Position4Norm );
GET_FORMAT( Pos2Tex2Norm );
GET_FORMAT( Pos2Tex3Norm );
GET_FORMAT( Pos2Tex4Norm );
GET_FORMAT( Pos3Tex2Norm );
GET_FORMAT( Pos3Tex3Norm );
GET_FORMAT( Pos3Tex4Norm );
GET_FORMAT( Pos4Tex2Norm );
GET_FORMAT( Pos4Tex3Norm );
GET_FORMAT( Pos4Tex4Norm );

#define MAKE_SINGLE_( name, str1, type1, count1 ) \
		__ ## name = new infi_format_t(); \
		__ ## name -> add( str1, type1, count1 );
#define MAKE_DOUBLE_( name, str1, type1, count1, str2, type2, count2 ) \
		MAKE_SINGLE_( name, str1, type1, count1 ) \
		__ ## name -> add( str2, type2, count2 );
		
#define MAKE_SINGLE( name, str1, type1, count1 ) \
		MAKE_SINGLE_( name, str1, type1, count1 ) \
		__ ## name -> finalize();
		
#define MAKE_DOUBLE( name, str1, type1, count1, str2, type2, count2 ) \
		MAKE_DOUBLE_( name, str1, type1, count1, str2, type2, count2 ) \
		__ ## name -> finalize();
		
#define MAKE_TRIPLE( name, str1, type1, count1, str2, type2, count2, str3, type3, count3 ) \
		MAKE_DOUBLE_( name, str1, type1, count1, str2, type2, count2 ) \
		__ ## name -> add( str3, type3, count3 ); \
		__ ## name -> finalize();

static void InfiLInitVertexFormats() {
	MAKE_SINGLE( Position2, 	"Position", INFI_FLOAT, 2 );
	MAKE_SINGLE( Position3, 	"Position", INFI_FLOAT, 3 );
	MAKE_SINGLE( Position4, 	"Position", INFI_FLOAT, 4 );
	
	MAKE_DOUBLE( Pos2Tex2, 		"Position", INFI_FLOAT, 2,
								"Texture", INFI_FLOAT, 2 );
	MAKE_DOUBLE( Pos3Tex2, 		"Position", INFI_FLOAT, 3,
								"Texture", INFI_FLOAT, 2 );
	MAKE_DOUBLE( Pos4Tex2, 		"Position", INFI_FLOAT, 4,
								"Texture", INFI_FLOAT, 2 );
	
	MAKE_DOUBLE( Pos2Tex3, 		"Position", INFI_FLOAT, 2,
								"Texture", INFI_FLOAT, 3 );
	MAKE_DOUBLE( Pos3Tex3, 		"Position", INFI_FLOAT, 3,
								"Texture", INFI_FLOAT, 3 );
	MAKE_DOUBLE( Pos4Tex3, 		"Position", INFI_FLOAT, 4,
								"Texture", INFI_FLOAT, 3 );
	
	MAKE_DOUBLE( Pos2Tex4, 		"Position", INFI_FLOAT, 2,
								"Texture", INFI_FLOAT, 4 );
	MAKE_DOUBLE( Pos3Tex4, 		"Position", INFI_FLOAT, 3,
								"Texture", INFI_FLOAT, 4 );
	MAKE_DOUBLE( Pos4Tex4, 		"Position", INFI_FLOAT, 4,
								"Texture", INFI_FLOAT, 4 );
	
	MAKE_DOUBLE( Position2Norm, "Position", INFI_FLOAT, 2,
								"Normal", INFI_FLOAT, 3 );
	MAKE_DOUBLE( Position3Norm, "Position", INFI_FLOAT, 3,
								"Normal", INFI_FLOAT, 3 );
	MAKE_DOUBLE( Position4Norm, "Position", INFI_FLOAT, 4,
								"Normal", INFI_FLOAT, 3 );
	
	MAKE_TRIPLE( Pos2Tex2Norm, 	"Position", INFI_FLOAT, 2,
								"Texture", INFI_FLOAT, 2,
								"Normal", INFI_FLOAT, 3 );
	MAKE_TRIPLE( Pos3Tex2Norm, 	"Position", INFI_FLOAT, 3,
								"Texture", INFI_FLOAT, 2,
								"Normal", INFI_FLOAT, 3 );
	MAKE_TRIPLE( Pos4Tex2Norm, 	"Position", INFI_FLOAT, 4,
								"Texture", INFI_FLOAT, 2,
								"Normal", INFI_FLOAT, 3 );
	
	MAKE_TRIPLE( Pos2Tex3Norm, 	"Position", INFI_FLOAT, 2,
								"Texture", INFI_FLOAT, 3,
								"Normal", INFI_FLOAT, 3 );
	MAKE_TRIPLE( Pos3Tex3Norm, 	"Position", INFI_FLOAT, 3,
								"Texture", INFI_FLOAT, 3,
								"Normal", INFI_FLOAT, 3 );
	MAKE_TRIPLE( Pos4Tex3Norm, 	"Position", INFI_FLOAT, 4,
								"Texture", INFI_FLOAT, 3,
								"Normal", INFI_FLOAT, 3 );
	
	MAKE_TRIPLE( Pos2Tex4Norm, 	"Position", INFI_FLOAT, 2, 
								"Texture", INFI_FLOAT, 4,
								"Normal", INFI_FLOAT, 3 );
	MAKE_TRIPLE( Pos3Tex4Norm, 	"Position", INFI_FLOAT, 3,
								"Texture", INFI_FLOAT, 4,
								"Normal", INFI_FLOAT, 3 );
	MAKE_TRIPLE( Pos4Tex4Norm, 	"Position", INFI_FLOAT, 4,
								"Texture", INFI_FLOAT, 4,
								"Normal", INFI_FLOAT, 3 );
}

#define GET_BLEND( name ) \
		static infi_blend_t* __ ## name = NULL; \
		infi_blend_t const* name() { \
			return __ ## name; \
		}

GET_BLEND( BlendMix )
GET_BLEND( BlendMixAlphaOnly )
GET_BLEND( BlendMixWeighted )
GET_BLEND( BlendExact )
GET_BLEND( BlendAdd )
GET_BLEND( BlendText )

static void InfiLInitBlendModes() {
	__BlendMix = InfiCreateBlend();
		__BlendMix->usage |= INFI_BLEND_FUNCTION;
		__BlendMix->srcalpha = GL_SRC_ALPHA;
		__BlendMix->dstalpha = GL_ONE_MINUS_SRC_ALPHA;
		
	__BlendMixAlphaOnly = InfiCreateBlend();
		__BlendMixAlphaOnly->usage |= INFI_BLEND_FUNCTION_SEP;
		__BlendMixAlphaOnly->srcalpha = GL_SRC_ALPHA;
		__BlendMixAlphaOnly->dstalpha = GL_ONE_MINUS_SRC_ALPHA;
		__BlendMixAlphaOnly->srccolor = GL_ONE;
		__BlendMixAlphaOnly->dstcolor = GL_ONE;
		
	__BlendMixWeighted = InfiCreateBlend();
		__BlendMixWeighted->usage |= INFI_BLEND_FUNCTION;
		__BlendMixWeighted->srcalpha = GL_ONE;
		__BlendMixWeighted->dstalpha = GL_ONE_MINUS_SRC_ALPHA;
		
	__BlendExact = InfiCreateBlend();
		__BlendExact->usage |= INFI_BLEND_FUNCTION;
		__BlendExact->srcalpha = GL_ONE;
		__BlendExact->dstalpha = GL_ZERO;
		
	__BlendAdd = InfiCreateBlend();
		__BlendAdd->usage |= INFI_BLEND_FUNCTION;
		__BlendAdd->srcalpha = GL_SRC_ALPHA;
		__BlendAdd->dstalpha = GL_DST_ALPHA;
		
	__BlendText = InfiCreateBlend();
		__BlendText->usage |= INFI_BLEND_FUNCTION;
		__BlendText->srcalpha = GL_ONE_MINUS_DST_ALPHA;
		__BlendText->dstalpha = GL_DST_ALPHA;
}

} }

#endif//__INFI_STANDARD_OBJECTS_H__