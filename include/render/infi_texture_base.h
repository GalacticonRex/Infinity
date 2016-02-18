#ifndef __INFI_TEXTURE_BASE_H__
#define __INFI_TEXTURE_BASE_H__

#include "core/infi_vector.h"

namespace INFI {
namespace render {
	
	#define INFI_TEXTURE_ALIGNMENT (infi_texture_base_t::pxalign)
	
	struct INFI_EXPORT infi_texture_base_t {
		static uint32 	pxalign;
		uint32 			handle;
		core::vec2ui	dimensions;
		GLenum 			pxformat;
		uint32			mipmap;
		virtual ~infi_texture_base_t() { ; }
	};
	
} }

#endif//__INFI_TEXTURE_BASE_H__