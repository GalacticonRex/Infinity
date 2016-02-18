#ifndef __INFI_STENCIL_MODE_H__
#define __INFI_STENCIL_MODE_H__

#include "core/infi_vector.h"

namespace INFI {
namespace render {
	
INFI_FUNCTION( void, InfiLEmptyStencilModeCache, () );

// INFI_BLEND_SEPARATE affects INFI_BLEND_FUNC and INFI_BLEND_EQUATION
// INFI_BLEND_ACTIVE and INFI_BLEND_INACTIVE mutually exclusive
const uint32 INFI_STENCIL_DO_NOTHING = 0x00000000,
			 INFI_STENCIL_FUNC		 = 0x00000001,
			 INFI_STENCIL_OP		 = 0x00000002,
			 INFI_STENCIL_MASK		 = 0x00000004,
			 INFI_STENCIL_FRONT		 = 0x00000010,
			 INFI_STENCIL_BACK		 = 0x00000020;

struct infi_stencil_t {
	uint32	usage;	// | flag list for ==>
	GLenum	func;	// | group 1
	int32	ref;	// | 
	uint32	mask;	// | 
	GLenum	sfail;	// | group 2
	GLenum	dpfail;	// | 
	GLenum	dppass;	// | 
	uint32	wmask;	// | group 3
};

INFI_FUNCTION( infi_stencil_t*, InfiCreateStencil, () );

} }

#endif//__INFI_STENCIL_MODE_H__
