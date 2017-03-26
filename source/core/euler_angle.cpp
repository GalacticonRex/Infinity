#include "core/euler_angles.hpp"

namespace core {

eulerangles_t::eulerangles_t()
{
	yaw = 0;
	pitch = 0;
	roll = 0;
}
eulerangles_t::eulerangles_t( float32 y,float32 p,float32 r )
{
	yaw = y;
	pitch = p;
	roll = r;
}
eulerangles_t::eulerangles_t( vec2 yp, float32 r )
{
	yaw = yp.x;
	pitch = yp.y;
	roll = r;
}
eulerangles_t::eulerangles_t( float32 y, vec2 pr )
{
	yaw = y;
	pitch = pr.x;
	roll = pr.y;
}
eulerangles_t::eulerangles_t( vec3 v )
{
	yaw = v.x;
	pitch = v.y;
	roll = v.z;
}
eulerangles_t eulerangles_t::operator-()
{
	return eulerangles_t( -yaw,-pitch,-roll );
}

std::ostream& operator<< ( std::ostream& ostr, const eulerangles_t& ang ) {
	ostr << "<" << ang.yaw << ", " << ang.pitch << ", " << ang.roll << ">";
	return ostr;
}

}
