#ifndef __INFI_ROTATION_H__
#define __INFI_ROTATION_H__

#include "core/infi_vector.h"
#include "core/infi_matrix.h"
#include "core/infi_euler_angles.h"
#include "core/infi_axis_angle.h"
#include "core/infi_quaternion.h"

namespace INFI {
namespace core {
	
	struct rotation_t {
		
	};

	INFI_FUNCTION( vec2, Rotate, (vec2,float32) );
	INFI_FUNCTION( vec2, Rotate, (vec2,mat2) );

	INFI_FUNCTION( vec3, Rotate, (vec3,mat3) );
	INFI_FUNCTION( vec3, Rotate, (vec3,eulerangles_t) );
	INFI_FUNCTION( vec3, Rotate, (vec3,axisangle_t) );
	INFI_FUNCTION( vec3, Rotate, (vec3,quaternion_t) );

} }

#endif//__INFI_ROTATIONH__
