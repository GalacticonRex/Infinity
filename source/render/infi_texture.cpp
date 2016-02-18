#include "main/infi_error.h"
#include "core/infi_methods.h"
#include "core/infi_stack.h"
#include "render/infi_texture.h"
#include "render/infi_gl_wrapper.h"
#include "render/infi_gl_control.h"
#include "render/infi_render.h"
#include <set>

namespace INFI {
namespace render {

namespace {
	using namespace std;
	using namespace core;
}

static GLuint texclearfbo;
void InfiLInitTextureClear() {
	InfiGLGenFramebuffers( 1, &texclearfbo );
}
void InfiLQuitTextureClear() {
	InfiGLDeleteFramebuffers( 1, &texclearfbo );
}

struct infi_texture_entry_t {
	infi_texture_t* tex;
	uint32 active;
};
static core::stack_t<infi_texture_entry_t> textures;
static std::set<infi_texture_t*> cache;

void InfiLEmptyTextureCache() {
	auto iter = cache.begin();
	for ( ;iter!=cache.end();++iter ) {
		cerr << "--- Begin Texture Cache ---" << endl;
		InfiDestroyTexture( *iter );
		cerr << "--- Finish Texture Cache ---" << endl;
	}
	cache.clear();
}

// +-------------------------------------------------------------------------------------------------------------------------------------------
// | PROTOTYPE DECLARATIONS
uint32 infi_texture_base_t::pxalign = 4;

static GLenum __formats[] = { GL_NONE, GL_RED, GL_RG, GL_RGB, GL_RGBA };
static GLenum __channels[] = { GL_RED, GL_GREEN, GL_BLUE, GL_ALPHA };

#define infi_procNullErr( ptr, func ) \
	if ( ptr == NULL ) \
		InfiSendError( INFI_NULL_DEREF_ERROR, "invalid texture" );

// evaluate a swizzle value
static GLint get_val( uint32 enumerator );
static void get_raw_vals( uint32 enumerator, GLint& r, GLint& g, GLint& b, GLint& a );
static void get_vals( uint32 enumerator, GLint& r, GLint& g, GLint& b, GLint& a );

// returns the base format needed to store these channels
static GLenum get_base_format( uint32 channels, uint32 &chan, uint32 &maxchan );

// returns the sized format of this combination of type and channels
static GLenum get_internal_format( infi_t storage, infi_t output, uint32 count, uint32& bytes );

static uint32 build_data( bool swiz, bool fpot, uint32 chan, uint32 chanmax, uint32 bytes );

// returns the format for this depth index
static void get_depth_format( INFI_depth_stencil_type type, 
							  GLenum& internal, 
							  GLenum& format, 
							  GLenum& datatype, 
							  uint32& bytes );

// returns a row length based on these values aligned to ::pxalign
static uint32 align_row( uint32 pixel_count, uint32 bytes_per_pixel );

// converts data from one base to another
// size is measured in (pixel, line)
// maps inflow to outflow
//
// e.g. in method : INFI_RG
//		in shader : INFI_1G1R
//		if ( 
//		1 G 1 R [0 1 2 3]
//		R G B 	[0 1 2]
//
//		3 -> 0 (ALPHA TO RED)
//		1 -> 1 (GREEN TO GREEN)
//      . -> 2 (EMPTY TO BLUE)

// create the converter between formats
static uint32 map_channels( INFI_channels in, INFI_channels out, int32* conv );

// inflow = format of incoming data
// outflow = channels in memory
/*static void convert_data( const vec2ui& size,	// pixel size of texture
						  INFI_channels inflow, // pixel format of incoming data
						  uint32 inpixel, 		// size of a single channel in a single pixel
						  bool inpadded,		// is data padded?
						  void* indata, 		// incoming data
						  INFI_channels outflow,// pixel format of outgoing data
						  uint32 outpixel,		// size of a single channel in a single pixel
						  bool outpadded,		// should data be padded?
						  void* outdata );		// outgoing data*/

// allocate data
static void convert_data( const vec2ui& size,
						  INFI_channels inflow, 
						  uint32 inpixel,
						  bool inpadded,
						  const void* indata,
						  INFI_channels outflow, 
						  uint32 outpixel,
						  bool outpadded, 
						  const void** outdata );

// convert data in-place
static void convert_data( const vec2ui& size,
						  INFI_channels inflow, 
						  uint32 inpixel,
						  bool inpadded,
						  INFI_channels outflow, 
						  uint32 outpixel,
						  bool outpadded, 
						  const void** inoutdata );

// +-------------------------------------------------------------------------------------------------------------------------------------------
// | Texture methods
uint32 infi_texture_t::buffersize( uint32 mip ) const {
	vec2ui tmp = realdim;
	for ( uint32 j=0;j<mip && tmp.x != 1 && tmp.y != 1 ;j++) {
		if ( tmp.x != 1 ) tmp.x /= 2;
		if ( tmp.y != 1 ) tmp.y /= 2;
	}
	uint32 rowAlign = align_row( tmp.x, bytesize() * maxchan() );
	return rowAlign * tmp.y;
}

static const uint32
	INFI_TEXTURE_FLOAT_MASK 	= 0x00000200,
	INFI_TEXTURE_INTEGER_MASK 	= 0x00000100,
	INFI_TEXTURE_SWIZZLE_MASK 	= 0x00000080,
	INFI_TEXTURE_FORCE_POT_MASK = 0x00000040,
	INFI_TEXTURE_CHANNEL_MASK 	= 0x00000030,
	INFI_TEXTURE_MAX_CHAN_MASK 	= 0x0000000C,
	INFI_TEXTURE_BYTE_SIZE_MASK = 0x00000003;
	
static const uint32
	INFI_TEXTURE_FLOAT_SHIFT 	 = 9,
	INFI_TEXTURE_INTEGER_SHIFT 	 = 8,
	INFI_TEXTURE_SWIZZLE_SHIFT 	 = 7,
	INFI_TEXTURE_FORCE_POT_SHIFT = 6,
	INFI_TEXTURE_CHANNEL_SHIFT 	 = 4,
	INFI_TEXTURE_MAX_CHAN_SHIFT  = 2,
	INFI_TEXTURE_BYTE_SIZE_SHIFT = 0;

bool infi_texture_t::needs_swizzle() const {
	return ( data & INFI_TEXTURE_SWIZZLE_MASK ) >> INFI_TEXTURE_SWIZZLE_SHIFT;
}
bool infi_texture_t::force_pot() const {
	return ( data & INFI_TEXTURE_FORCE_POT_MASK ) >> INFI_TEXTURE_FORCE_POT_SHIFT;
}
uint32 infi_texture_t::channels() const {
	return ( ( data & INFI_TEXTURE_CHANNEL_MASK ) >> INFI_TEXTURE_CHANNEL_SHIFT ) + 1;
}
uint32 infi_texture_t::maxchan() const {
	return ( ( data & INFI_TEXTURE_MAX_CHAN_MASK ) >> INFI_TEXTURE_MAX_CHAN_SHIFT ) + 1;
}
uint32 infi_texture_t::bytesize() const {
	return ( ( data & INFI_TEXTURE_BYTE_SIZE_MASK ) >> INFI_TEXTURE_BYTE_SIZE_SHIFT ) + 1;
}

void infi_texture_t::swizzle( GLint& r, GLint& g, GLint& b, GLint& a ) const {
	InfiPushFunction( "infi_texture_t.swizzle" );
	get_vals( compressed, r, g, b, a );
	InfiPopFunction();
}
void infi_texture_t::red( GLint& r ) const {
	InfiPushFunction( "infi_texture_t.swizzle" );
	r = get_val( compressed & 0xFF );
	InfiPopFunction();
}
void infi_texture_t::green( GLint& g ) const {
	InfiPushFunction( "infi_texture_t.green" );
	g = get_val( (compressed>>8) & 0xFF );
	InfiPopFunction();
}
void infi_texture_t::blue( GLint& b ) const {
	InfiPushFunction( "infi_texture_t.blue" );
	b = get_val( (compressed>>16) & 0xFF );
	InfiPopFunction();
}
void infi_texture_t::alpha( GLint& a ) const {
	InfiPushFunction( "infi_texture_t.alpha" );
	a = get_val( (compressed>>24) & 0xFF );
	InfiPopFunction();
}
infi_texture_t::~infi_texture_t() {
	InfiGLDeleteTextures( 1, &handle );
	cache.erase( this );
}

uint32 InfiGetChannelCount( INFI_channels chan ) {
	uint32 mask = 0xFF;
	uint32 count = 0;
	for ( uint32 i=0;i<4;i++ ) {
		if ( chan & mask )
			count ++ ;
		mask <<= 8;
	} return count;
}
uint32 InfiGetChannelHighest( INFI_channels chan ) {
	uint32 mask = 0xFF000000;
	for ( uint32 i=0;i<4;i++ ) { 
		if ( chan & mask )
			return 4-i;
		mask >>= 8;
	}
	return 0;
}
INFI_channels InfiOrderChannel( INFI_channels input ) {
	INFI_channels output = 0;
	
	GLint decompressed[4];
	get_raw_vals( input, decompressed[0], 
						 decompressed[1], 
						 decompressed[2], 
						 decompressed[3] );
	for ( uint32 i=0;i<4;i++ ) {
		switch ( decompressed[i] ) {
			case INFI_RED0:
				output |= INFI_RED0;
				break;
			case INFI_GREEN0:
				output |= INFI_GREEN1;
				break;
			case INFI_BLUE0:
				output |= INFI_BLUE2;
				break;
			case INFI_ALPHA0:
				output |= INFI_ALPHA3;
				break;
			default:
				continue;
		}
	}
	return output;
}
INFI_channels InfiGetBaseChannel( uint32 chan ) {
	switch ( chan ) {
		case 1:
			return INFI_RED0;
			break;
		case 2:
			return INFI_RED0 | INFI_GREEN1;
			break;
		case 3:
			return INFI_RED0 | INFI_GREEN1 | INFI_BLUE2;
			break;
		case 4:
			return INFI_RED0 | INFI_GREEN1 | INFI_BLUE2 | INFI_ALPHA3;
			break;
		default:
			return 0;
	}
}

infi_texture_t* InfiCreateTexture(const vec2ui& dim,
									infi_t storage,
									infi_t output,
									INFI_channels chan,
									bool use_mipmaps,
									bool force_pow2) {
	InfiPushFunction( "InfiCreateTexture" );
	infi_texture_t* ntex = new infi_texture_t;
	
	InfiGLGenTextures( 1, &(ntex->handle) );
	InfiGLPushTexture( ntex->handle );
	
	ntex->mipmap = 1;
	if ( use_mipmaps ) {
		vec2ui tmp = dim;
		while ( tmp.x != 1 && tmp.y != 1 ) {
			if ( tmp.x != 1 ) tmp.x /= 2;
			if ( tmp.y != 1 ) tmp.y /= 2;
			ntex->mipmap ++ ;
		}
	}
	
	bool fpot = force_pow2 || !GL.texture.npot();
	
	ntex->dimensions = dim;
	if ( fpot )
		ntex->realdim = vec2ui( MakePow2( dim.x ), MakePow2( dim.y ) );
	else
		ntex->realdim = dim;
	
	bool need_swiz = !GL.texture.swizzle();
	uint32 grab_chan = 0, 
		 grab_max = 0,
		 grab_size = 0;
	
	ntex->pxformat = get_base_format( /* input */ chan, /* output */ grab_chan, grab_max );
	ntex->internal = get_internal_format( /* input */ storage, output, grab_max, /* output  */ grab_size );
	ntex->data = build_data( need_swiz, fpot, grab_chan, grab_max, grab_size );
	ntex->datatype = storage;
	ntex->occupancy = grab_size * grab_max * dim.x;
	ntex->rowlen = align_row( dim.x, grab_size * grab_max );
	ntex->compressed = chan;
	
	if ( GL.texture.storage() ) {
		InfiGLTexParameteri( GL_TEXTURE_BASE_LEVEL, 0);
		InfiGLTexParameteri( GL_TEXTURE_MAX_LEVEL, ntex->mipmap - 1);
		InfiGLTexStorage( ntex->mipmap, ntex->internal, ntex->realdim.x, ntex->realdim.y );
	} else {
		InfiGLTexImage( 0, ntex->internal, ntex->realdim.x, ntex->realdim.y, ntex->pxformat, ntex->datatype, 0 );
	}
	
	if ( GL.texture.swizzle() ) {
		GLint swiz[4];
		get_vals( chan, swiz[0], swiz[1], swiz[2], swiz[3] );
		for ( uint32 i=0;i<4;i++ )
			if ( swiz[i] == -1 )
				swiz[i] = __channels[i];
		InfiGLTexParameteri( GL_TEXTURE_SWIZZLE_RGBA, swiz );
	}
	
	if ( ntex->mipmap != 1 )
		InfiGLGenerateMipmap();
	
	InfiGLPopTexture();
	
	cache.insert( ntex );
	
	InfiPopFunction();
	return ntex;
}

infi_texture_t* InfiCreateTexture( const vec2ui& dim,
									 INFI_depth_stencil_type type,
									 bool force_pow2 ) {
	InfiPushFunction( "InfiCreateTexture" );
	infi_texture_t* ntex = new infi_texture_t;
	
	InfiGLGenTextures( 1, &(ntex->handle) );
	InfiGLPushTexture( ntex->handle );
	
	bool fpot = force_pow2 || !GL.texture.npot();
	
	ntex->mipmap = 1;
	ntex->dimensions = dim;
	if ( fpot )
		ntex->realdim = vec2ui( MakePow2( dim.x ), MakePow2( dim.y ) );
	else
		ntex->realdim = dim;
	
	uint32 grab_bytes = 0;
	get_depth_format( type, ntex->internal, ntex->pxformat, ntex->datatype, grab_bytes );
	
	ntex->compressed = INFI_RED0;
	ntex->data = build_data( false, fpot, 1, 1, grab_bytes );
	ntex->occupancy = grab_bytes * dim.x;
	ntex->rowlen = align_row( dim.x, grab_bytes * 1 );
	
	if ( GL.texture.storage() )
		InfiGLTexStorage( 1, ntex->internal, ntex->realdim.x, ntex->realdim.y );
	else
		InfiGLTexImage( 0, ntex->internal, ntex->realdim.x, ntex->realdim.y, ntex->pxformat, ntex->datatype, 0 );
	
	if ( ntex->mipmap != 1 )
		InfiGLGenerateMipmap();
	
	InfiGLPopTexture();
	
	cache.insert( ntex );
	
	InfiPopFunction();
	return ntex;
}

void InfiDestroyTexture( infi_texture_t* tex ) {
	delete tex;
}

infi_texture_t* InfiCopyTexture( const infi_texture_t* src ) {
	InfiPushFunction( "InfiCopyTexture" );
	infi_texture_t* ntex = new infi_texture_t;
	
	ntex->occupancy = src->occupancy;
	ntex->rowlen = src->rowlen;
	ntex->dimensions = src->dimensions;
	ntex->realdim = src->realdim;
	ntex->mipmap = src->mipmap;
	ntex->data = src->data;
	ntex->compressed = src->compressed;
	ntex->pxformat = src->pxformat;
	ntex->internal = src->internal;
	ntex->datatype = src->datatype;
	
	InfiGLGenTextures( 1, &(ntex->handle) );
	InfiGLPushTexture( ntex->handle );
	
	if ( GL.texture.storage() ) {
		InfiGLTexParameteri( GL_TEXTURE_BASE_LEVEL, 0);
		InfiGLTexParameteri( GL_TEXTURE_MAX_LEVEL, ntex->mipmap - 1);
		InfiGLTexStorage( ntex->mipmap, 
						   ntex->internal, 
						   ntex->width(), 
						   ntex->height() );
	} else {
		InfiGLTexImage( 0, ntex->internal, 
						 	ntex->width(), 
						 	ntex->height(), 
						 	ntex->pxformat, 
						 	ntex->datatype, 0 );
	}
	
	if ( ntex->mipmap != 1 )
		InfiGLGenerateMipmap();
	
	if ( GL.texture.swizzle() ) {
		GLint swiz[4];
		get_vals( ntex->compressed, swiz[0], swiz[1], swiz[2], swiz[3] );
		for ( uint32 i=0;i<4;i++ )
			if ( swiz[i] == -1 )
				swiz[i] = __channels[i];
		InfiGLTexParameteri( GL_TEXTURE_SWIZZLE_RGBA, swiz );
	}
	
	InfiGLPopTexture();
	InfiPopFunction();
	return ntex;
}

infi_texture_t* InfiCurrentTexture( uint32 tex ) {
	return ( textures.empty() ) ? NULL : textures[0].tex;
}
void InfiPushTexture( infi_texture_t* tex, uint32 act ) {
	InfiPushFunction( "InfiPushTexture" );
	textures.push( {tex,act} );
	InfiGLPushTexture( tex->handle, act );
	InfiPopFunction();
}
void InfiPopTexture() {
	InfiPushFunction( "InfiPopTexture" );
	textures.pop();
	InfiGLPopTexture();
	InfiPopFunction(); 
}


void InfiSetData( infi_texture_t* tex, const void* data ) {
	InfiPushFunction( "InfiSetData" );
	/*char* working = NULL;
	
	if ( tex->needs_swizzle() ) {
		convert_data( tex->realdim, InfiGetBaseChannel( tex->channels() ), tex->bytesize(), false, data, 
					  tex->compressed, tex->bytesize(), false, (const void**) &working );
	} else {
		cerr << "WORKS!" << endl;
		convert_data( tex->realdim, InfiGetBaseChannel( tex->channels() ), tex->bytesize(), false, data,
					  InfiGetBaseChannel( tex->maxchan() ), tex->bytesize(), false, (const void**) &working );
	}*/
	
	InfiGLPushTexture( tex->handle );
	InfiGLTexSubImage( 0, 0,0, tex->width(), tex->height(), 
						tex->pxformat, tex->datatype, data /*working*/ );
	InfiGLGenerateMipmap();
	InfiGLPopTexture();
	InfiPopFunction();
}
void InfiSetData( infi_texture_t* tex, const indexable_t<uint8>& block ) {
	InfiSetData( tex, block.source() );
}
void InfiSetData( infi_texture_t* tex, const rectui& r, const void* data ) {
	InfiPushFunction( "InfiSetData" );
	char* working = NULL;
	
	if ( tex->needs_swizzle() ) {
		convert_data( r.dim, InfiGetBaseChannel( tex->channels() ), tex->bytesize(), false, data, 
					  tex->compressed, tex->bytesize(), true, (const void**) &working );
	} else {
		convert_data( r.dim, InfiGetBaseChannel( tex->channels() ), tex->bytesize(), false, data,
					  InfiGetBaseChannel( tex->maxchan() ), tex->bytesize(), true, (const void**) &working );
	}
	
	InfiGLPushTexture( tex->handle );
	InfiGLTexSubImage( 0, r.x, r.y, r.w, r.h, 
						tex->pxformat, tex->datatype, working );
	InfiGLGenerateMipmap();
	InfiGLPopTexture();
	InfiPopFunction();
}
void InfiSetData( infi_texture_t* tex, const rectui& r, const indexable_t<uint8>& block ) {
	InfiSetData( tex, r, block.source() );
}

void InfiGetData( infi_texture_t* tex, data_t<uint8>& output, uint32 lvl ) {
	InfiPushFunction( "InfiGetData" );
	infi_procNullErr( tex, InfiGetData(...) );
	if ( lvl >= tex->mipmap )
		InfiSendError( INFI_INDEX_ERROR,
					   "mipmap level %d / %d exceeded for texture", lvl, tex->mipmap );
	
	uint32 sz = tex->buffersize( lvl );
	char* initial = new char[sz];
	InfiGLPushTexture( tex->handle );
	InfiGLGetTexImage( lvl, tex->pxformat, tex->datatype, initial );
	InfiGLPopTexture();
	if ( tex->needs_swizzle() )
		convert_data( tex->dimensions, tex->compressed, tex->bytesize(), true,
									   InfiGetBaseChannel( tex->channels() ), tex->bytesize(), false, (const void**) &initial );
	else
		convert_data( tex->dimensions, InfiGetBaseChannel( tex->maxchan() ), tex->bytesize(), true,
									   InfiGetBaseChannel( tex->channels() ), tex->bytesize(), false, (const void**) &initial );
	delete[] output.data;
	output.data = (uint8*)initial;
	output.alloc = sz;
	InfiPopFunction();
}
//void InfiGetData, ( infi_texture_t*, data_t<uint8>&, const rectui&, uint32 = 0 ) );

void InfiSyncTexture( infi_texture_t* tex ) {
	InfiPushFunction( "InfiSyncTexture" );
	infi_procNullErr( tex, InfiSyncTexture(...) );
	if ( tex->mipmap != 1 ) {
		InfiGLPushTexture( tex->handle );
		InfiGLGenerateMipmap();
		InfiGLPopTexture();
	}
	InfiPopFunction();
}

void InfiSetTextureAttrib( infi_texture_t* tex, GLuint param, int32 value ) {
	InfiPushFunction( "InfiSetTextureAttrib" );
	infi_procNullErr( tex, InfiSetTextureAttrib(...) );
	InfiGLPushTexture( tex->handle );
	InfiGLTexParameteri( param, value );
	InfiGLPopTexture();
	InfiPopFunction();
}
void InfiSetTextureAttrib( infi_texture_t* tex, GLuint param, float32 value ) {
	InfiPushFunction( "InfiSetTextureAttrib" );
	infi_procNullErr( tex, InfiSetTextureAttrib(...) );
	InfiGLPushTexture( tex->handle );
	InfiGLTexParameterf( param, value );
	InfiGLPopTexture();
	InfiPopFunction();
}
void InfiSetTextureAttrib( infi_texture_t* tex, GLuint param, int32* value ) {
	InfiPushFunction( "InfiSetTextureAttrib" );
	infi_procNullErr( tex, InfiSetTextureAttrib(...) );
	InfiGLPushTexture( tex->handle );
	InfiGLTexParameteri( param, value );
	InfiGLPopTexture();
	InfiPopFunction();
}
void InfiSetTextureAttrib( infi_texture_t* tex, GLuint param, float32* value ) {
	InfiPushFunction( "InfiSetTextureAttrib" );
	infi_procNullErr( tex, InfiSetTextureAttrib(...) );
	InfiGLPushTexture( tex->handle );
	InfiGLTexParameterf( param, value );
	InfiGLPopTexture();
	InfiPopFunction();
}

void InfiNearestTexel( infi_texture_t* tex ) {
	InfiPushFunction( "InfiNearestTexel" );
	infi_procNullErr( tex, InfiSetTextureAttrib(...) );
	InfiGLPushTexture( tex->handle );
	InfiGLTexParameteri( GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	InfiGLTexParameteri( GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	InfiGLPopTexture();
	InfiPopFunction();
}
void InfiBilinearTexel( infi_texture_t* tex ) {
	InfiPushFunction( "InfiBilinearTexel" );
	infi_procNullErr( tex, InfiSetTextureAttrib(...) );
	InfiGLPushTexture( tex->handle );
	InfiGLTexParameteri( GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	InfiGLTexParameteri( GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	InfiGLPopTexture();
	InfiPopFunction();
}

void InfiRepeatTexture( infi_texture_t* tex ) {
	InfiPushFunction( "InfiRepeatTexture" );
	infi_procNullErr( tex, InfiSetTextureAttrib(...) );
	InfiGLPushTexture( tex->handle );
	InfiGLTexParameteri( GL_TEXTURE_WRAP_S, GL_REPEAT );
	InfiGLTexParameteri( GL_TEXTURE_WRAP_T, GL_REPEAT );
	InfiGLPopTexture();
	InfiPopFunction();
}
void InfiClampTexture( infi_texture_t* tex ) {
	InfiPushFunction( "InfiClampTexture" );
	infi_procNullErr( tex, InfiSetTextureAttrib(...) );
	InfiGLPushTexture( tex->handle );
	InfiGLTexParameteri( GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
	InfiGLTexParameteri( GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
	InfiGLPopTexture();
	InfiPopFunction();
}

void InfiSetTextureSwizzle( infi_texture_t* tex, INFI_channels chan ) {
	InfiPushFunction( "InfiSetTextureSwizzle" );
	infi_procNullErr( tex, InfiSetTextureSwizzle(...) );
	InfiGLPushTexture( tex->handle );
	if ( tex->needs_swizzle() ) {
		GLubyte* data = new GLubyte[tex->buffersize(1)];
		InfiGLGetTexImage( 0, tex->pxformat, tex->datatype, data );
		convert_data( tex->realdim,
					  tex->compressed, tex->bytesize(), true,
					  chan, tex->bytesize(), false,
					  (const void**) &data );
		InfiGLTexSubImage( 0, 0,0, tex->width(), tex->height(), 
							tex->pxformat, tex->datatype, data );
		delete[] data;
	} else {
		GLint swiz[4];
		get_vals( chan, swiz[0], swiz[1], swiz[2], swiz[3] );
		for ( uint32 i=0;i<4;i++ )
   			if ( swiz[i] == -1 )
   				swiz[i] = __channels[i];
		InfiGLTexParameteri( GL_TEXTURE_SWIZZLE_RGBA, swiz );
		tex->compressed = chan;
	}
	InfiGLPopTexture();
	InfiPopFunction();
}

void InfiClearTexture( infi_texture_t* tex ) {	
	if ( GL.framebuffer.obj() ) {
		InfiGLPushFramebuffer( texclearfbo );
		InfiGLFramebufferTexture( GL_COLOR_ATTACHMENT0, tex->handle, 0 );
		InfiGLClearColor( 0,0,0,0 );
		InfiGLClear( GL_COLOR_BUFFER_BIT );
		InfiGLPopFramebuffer();
	} else {
		uint32 len = tex->rowlen * tex->height();
		data_t<uint8> empty( len );
		for ( uint32 i=0;i<len;++i )
			empty[i] = 0;
		InfiGLTexSubImage( 0, 0, 0, 
							tex->width(), tex->height(), 
							tex->pxformat, 
							tex->datatype, 
							empty.source() );
	}
	if ( tex->mipmap != 1 )
		InfiGLGenerateMipmap();
}

void InfiClearTexture( infi_texture_t* tex, const vec4& col ) {	
	if ( GL.framebuffer.obj() ) {
		InfiGLPushFramebuffer( texclearfbo );
		InfiGLFramebufferTexture( GL_COLOR_ATTACHMENT0, tex->handle, 0 );
		InfiGLClearColor( col.r, col.g, col.b, col.a );
		InfiGLClear( GL_COLOR_BUFFER_BIT );
		InfiGLPopFramebuffer();
	} else {
		uint32 len = tex->rowlen * tex->height();
		data_t<uint8> empty( len );
		for ( uint32 i=0;i<len;++i )
			empty[i] = 0;
		InfiGLTexSubImage( 0, 0, 0, 
							tex->width(), tex->height(), 
							tex->pxformat, 
							tex->datatype, 
							empty.source() );
	}
	if ( tex->mipmap != 1 )
		InfiGLGenerateMipmap();
}

// +-------------------------------------------------------------------------------------------------------------------------------------------
// | Static methods
static GLint get_val( uint32 enumerator ) {
	switch( enumerator ) {
		case 0x00: return -1; break;
		case 0x01: return GL_RED; break;
		case 0x02: return GL_GREEN; break;
		case 0x04: return GL_BLUE; break;
		case 0x08: return GL_ALPHA; break;
		case 0x10: return GL_ZERO; break;
		case 0x20: return GL_ONE; break;
		case 0x40:
		case 0x80:
			InfiSendError( INFI_TYPE_ERROR, "unknown channel definition" );
			break;
		default:
			InfiSendError( INFI_TYPE_ERROR, "multiple incoming channels overlap" );
	} return -1;
}
static void get_raw_vals( uint32 enumerator, GLint& r, GLint& g, GLint& b, GLint& a ) {
	r = (enumerator    ) & 0xFF;
	g = (enumerator>>=8) & 0xFF;
	b = (enumerator>>=8) & 0xFF;
	a = (enumerator>>=8) & 0xFF;
}
static void get_vals( uint32 enumerator, GLint& r, GLint& g, GLint& b, GLint& a ) {
	r = get_val( (enumerator    ) & 0xFF );
	g = get_val( (enumerator>>=8) & 0xFF );
	b = get_val( (enumerator>>=8) & 0xFF );
	a = get_val( (enumerator>>=8) & 0xFF );
}

static GLenum get_base_format( uint32 channels, uint32 &chan, uint32 &maxchan ) {
	// return possibilities:
	// GL_RED, GL_RG, GL_RGB, GL_RGBA
	for ( uint32 i=0;i<4;i++ ) {
		GLint tmp;
		if ( (tmp=get_val( channels & 0xFF )) != -1 ) {
			if ( tmp != GL_ONE && tmp != GL_ZERO ) {
				if ( !GL.texture.swizzle() )
					maxchan = i + 1;
				else
					maxchan ++ ;
				chan ++ ;
			}
		} channels >>= 8;
	}
	if ( chan == 0 )
		InfiSendError( INFI_GL_ERROR, "cannot allocate zero channel texture" );
	else if ( maxchan < 2 && !GL.texture.rg() )
		maxchan = 3;
	return __formats[maxchan];
	
}

static GLenum get_internal_format( infi_t storage, infi_t output, uint32 count, uint32& bytes ) {
	uint32 bitsz = 0;
	
	switch ( storage ) {
		case INFI_BYTE:
		case INFI_UBYTE:
			bitsz = 8;
			bytes = 1;
			break;
		case INFI_SHORT:
		case INFI_USHORT:
			bitsz = 16;
			bytes = 2;
			break;
		case INFI_INT:
		case INFI_UINT:
			bitsz = 32;
			bytes = 4;
			break;
		case INFI_DOUBLE:
		case INFI_FLOAT:
			bitsz = 32;
			bytes = 4;
			bitsz |= 0x40000000;
			break;
		default:
			InfiSendError( INFI_GL_ERROR, 
						   "TextureFormatter.GetAllocator", 
						   "texture storage of type %d is not supported", 
						   (int32)storage );
	}
	
	switch ( output ) {
		case INFI_BYTE:
		case INFI_SHORT:
		case INFI_INT:
			bitsz |= 0x20000000;
			break;
		case INFI_UBYTE:
		case INFI_USHORT:
		case INFI_UINT:
			bitsz |= 0x80000000;
			break;
		case INFI_FLOAT:
		case INFI_DOUBLE:
			break;
		default:
			InfiSendError( INFI_GL_ERROR,
						   "TextureFormatter.GetAllocator", 
						   "texture storage of type %d is not supported", 
						   (int32)output );
	}
	
	switch ( count ) {
		case 1:
			switch ( bitsz ) {
				case 8:				return GL_R8; break;
				case 16:			return GL_R16; break;
				
				case 0x20000008:	return GL_R8I; break;
				case 0x20000010:	return GL_R16I; break;
				case 0x20000020:	return GL_R32I; break;
				
				case 0x40000010: 	return GL_R16F; break; // 16F
				case 0x40000020: 	return GL_R32F; break; // 32F
				
				case 0x80000008: 	return GL_R8UI; break; // 8UI
				case 0x80000010: 	return GL_R16UI; break; // 16UI
				case 0x80000020: 	return GL_R32UI; break; // 32UI
				default:
					InfiSendError( INFI_WARNING,
								   "TextureFormatter.GetAllocator", 
								   "cannot generate texture of size %d and channels %d", 
								   bitsz & 0x0FFFFFFF,
								   count );
					return 0;
			} break;
		case 2:
			switch ( bitsz ) {
				case 8:				return GL_RG8; break;
				case 16:			return GL_RG16; break;
				
				case 0x20000008:	return GL_RG8I; break;
				case 0x20000010:	return GL_RG16I; break;
				case 0x20000020:	return GL_RG32I; break;
				
				case 0x40000010: 	return GL_RG16F; break; // 16F
				case 0x40000020: 	return GL_RG32F; break; // 32F
				
				case 0x80000008: 	return GL_RG8UI; break; // 8UI
				case 0x80000010: 	return GL_RG16UI; break; // 16UI
				case 0x80000020: 	return GL_RG32UI; break; // 32UI
				default:
					InfiSendError( INFI_WARNING,
								   "TextureFormatter.GetAllocator", 
								   "cannot generate texture of size %d and channels %d", 
								   bitsz & 0x0FFFFFFF,
								   count );
					return 0;
			} break;
		case 3:
			switch ( bitsz ) {
				case 4:				return GL_RGB4; break;
				case 5:				return GL_RGB5; break;
				case 8:				return GL_RGB8; break;
				case 10:			return GL_RGB10; break;
				case 12:			return GL_RGB12; break;
				case 16:			return GL_RGB16; break;
				
				case 0x20000008:	return GL_RGB8I; break;
				case 0x20000010:	return GL_RGB16I; break;
				case 0x20000020:	return GL_RGB32I; break;
				
				case 0x40000010: 	return GL_RGB16F; break; // 16F
				case 0x40000020: 	return GL_RGB32F; break; // 32F
				
				case 0x80000008: 	return GL_RGB8UI; break; // 8UI
				case 0x80000010: 	return GL_RGB16UI; break; // 16UI
				case 0x80000020: 	return GL_RGB32UI; break; // 32UI
				default:
					InfiSendError( INFI_WARNING,
								   "TextureFormatter.GetAllocator", 
								   "cannot generate texture of size %d and channels %d", 
								   bitsz & 0x0FFFFFFF,
								   count );
					return 0;
			} break;
		case 4:
			switch ( bitsz ) {
				case 2:				return GL_RGBA2; break;
				case 4:				return GL_RGBA4; break;
				case 5:				return GL_RGB5_A1; break;
				case 8:				return GL_RGBA8; break;
				case 10:			return GL_RGB10_A2; break;
				case 12:			return GL_RGBA12; break;
				case 16:			return GL_RGBA16; break;
				
				case 0x20000008:	return GL_RGBA8I; break;
				case 0x20000010:	return GL_RGBA16I; break;
				case 0x20000020:	return GL_RGBA32I; break;
				
				case 0x40000010: 	return GL_RGBA16F; break; // 16F
				case 0x40000020: 	return GL_RGBA32F; break; // 32F
				
				case 0x8000000A:	return GL_RGB10_A2UI; break;
				case 0x80000008: 	return GL_RGBA8UI; break; // 8UI
				case 0x80000010: 	return GL_RGBA16UI; break; // 16UI
				case 0x80000020: 	return GL_RGBA32UI; break; // 32UI
				default:
					InfiSendError( INFI_WARNING,
								   "TextureFormatter.GetAllocator", 
								   "cannot generate texture of size %d and channels %d", 
								   bitsz & 0x0FFFFFFF,
								   count );
					return 0;
			} break;
		default:
			InfiSendError( INFI_WARNING,
								   "TextureFormatter.GetAllocator", 
								   "cannot generate texture of size %d and channels %d", 
								   bitsz & 0x0FFFFFFF,
								   count );
			return 0;
	}
}

static uint32 build_data( bool swiz, bool fpot, uint32 chan, uint32 chanmax, uint32 bytes ) {
	return ( ( (uint32)swiz << INFI_TEXTURE_SWIZZLE_SHIFT ) & INFI_TEXTURE_SWIZZLE_MASK ) |
		   ( ( (uint32)fpot << INFI_TEXTURE_FORCE_POT_SHIFT ) & INFI_TEXTURE_FORCE_POT_MASK ) |
		   ( ( (uint32)(chan-1) << INFI_TEXTURE_CHANNEL_SHIFT ) & INFI_TEXTURE_CHANNEL_MASK ) |
		   ( ( (uint32)(chanmax-1) << INFI_TEXTURE_MAX_CHAN_SHIFT ) & INFI_TEXTURE_MAX_CHAN_MASK ) |
		   ( ( (uint32)(bytes-1) << INFI_TEXTURE_BYTE_SIZE_SHIFT ) & INFI_TEXTURE_BYTE_SIZE_MASK );
}

static void get_depth_format( INFI_depth_stencil_type type, GLenum& internal, GLenum& format, GLenum& datatype, uint32& bytes ) {
	internal = type;
	switch ( type ) {
		case INFI_DEPTH32:
		case INFI_DEPTH24:
		case INFI_DEPTH16:
			format = GL_DEPTH_COMPONENT;
			break;
		case INFI_DEPTH24_STENCIL:
		case INFI_DEPTH32_STENCIL:
			format = GL_DEPTH_STENCIL;
			break;
		case INFI_STENCIL:
			format = GL_STENCIL_INDEX;
			break;
	}
	switch ( type ) {
		case INFI_DEPTH32:
		case INFI_DEPTH32_STENCIL:
			datatype = GL_FLOAT;
			break;
		case INFI_DEPTH24:
		case INFI_DEPTH24_STENCIL:
			datatype = GL_INT;
			break;
		case INFI_DEPTH16:
			datatype = GL_SHORT;
			break;
		case INFI_STENCIL:
			datatype = GL_BYTE;
			break;
	}
	switch ( type ) {
		case INFI_DEPTH32_STENCIL:
			bytes = 5;
			break;
		case INFI_DEPTH32:
		case INFI_DEPTH24_STENCIL:
			bytes = 4;
			break;
		case INFI_DEPTH24:
			bytes = 3;
			break;
		case INFI_DEPTH16:
			bytes = 2;
			break;
		case INFI_STENCIL:
			bytes = 1;
			break;
	}
}

static uint32 align_row( uint32 pixel_count, uint32 bytes_per_pixel ) {
	uint32 alig = pixel_count * bytes_per_pixel, 
		 tmp = alig % infi_texture_t::pxalign;
	if ( tmp ) alig += infi_texture_t::pxalign - tmp;
	return alig;
}

// 111R -> 0RG1
//   /
// 0RG1
//   ?

// output values 
// -3 -- no channel definition, use default
// -2 -- use one
// -1 -- use zero
//  0 -- take first channel from input
//  1 -- take second channel from input
//  2 -- take third channel from input
//  3 -- take fourth channel from input

static uint32 map_channels( INFI_channels in, INFI_channels out, int32* conv ) {
	int32 inc[4];
	get_vals( in, inc[0], inc[1], inc[2], inc[3] );
	
	int32 outc[4];
	get_vals( in, outc[0], outc[1], outc[2], outc[3] );
	
	uint32 k = 0;
	for ( uint32 i=0;i<4;i++ )
		if ( inc[i] != -1 || outc[i] != -1 ) {
			k = i + 1;
		}
		
	for ( uint32 i=0;i<k;i++ ) {
		if ( outc[i] == -1 ) {
			conv[i] = -3;
		} else if ( outc[i] == GL_ONE ) {
			conv[i] = -2;
		} else if ( outc[i] == GL_ZERO ) {
			conv[i] = -1;
		} else {
			conv[i] = -3;
			for ( uint32 j=0;j<4;j++ )
				if ( inc[j] == outc[i] ) {
					conv[i] = j;
					break;
				}
		}
	}
	
	return k;
}

// NOTE: transfer of different byte counts does not work
static void transfer_channel( uint32 rows,		// number of rows
							  uint32 pixels,		// pixels per row
							  uint32 bytes,		// number of bytes per channel
							  uint32 inoffset,	// offset in the pixel
							  uint32 inpixel,		// size of pixel in channels
							  uint32 inrow,		// bytes to a row
							  const void* indata,		// incoming data
							  uint32 outoffset,	// offset in the pixel
							  uint32 outpixel,	// size of pixel in channels
							  uint32 outrow,		// bytes to a row
							  const void* outdata ) { // outgoing data
	
	char* cindata = (char*) indata;
	char* coutdata = (char*) outdata;
	
	uint32 in = 0;
	uint32 out = 0;
	uint32 inreal = pixels * inpixel * bytes;
	uint32 outreal = pixels * outpixel * bytes;
	for ( uint32 row=0;row<rows;row++ ) {
		for ( uint32 pixel=0;pixel<pixels;pixel++ ) {
			for ( uint32 byte=0;byte<bytes;byte++ )
				coutdata[out+outoffset] = cindata[in+inoffset];
			in += inpixel;
			out += outpixel;
		}
		in += inrow - inreal;
		out += outrow - outreal;
	}
}

template<typename type>
static void fill_channel_typed( uint32 rows,
								uint32 pixels,
								type input,
								uint32 outoffset,
								uint32 outpixel,
								uint32 outrow,
								const char* outdata ) {
	uint32 out = 0;
	for ( uint32 row=0;row<rows;row++ ) {
		for ( uint32 pixel=0;pixel<pixels;pixel++ ) {
			*(type*)(outdata+out+outoffset) = input;
			out += outpixel;
		}
		out += out % outrow;
	}
}

static void fill_channel( uint32 rows,
						  uint32 pixels,
						  uint32 bytes,
						  uint32 input,
						  uint32 outoffset,
						  uint32 outpixel,
						  uint32 outrow,
						  const void* outdata ) {
	switch ( bytes ) {
		case 1:
			fill_channel_typed<uint8>( rows, pixels, (uint8)input, outoffset, outpixel, outrow, (char*)outdata );
			break;
		case 2:
			fill_channel_typed<uint16>( rows, pixels, (uint8)input, outoffset, outpixel, outrow, (char*)outdata );
			break;
		case 4:
			fill_channel_typed<uint32>( rows, pixels, (uint8)input, outoffset, outpixel, outrow, (char*)outdata );
			break;
		default:
			InfiSendError( INFI_TYPE_ERROR, "type byte size for texture fill is invalid" );
	}
}
static bool check_need_convert( const vec2ui& size,
								INFI_channels inflow,
								uint32 inpixel,
								bool inpadded,
								INFI_channels outflow,
								uint32 outpixel,
								bool outpadded ) {
	
	uint32 outcount = InfiGetChannelCount( outflow );
	uint32 outputsize = outcount * outpixel;
	uint32 outputrow = (outpadded) ? align_row( outputsize, size.x ) : outputsize * size.x;
	
	uint32 incount = InfiGetChannelCount( inflow );
	uint32 inputsize = incount * inpixel;
	uint32 inputrow = (inpadded) ? align_row( inputsize, size.x ) : inputsize * size.x;
	
	return ( inflow != outflow ) || ( outputsize != inputsize ) || ( outputrow != inputrow );
}
static void convert_data_basic( const vec2ui& size,
								INFI_channels inflow,
								uint32 inpixel,
								bool inpadded,
								const void* indata,
								INFI_channels outflow,
								uint32 outpixel,
								bool outpadded,
								const void* outdata ) {
	// use this as the default color
	const vec4& color = InfiGetColor();
	
	int32 transfer[4];
	uint32 outcount = map_channels( inflow, outflow, transfer );
	uint32 outputsize = outcount * outpixel;
	uint32 outputrow = (outpadded) ? align_row( outputsize, size.x ) : outputsize * size.x;
	
	uint32 incount = InfiGetChannelCount( inflow );
	uint32 inputsize = incount * inpixel;
	uint32 inputrow = (inpadded) ? align_row( inputsize, size.x ) : inputsize * size.x;
	
	for ( uint32 i=0;i<outcount;i++ ) {
		switch( transfer[i] ) {
			// special cases
			case -3: // use default color
				fill_channel( size.y,
							  size.x,
							  outpixel, 
							  (float32)((uint32)(-1)>>((sizeof(uint32)-outpixel)*8)) * color.data[i], 
							  i * outpixel, 
							  outcount, 
							  outputrow,
							  outdata );
				break;
			case -2: // use one
				fill_channel( size.y,
							  size.x,
							  outpixel, 
							  (uint32)(-1), 
							  i * outpixel, 
							  outcount, 
							  outputrow,
							  outdata );
				break;
			case -1: // use zero
				fill_channel( size.y,
							  size.x,
							  outpixel, 
							  0, 
							  i * outpixel, 
							  outcount, 
							  outputrow, 
							  outdata );
				break;
			
			// use channels
			default:
				transfer_channel( size.y, size.x, std::min( inpixel, outpixel ),
								  transfer[i] * inpixel, incount, inputrow, indata,
								  i * outpixel, outcount, outputrow, outdata );
		}
	}
}

// -- UNUSED --
/*static void convert_data( const vec2ui& size,
						  INFI_channels inflow,
						  uint32 inpixel,
						  bool inpadded,
						  void* indata,
						  INFI_channels outflow,
						  uint32 outpixel,
						  bool outpadded,
						  void* outdata ) {
	if ( !check_need_convert( size, inflow, inpixel, inpadded,
									outflow, outpixel, outpadded ) )
		outdata = indata;
	else
		convert_data_basic( size, inflow, inpixel, inpadded, indata, 
								  outflow, outpixel, outpadded, outdata );
}*/
// allocate data
static void convert_data( const vec2ui& size,
						  INFI_channels inflow, 
						  uint32 inpixel,
						  bool inpadded,
						  const void* indata,
						  INFI_channels outflow,
						  uint32 outpixel,
						  bool outpadded, 
						  const void** outdata ) {
	if ( !check_need_convert( size, inflow, inpixel, inpadded,
									outflow, outpixel, outpadded ) ) {
		(*outdata) = indata;
	} else {
		uint32 chancount = InfiGetChannelCount( outflow );
		char* working = (outpadded) ? new char[size.y * align_row( size.x, outpixel * chancount )] :
									  new char[size.y * size.x * outpixel * chancount];
		convert_data_basic( size, inflow, inpixel, inpadded, indata,
								  outflow, outpixel, outpadded, (const void*)working );
		(*outdata) = working;
	}
}

// convert data in-place
static void convert_data( const vec2ui& size,
						  INFI_channels inflow, 
						  uint32 inpixel,
						  bool inpadded,
						  INFI_channels outflow, 
						  uint32 outpixel,
						  bool outpadded, 
						  const void** inoutdata ) {
	cerr << "HERE" << endl;
	void* working;
	convert_data( size, inflow, inpixel, inpadded, *inoutdata,
						outflow, outpixel, outpadded, (const void**) &working );
	if ( *inoutdata != working ) {
		char* indata = (char*) *inoutdata;
		(*inoutdata) = working;
		delete[] indata;
	}
}

} }