#ifndef __INFI_TEXTURE_MULTISAMPLE_H__
#define __INFI_TEXTURE_MULTISAMPLE_H__

#include "core/infi_vector.h"
#include "render/infi_texture_base.h"

namespace INFI {
namespace render {
	
	/*	Multisample Textures
			multisample textures function exclusively as targets
			for draw buffer rendering. Operations such as data
			fetching and writing are not allowed.
			Data must be retrieved from the draw target.
			In addition, operations such as swizzling are not allowed.
	*/
	
	struct infi_texture_multisample_t : infi_texture_base_t {
		core::vec2ui	powtwo; 	// closest power of two dimensions
		GLenum  		pxformat;	// internal base format (e.g. GL_RGB)
		GLenum			internal;	// internal sized format (e.g. GL_RGB8UI)
		GLenum			datatype;	// internal data type (e.g. GL_UNSIGNED_INT)
	};
	
	INFI_FUNCTION( infi_texture_multisample_t*, InfiCreateMultisampleTexture, () );
	INFI_FUNCTION( infi_texture_multisample_t*, InfiCreateMultisampleTexture, ( uint32 width, uint32 height ) );
	INFI_FUNCTION( void, InfiCreateMultisampleTexture, ( infi_texture_multisample_t* ) );
	
} }

#endif//__INFI_TEXTURE_MULTISAMPLE_H__