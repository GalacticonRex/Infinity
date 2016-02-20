#ifndef __INFI_BLEND_MODE_H__
#define __INFI_BLEND_MODE_H__

#include "main/infi_export.h"
#include "main/infi_types.h"

namespace INFI {
namespace render {
	
INFI_FUNCTION( void, InfiLEmptyBlendModeCache, () );

const uint32 INFI_BLEND_DO_NOTHING	 = 0x00, // don't do anything
			 INFI_BLEND_EQUATION	 = 0x01, // use equation
			 INFI_BLEND_EQUATION_SEP = 0x02, // use equation separate
			 INFI_BLEND_FUNCTION	 = 0x10, // use function
			 INFI_BLEND_FUNCTION_SEP = 0x20; // use function sep
			
struct infi_blend_t {
	uint32 usage;	 // flag list for 
	
	GLenum srcalpha;  // source alpha type
	GLenum srccolor;  // source color type
	GLenum dstalpha;  // destination alpha type
	GLenum dstcolor;  // destination color type
	
	GLenum funcalpha; // equation type ( e.g. ADD, SUBTRACT )
	GLenum funccolor; // equation type ( e.g. ADD, SUBTRACT )
	
	infi_blend_t();
	~infi_blend_t();
};

INFI_FUNCTION( const infi_blend_t*, BlendMix, () );
INFI_FUNCTION( const infi_blend_t*, BlendMixAlphaOnly, () );
INFI_FUNCTION( const infi_blend_t*, BlendMixWeighted, () );
INFI_FUNCTION( const infi_blend_t*, BlendExact, () );
INFI_FUNCTION( const infi_blend_t*, BlendAdd, () );
INFI_FUNCTION( const infi_blend_t*, BlendText, () );
	
} }

#endif//__INFI_BLEND_MODE_H__