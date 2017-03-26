#ifndef __CONVERT_H__
#define __CONVERT_H__

#include "core/matrix.hpp"
#include "core/axis_angle.hpp"
#include "core/euler_angles.hpp"
#include "core/quaternion.hpp"

namespace core {

	// convert 2D rotations
	DEFINE_EXPORTED_FUNCTION( float32, toFloat, (const mat2&) );
	DEFINE_EXPORTED_FUNCTION( mat2, toMatrix, (float32) );

	// convert 3D rotations to different representations
	DEFINE_EXPORTED_FUNCTION( mat3, toMatrix, (const eulerangles_t&) );
	DEFINE_EXPORTED_FUNCTION( mat3, toMatrix, (const axisangle_t&) );
	DEFINE_EXPORTED_FUNCTION( mat3, toMatrix, (const quaternion_t&) );

	DEFINE_EXPORTED_FUNCTION( axisangle_t, toAxisAngle, (const eulerangles_t&) );
	DEFINE_EXPORTED_FUNCTION( axisangle_t, toAxisAngle, (const mat3&) );
	DEFINE_EXPORTED_FUNCTION( axisangle_t, toAxisAngle, (const quaternion_t&) );

	DEFINE_EXPORTED_FUNCTION( eulerangles_t, toEuler, (const mat3&) );
	DEFINE_EXPORTED_FUNCTION( eulerangles_t, toEuler, (const axisangle_t&) );
	DEFINE_EXPORTED_FUNCTION( eulerangles_t, toEuler, (const quaternion_t&) );

	DEFINE_EXPORTED_FUNCTION( quaternion_t, toQuaternion, (const mat3&) );
	DEFINE_EXPORTED_FUNCTION( quaternion_t, toQuaternion, (const axisangle_t&) );
	DEFINE_EXPORTED_FUNCTION( quaternion_t, toQuaternion, (const eulerangles_t&) );

}

#endif//__CONVERT_H__
