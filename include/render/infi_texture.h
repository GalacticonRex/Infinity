#ifndef __INFI_TEXTURE2_2D_H__
#define __INFI_TEXTURE2_2D_H__

#include "core/infi_methods.h"
#include "core/infi_array.h"
#include "core/infi_datablock.h"
#include "core/infi_rect.h"
#include "render/infi_texture_base.h"
#include "render/infi_view_transform.h"

namespace INFI {
namespace render {
	
INFI_FUNCTION( void, InfiLEmptyTextureCache, () );

/*
	The texture channel enumerator allows for implicit
	swizzling and channel count control
		--- INFI_[COLOR][NUMBER]
		The color indicates the incoming data
				RED   = first index
				GREEN = second index
				BLUE  = third index
				ALPHA = fourth index
		The number indicates the target for that data
	EXAMPLES
		INFI_RED1 will take the first(RED) index of every pixel
		and transfer it to the green(1) channel of the texture
			
	COMPARISONS TO GL SWIZZLE VALUES
		INFI_ALPHA0 | INFI_RED1 | INFI_RED2 | INFI_MAX3
		is the same as
		swizzle( GL_ALPHA, GL_RED, GL_RED, GL_ONE )

		because the texture enumerators are OR'd together,
		all the information of a texture's pixel layout is
		condensed into a single value
*/	
// individual channels
typedef uint32 INFI_channels;
const INFI_channels
	INFI_RED0	= 0x00000001,
	INFI_RED1	= 0x00000100,
	INFI_RED2	= 0x00010000,
	INFI_RED3	= 0x01000000,
	
	INFI_GREEN0	= 0x00000002,
	INFI_GREEN1	= 0x00000200,
	INFI_GREEN2	= 0x00020000,
	INFI_GREEN3	= 0x02000000,
	
	INFI_BLUE0	= 0x00000004,
	INFI_BLUE1	= 0x00000400,
	INFI_BLUE2	= 0x00040000,
	INFI_BLUE3	= 0x04000000,
	
	INFI_ALPHA0	= 0x00000008,
	INFI_ALPHA1	= 0x00000800,
	INFI_ALPHA2	= 0x00080000,
	INFI_ALPHA3	= 0x08000000,
	
	INFI_MIN0	= 0x00000010,
	INFI_MIN1	= 0x00001000,
	INFI_MIN2	= 0x00100000,
	INFI_MIN3	= 0x10000000,
	
	INFI_MAX0	= 0x00000020,
	INFI_MAX1	= 0x00002000,
	INFI_MAX2	= 0x00200000,
	INFI_MAX3	= 0x20000000,
	
