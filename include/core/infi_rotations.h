#ifndef __INFI_ROTATION_H__
#define __INFI_ROTATION_H__

#include "core/infi_vector.h"
#include "core/infi_matrix.h"
#include "core/infi_euler_angles.h"
#include "core/infi_axis_angle.h"
#include "core/infi_quaternion.h"

namespace INFI {
namespace core {

	INFI_FUNCTION( vec2, Rotate, (vec2,float32) );
	INFI_FUNCTION( vec2, Rotate, (vec2,mat2) );

	INFI_FUNCTION( vec3, Rotate, (vec3,mat3) );
	INFI_FUNCTION( vec3, Rotate, (vec3,EulerAngles) );
	INFI_FUNCTION( vec3, Rotate, (vec3,AxisAngle) );
	INFI_FUNCTION( vec3, Rotate, (vec3,Quaternion) );

} }

#endif//__INFI_ROTATIONH__
