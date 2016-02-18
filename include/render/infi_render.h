#ifndef __INFI_RENDER_FUNCTIONS_H__
#define __INFI_RENDER_FUNCTIONS_H__

#include "main/infi_export.h"
#include "core/infi_vector.h"
#include "core/infi_rect.h"
#include "render/infi_render_structs.h"

namespace INFI {
namespace render {
	
	INFI_FUNCTION( void, InfiLInitRender, () );
	INFI_FUNCTION( void, InfiLQuitRender, () );
	
	// control functions
	INFI_FUNCTION( void, InfiLSignalTransformChange, () );
	INFI_FUNCTION( void, InfiLSignalViewportChange, () );
	
	// get screen dimensions
	INFI_FUNCTION( float32, InfiGetRatio, () );
	INFI_FUNCTION( const core::vec2ui&, InfiGetDimensions, () );
	INFI_FUNCTION( const core::rectf&, InfiGetRect, () );
	
	INFI_FUNCTION( void, InfiPushColor, () );
	INFI_FUNCTION( void, InfiPushColor, ( const core::vec4& ) );
	INFI_FUNCTION( void, InfiPopColor, () );
	INFI_FUNCTION( void, InfiSetColor, ( const core::vec4& ) );
	INFI_FUNCTION( void, InfiSetColor, ( float32, float32, float32, float32=1.f ) );
	INFI_FUNCTION( const core::vec4&, InfiGetColor, () );
	
	INFI_FUNCTION( void, InfiSetPrimitives, ( INFI_render_style ) );
	INFI_FUNCTION( void, InfiPushPrimitives, ( INFI_render_style ) );
	INFI_FUNCTION( void, InfiPopPrimitives, () );
	
	INFI_FUNCTION( void, InfiDraw, () );
	INFI_FUNCTION( void, InfiDraw, ( uint32 ) );
	INFI_FUNCTION( void, InfiDraw, ( uint32, uint32 ) );
	
} }

#endif//__INFI_RENDER_FUNCTIONS_H__