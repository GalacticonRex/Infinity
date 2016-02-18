#ifndef __INFI_EULER_H__
#define __INFI_EULER_H__

#include "core/infi_vector.h"

namespace INFI {
namespace core {

	struct INFI_EXPORT EulerAngles {
		float32 yaw,pitch,roll;
		
		// Sampled Z AXIS, Y AXIS, X AXIS in constructors
		// Resolved Z AXIS MATRIX * Y AXIS MATRIX * X AXIS MATRIX
		EulerAngles();
		EulerAngles( float32,	  // Rotation about Z
			   float32,	  // Rotation about Y
			   float32 );	// Rotation about X
		EulerAngles( vec2, float32 );
		EulerAngles( float32, vec2 );
		EulerAngles( vec3 );
		
		EulerAngles operator-();
	};

	std::ostream& operator<< ( std::ostream&, const EulerAngles& );

} }

#endif//__INFI_EULER_H__
