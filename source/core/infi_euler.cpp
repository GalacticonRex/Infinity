#include "core/infi_euler_angles.h"

namespace INFI {
namespace core {

EulerAngles::EulerAngles()
{
	yaw = 0;
	pitch = 0;
	roll = 0;
}
EulerAngles::EulerAngles( float32 y,float32 p,float32 r )
{
	yaw = y;
	pitch = p;
	roll = r;
}
EulerAngles::EulerAngles( vec2 yp, float32 r )
{
	yaw = yp.x;
	pitch = yp.y;
	roll = r;
}
EulerAngles::EulerAngles( float32 y, vec2 pr )
{
	yaw = y;
	pitch = pr.x;
	roll = pr.y;
}
EulerAngles::EulerAngles( vec3 v )
{
	yaw = v.x;
	pitch = v.y;
	roll = v.z;
}
EulerAngles EulerAngles::operator-()
{
	return EulerAngles( -yaw,-pitch,-roll );
}

std::ostream& operator<< ( std::ostream& ostr, const EulerAngles& ang ) {
	ostr << "<" << ang.yaw << ", " << ang.pitch << ", " << ang.roll << ">";
	return ostr;
}

} }
