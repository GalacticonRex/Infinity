#ifndef __INFI_RENDER_TRANSFORM_H__
#define __INFI_RENDER_TRANSFORM_H__

#include "core/infi_convert.h"
#include "core/infi_rotations.h"

namespace INFI {
namespace render {

	INFI_FUNCTION( void, InfiResetTransform, () );
	
	INFI_FUNCTION( void, InfiPushTransform, () );
	INFI_FUNCTION( void, InfiPushNewTransform, () );
	INFI_FUNCTION( void, InfiPushTransform, ( const core::mat4& ) );
	INFI_FUNCTION( void, InfiAddTransform, ( const core::mat4& ) );
	INFI_FUNCTION( void, InfiTranslate, ( const core::vec2& ) );
	INFI_FUNCTION( void, InfiTranslate, ( const core::vec3& ) );
	INFI_FUNCTION( void, InfiTranslate, ( float32, float32 ) );
	INFI_FUNCTION( void, InfiTranslate, ( float32, float32, float32 ) );
	INFI_FUNCTION( void, InfiRotate, ( float32 ) );
	INFI_FUNCTION( void, InfiRotate, ( const core::EulerAngles& ) );
	INFI_FUNCTION( void, InfiRotate, ( const core::AxisAngle& ) );
	INFI_FUNCTION( void, InfiRotate, ( const core::Quaternion& ) );
	INFI_FUNCTION( void, InfiScale, ( float32 ) );
	INFI_FUNCTION( void, InfiScale, ( const core::vec2& ) );
	INFI_FUNCTION( void, InfiScale, ( const core::vec3& ) );
	INFI_FUNCTION( void, InfiScale, ( float32, float32 ) );
	INFI_FUNCTION( void, InfiScale, ( float32, float32, float32 ) );
	
	INFI_FUNCTION( void, InfiPopTransform, () );
	
	INFI_FUNCTION( const core::mat4&, InfiGetTransform, () );
	
	INFI_FUNCTION( const core::mat4&, InfiGetCameraAndTransform, () );
	
} }
	
#endif//__INFI_RENDER_TRANSFORM_H__