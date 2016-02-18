#include "core/infi_axis_angle.h"

namespace INFI {
namespace core {

namespace {
	using namespace std;
}

AxisAngle::AxisAngle() {
	axis = vec3(1,0,0);
	angle = 0;
}
AxisAngle::AxisAngle(vec3 v,float32 n) {
	axis = Normalize(v);
	angle = n;
}
AxisAngle::AxisAngle(float32 n,vec3 v) {
	axis = Normalize(v);
	angle = n;
}
AxisAngle::AxisAngle(vec3 a,vec3 b)
{
	if ( a == b ) {
		axis = vec3(1,0,0);
		angle = 0;
	} else {
		axis = Normalize( Cross(a,b) );
		angle = Angle( a,b );
	}
}

vec3 AxisAngle::simplify() { return axis * angle; }

ostream& operator<< ( ostream& out, const AxisAngle& aa ) {
	out << "axis" << aa.axis << " | angle<" << aa.angle << ">";
	return out;
}

} } 
