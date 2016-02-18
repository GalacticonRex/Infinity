#ifndef __INFI_AXIANGLE_H__
#define __INFI_AXIANGLE_H__

#include "core/infi_vector.h"

namespace INFI {
namespace core {

	struct INFI_EXPORT AxisAngle {
		vec3 axis;
		float32 angle;
		
		AxisAngle();
		AxisAngle(vec3,float32); // explicit dump
		AxisAngle(float32,vec3); // ""
		AxisAngle(vec3,vec3); // angle between two vectors
		
		vec3 simplify();
	};

	INFI_FUNCTION( std::ostream&, operator<<, ( std::ostream&, const AxisAngle& ) );

} }

#endif//__INFI_AXIANGLE_H__
