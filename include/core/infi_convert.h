#ifndef __INFI_CONVERT_H__
#define __INFI_CONVERT_H__

#include "core/infi_matrix.h"
#include "core/infi_axis_angle.h"
#include "core/infi_euler_angles.h"
#include "core/infi_quaternion.h"

namespace INFI {
namespace core {
	
	// color conversion
	INFI_FUNCTION( vec3, toHSV, ( const vec3& ) );
	INFI_FUNCTION( vec3, toRGB, ( const vec3& ) );

	INFI_FUNCTION( vec3, toHSV, ( float32, float32, float32 ) );
	INFI_FUNCTION( vec3, toRGB, ( float32, float32, float32 ) );

	// convert polar and cartesian coordinates
	INFI_FUNCTION( vec2, toCartesian, ( float32 length, float32 angle ) );
	INFI_FUNCTION( vec2, toCartesian, ( vec2 polar ) );

	INFI_FUNCTION( vec2, toPolar, ( float32 x, float32 y ) );
	INFI_FUNCTION( vec2, toPolar, ( vec2 carte ) );

	// convert 2D rotations
	INFI_FUNCTION( float32, toFloat, (const mat2&) );
	INFI_FUNCTION( mat2, toMatrix, (float32) );

	// convert 3D rotations to different representations
	INFI_FUNCTION( mat3, toMatrix, (const eulerangles_t&) );
	INFI_FUNCTION( mat3, toMatrix, (const axisangle_t&) );
	INFI_FUNCTION( mat3, toMatrix, (const quaternion_t&) );

	INFI_FUNCTION( axisangle_t, toAxisAngle, (const eulerangles_t&) );
	INFI_FUNCTION( axisangle_t, toAxisAngle, (const mat3&) );
	INFI_FUNCTION( axisangle_t, toAxisAngle, (const quaternion_t&) );

	INFI_FUNCTION( eulerangles_t, toEuler, (const mat3&) );
	INFI_FUNCTION( eulerangles_t, toEuler, (const axisangle_t&) );
	INFI_FUNCTION( eulerangles_t, toEuler, (const quaternion_t&) );

	INFI_FUNCTION( quaternion_t, toQuaternion, (const mat3&) );
	INFI_FUNCTION( quaternion_t, toQuaternion, (const axisangle_t&) );
	INFI_FUNCTION( quaternion_t, toQuaternion, (const eulerangles_t&) );

} }

#endif//__INFI_CONVERT_H__
