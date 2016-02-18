#ifndef __INFI_RENDERBUFFER_H__
#define __INFI_RENDERBUFFER_H__

#include "core/infi_vector.h"
#include "render/infi_texture_base.h"

namespace INFI {
namespace render {
	
	INFI_FUNCTION( void, InfiLEmptyRenderbufferCache, () );
	
	struct infi_renderbuffer_t : infi_texture_base_t {
		uint32 samples;
	};
	
	INFI_FUNCTION( infi_renderbuffer_t*, InfiCreateRenderbuffer, () );
	INFI_FUNCTION( infi_renderbuffer_t*, InfiCreateRenderbuffer, ( uint32 width, uint32 height, GLenum format ) );
	INFI_FUNCTION( void, InfiDestroyRenderbuffer, ( infi_renderbuffer_t* ) );
	
	INFI_FUNCTION( void, InfiFormat, ( infi_renderbuffer_t*, uint32 width, uint32 height, GLenum format ) );
	INFI_FUNCTION( void, InfiFormat, ( infi_renderbuffer_t*, core::vec2ui dim, GLenum format ) );
} }

#endif//__INFI_RENDERBUFFER_H__