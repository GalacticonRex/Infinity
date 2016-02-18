#ifndef __INFI_STANDARD_OBJECT_H__
#define __INFI_STANDARD_OBJECT_H__

#include "core/infi_rect.h"
#include "render/infi_render_structs.h"

namespace INFI {
namespace render {

	// get basic objects
	INFI_FUNCTION( void, InfiLInitObjects, () );
	INFI_FUNCTION( void, InfiLQuitObjects, () );
	
	// shaders
	INFI_FUNCTION( infi_program_t*, InfiRect2DShader, () );
	INFI_FUNCTION( infi_program_t*, InfiHSVtoRGB, () );
	INFI_FUNCTION( infi_program_t*, InfiRGBtoHSV, () );
	INFI_FUNCTION( infi_program_t*, InfiHSVBlend, () );
	
	// vertex objects
	INFI_FUNCTION( infi_vertices_t*, InfiRect2DVertices, () );
	
	// functions
	INFI_FUNCTION( void, InfiDrawRect, ( core::rectf, infi_texture_t* = NULL, float32 = 0 ) );
	
	INFI_FUNCTION( infi_texture_t*, InfiConvertTexture, ( infi_texture_t*,
														  infi_program_t*,
														  const char* = "teximage" ) );
	INFI_FUNCTION( void, InfiConvertTexture, ( infi_texture_t*,
											   infi_texture_t*,
											   infi_program_t*,
											   const char* = "teximage" ) );
	
} }	

#endif//__INFI_STANDARD_OBJECT_H__