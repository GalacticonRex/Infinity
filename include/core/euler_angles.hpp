#ifndef __EULER_ANGLES_H__
#define __EULER_ANGLES_H__

#include "core/vector.hpp"

namespace core {

	struct eulerangles_t {
		float32 yaw,pitch,roll;

		// Sampled Z AXIS, Y AXIS, X AXIS in constructors
		// Resolved Z AXIS MATRIX * Y AXIS MATRIX * X AXIS MATRIX
		eulerangles_t();
		eulerangles_t( float32,	  // Rotation about Z
					   float32,	  // Rotation about Y
					   float32 ); // Rotation about X
		eulerangles_t( vec2, float32 );
		eulerangles_t( float32, vec2 );
		eulerangles_t( vec3 );

		eulerangles_t operator-();
	};

	std::ostream& operator<< ( std::ostream&, const eulerangles_t& );

}

#endif//__EULER_ANGLES_H__