	// combination channels
	INFI_RG			= INFI_RED0 | INFI_GREEN1,
	INFI_RGB		= INFI_RED0 | INFI_GREEN1 | INFI_BLUE2,
	INFI_RGBA		= INFI_RED0 | INFI_GREEN1 | INFI_BLUE2 | INFI_ALPHA3,
	INFI_111R		= INFI_MAX0 | INFI_MAX1 | INFI_MAX2 | INFI_RED3;
	
// count the number of active channels
// as a side note, inactive channels will be replaced by 
INFI_FUNCTION( uint32, InfiGetChannelCount, ( INFI_channels ) );

// highest channel the swizzle uses
INFI_FUNCTION( uint32, InfiGetChannelHighest, ( INFI_channels ) );

// returns INFI_RED0, INFI_RG, INFI_RGB or INFI_RGBA based on the format
// for example, INFI_11GR returns INFI_RG because only the RED and GREEN
// channels are in use
INFI_FUNCTION( INFI_channels, InfiOrderChannel, ( INFI_channels ) );

// returns INFI_RED0, INFI_RG, INFI_RGB or INFI_RGBA based on the int32 value
INFI_FUNCTION( INFI_channels, InfiGetBaseChannel, ( uint32 ) );

enum INFI_depth_stencil_type {
	INFI_DEPTH16		 = GL_DEPTH_COMPONENT16,
	INFI_DEPTH24 		 = GL_DEPTH_COMPONENT24,
	INFI_DEPTH32 		 = GL_DEPTH_COMPONENT32F,
	INFI_STENCIL 		 = GL_STENCIL_INDEX8,
	INFI_DEPTH24_STENCIL = GL_DEPTH24_STENCIL8,
	INFI_DEPTH32_STENCIL = GL_DEPTH32F_STENCIL8
};

/*
Texture Object will attempt to make all texture operations possible
	even if the GL version does not support it
These extensions are handled
	Non-power-of-two textures
		the texture is allocated as the next largest size
		the data is placed in the corner, and the extra space is zeroed out
		Single and float64 channel textures (GL_RED and GL_RG)
		a GL_RGB texture is allocated, with the blue channel zeroed out 
	Immutable texture storage
		allocate as mutable storage instead
		Swizzle the texture channels
		when data is submitted to the texture, it is reorganized accordingly
		into a texture with an adequate number of channels (i.e. if a blue
		channel is required in the swizzle but not the alpha an RGB texture
		is allocated, if an alpha channel is required an RGBA texture is
		allocated)
These extensions are not handled
	Store floating point values in a texture
		the client is notified that the float32 data is converted to the
		closet integer value instead
	Send integer types to the shader
		the client is notified that the shader will be receiving floats
		scaled to [0,1] instead of integers
*/
struct infi_texture_t : infi_texture_base_t, infi_view_transform_t {
	uint32 			occupancy;	// number of bytes used per row
	uint32 			rowlen;		// number of bytes (including padding) per row
	core::vec2ui	realdim;	// closest power-of-two dimensions
	INFI_channels 	compressed;	// swizzle value
	uint32 			data;		// combination of force_pot, channels, maxchan, and bytesize
								// 00000000000000000000 0111 1111 1111
								// 						 ^ convert_to_int		- incoming data is float32, convert to ubyte
								//						  ^ float_storage		- stored as a floating point value instead of an integer
								//						   ^ integer_shader		- output integer to shader instead of float32
								//							 ^ need_swizzle		- texture needs to be manually swizzled when data is entered
								//							  ^ force_pot		- <realdim> is forced to a power of two
								//							   ^^ channels		- number of channels apparent (min 1)
								//								  ^^ maxchan		- number of actual channels (min 1)
								//									^^ bytesize	- number of bytes per channel (min 1)
	GLenum			internal;	// internal sized format (e.g. GL_RGB8UI)
	GLenum			datatype;	// internal data type (e.g. GL_UNSIGNED_INT)
	
	// get the number of bytes in the texture at a particular mip level
	uint32 buffersize( uint32 ) const;
	
	bool float_storage() const;
	bool integer_shader() const;
	bool needs_swizzle() const;
	bool force_pot() const;
	uint32 channels() const;
	uint32 maxchan() const;
	uint32 bytesize() const;
	
	void swizzle( GLint&, GLint&, GLint&, GLint& ) const;
	void red( GLint& ) const;
	void green( GLint& ) const;
	void blue( GLint& ) const;
	void alpha( GLint& ) const;
	
	uint32& width() { return realdim.x; }
	uint32& height() { return realdim.y; }
	
	const uint32& width() const { return realdim.x; }
	const uint32& height() const { return realdim.y; }
	
	operator core::mat4() const {
		return core::OrthoMat4( core::vec2(), realdim );
	}
	
