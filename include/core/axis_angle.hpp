#ifndef __AXIS_ANGLES_H__
#define __AXIS_ANGLES_H__

#include "core/vector.hpp"

namespace core {

	struct axisangle_t {
		vec3 axis;
		float32 angle;

		axisangle_t();
		axisangle_t(vec3 ax,float32 an); // explicit dump
		axisangle_t(float32 an,vec3 ax); // ""
		axisangle_t(vec3 v1,vec3 v2); // angle between two vectors

		vec3 simplify();
	};

	DEFINE_EXPORTED_FUNCTION( std::ostream&, operator<<, ( std::ostream&, const axisangle_t& ) );

}

#endif//__AXIS_ANGLES_H__
