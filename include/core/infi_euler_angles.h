#ifndef __INFI_EULER_H__
#define __INFI_EULER_H__

#include "core/infi_vector.h"

namespace INFI {
namespace core {

	struct INFI_EXPORT eulerangles_t {
		float32 yaw,pitch,roll;
		
		// Sampled Z AXIS, Y AXIS, X AXIS in constructors
		// Resolved Z AXIS MATRIX * Y AXIS MATRIX * X AXIS MATRIX
		eulerangles_t();
		eulerangles_t( float32,	  // Rotation about Z
			   float32,	  // Rotation about Y
			   float32 );	// Rotation about X
		eulerangles_t( vec2, float32 );
		eulerangles_t( float32, vec2 );
		eulerangles_t( vec3 );
		
		eulerangles_t operator-();
	};

	std::ostream& operator<< ( std::ostream&, const eulerangles_t& );

} }

#endif//__INFI_EULER_H__