	~infi_texture_t();
};

// create a color texture
INFI_FUNCTION( infi_texture_t*, InfiCreateTexture, ( const core::vec2ui& dim, 		// size of the texture in pixels
													 infi_t storage, 				// type that the texture can expect as input (INFI_UBYTE)
													 infi_t output, 				// type that the texture outputs to the shader (INFI_FLOAT)
													 INFI_channels chan, 			// what channels this texture will have (1)
													 bool use_mipmaps = true,		// use mipmaps with this texture
													 bool force_pow2 = false ) );	// force the texture to be power of two in memory

// create a depth/stencil texture
INFI_FUNCTION( infi_texture_t*, InfiCreateTexture, ( const core::vec2ui& dim,
													 INFI_depth_stencil_type,
													 bool force_pow2 = false ) );

INFI_FUNCTION( void, InfiDestroyTexture, ( infi_texture_t* ) );

INFI_FUNCTION( infi_texture_t*, InfiCopyTexture, ( const infi_texture_t* src ) );
INFI_FUNCTION( infi_texture_t*, InfiCloneTexture, ( const infi_texture_t* src ) );
INFI_FUNCTION( void, InfiSyncTexture, ( infi_texture_t* ) );
INFI_FUNCTION( void, InfiClearTexture, ( infi_texture_t* ) );
INFI_FUNCTION( void, InfiClearTexture, ( infi_texture_t*, const core::vec4& ) );

INFI_FUNCTION( infi_texture_t*, InfiCurrentTexture, ( uint32=0 ) );
INFI_FUNCTION( void, InfiPushTexture, ( infi_texture_t*, uint32=0 ) );
INFI_FUNCTION( void, InfiPopTexture, () );

// set to individual texture
INFI_FUNCTION( void, InfiSetData, ( infi_texture_t*, const core::indexable_t<uint8>& ) );
INFI_FUNCTION( void, InfiSetData, ( infi_texture_t*, const void* ) );
INFI_FUNCTION( void, InfiSetData, ( infi_texture_t*, const core::rectui&, const core::indexable_t<uint8>& ) );
INFI_FUNCTION( void, InfiSetData, ( infi_texture_t*, const core::rectui&, const void* ) );

INFI_FUNCTION( void, InfiGetData, ( infi_texture_t*, core::data_t<uint8>&, uint32 = 0 ) );
INFI_FUNCTION( void, InfiGetData, ( infi_texture_t*, core::data_t<uint8>&, const core::rectui&, uint32 = 0 ) );

INFI_FUNCTION( void, InfiSetTextureAttrib, ( infi_texture_t*, GLuint, int32 ) );
INFI_FUNCTION( void, InfiSetTextureAttrib, ( infi_texture_t*, GLuint, float32 ) );
INFI_FUNCTION( void, InfiSetTextureAttrib, ( infi_texture_t*, GLuint, int32* ) );
INFI_FUNCTION( void, InfiSetTextureAttrib, ( infi_texture_t*, GLuint, float32* ) );

INFI_FUNCTION( void, InfiNearestTexel, ( infi_texture_t* ) );
INFI_FUNCTION( void, InfiBilinearTexel, ( infi_texture_t* ) );

INFI_FUNCTION( void, InfiRepeatTexture, ( infi_texture_t* ) );
INFI_FUNCTION( void, InfiClampTexture, ( infi_texture_t* ) );

INFI_FUNCTION( void, InfiSetTextureSwizzle, ( infi_texture_t*, INFI_channels ) );

INFI_FUNCTION( void, InfiDebugTexture, ( infi_texture_t*, std::ostream& = std::cerr ) );

// low level accessors
INFI_FUNCTION( void, InfiLSetTextureData, ( infi_texture_t*, const core::indexable_t<uint8>& ) );
INFI_FUNCTION( void, InfiLSetTextureData, ( infi_texture_t*, void* ) );
INFI_FUNCTION( void, InfiLSetTextureData, ( infi_texture_t*, const core::rectui&, const core::indexable_t<uint8>& ) );
INFI_FUNCTION( void, InfiLSetTextureData, ( infi_texture_t*, const core::rectui&, void* ) );

INFI_FUNCTION( void, InfiLGetTextureData, ( infi_texture_t*, core::data_t<uint8>&, uint32 = 0 ) );
INFI_FUNCTION( void, InfiLGetTextureData, ( infi_texture_t*, core::data_t<uint8>&, const core::rectui&, uint32 = 0 ) );

// debug display
std::ostream& operator<< ( std::ostream&, infi_texture_t* );

} }

#endif//__INFI_TEXTURE_2D_H__