#ifndef __INFI_AXIANGLE_H__
#define __INFI_AXIANGLE_H__

#include "core/infi_vector.h"

namespace INFI {
namespace core {

	struct INFI_EXPORT axisangle_t {
		vec3 axis;
		float32 angle;
		
		axisangle_t();
		axisangle_t(vec3,float32); // explicit dump
		axisangle_t(float32,vec3); // ""
		axisangle_t(vec3,vec3); // angle between two vectors
		
		vec3 simplify();
	};

	INFI_FUNCTION( std::ostream&, operator<<, ( std::ostream&, const axisangle_t& ) );

} }

#endif//__INFI_AXIANGLE_H__
