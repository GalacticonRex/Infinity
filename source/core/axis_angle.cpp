#include "core/axis_angle.hpp"

namespace core {

namespace {
	using namespace std;
}

axisangle_t::axisangle_t() {
	axis = vec3(1,0,0);
	angle = 0;
}
axisangle_t::axisangle_t(vec3 v,float32 n) {
	axis = Normalize(v);
	angle = n;
}
axisangle_t::axisangle_t(float32 n,vec3 v) {
	axis = Normalize(v);
	angle = n;
}
axisangle_t::axisangle_t(vec3 a,vec3 b)
{
	if ( a == b ) {
		axis = vec3(1,0,0);
		angle = 0;
	} else {
		axis = Normalize( Cross(a,b) );
		angle = Angle( a,b );
	}
}

vec3 axisangle_t::simplify() { return axis * angle; }

ostream& operator<< ( ostream& out, const axisangle_t& aa ) {
	out << "axis" << aa.axis << " | angle<" << aa.angle << ">";
	return out;
}

}
