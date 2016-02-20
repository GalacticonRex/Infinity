#include "core/infi_rotations.h"
#include "core/infi_convert.h"
#include "core/infi_euler_angles.h"
#include "core/infi_axis_angle.h"
#include "core/infi_quaternion.h"

namespace INFI {
namespace core {

vec2 Rotate(vec2 v,float32 r) {
	return vec2( v.x * cos( r ) - v.y * sin( r ),
				 v.x * sin( r ) + v.y * cos( r ) );
}
vec2 Rotate(vec2 v,mat2 r) {
	return vec2( v.x * r.data[0] + v.y * r.data[1],
				 v.x * r.data[2] + v.y * r.data[3] );
}

vec3 Rotate(vec3 v,mat3 n) {
	return vec3( v.x*n.data[0] + v.y*n.data[3] + v.z*n.data[6],
				 v.x*n.data[1] + v.y*n.data[4] + v.z*n.data[7],
				 v.x*n.data[2] + v.y*n.data[5] + v.z*n.data[8] );
}
vec3 Rotate(vec3 v,eulerangles_t r) {
	mat3 n = toMatrix( r );
	return vec3( v.x*n.data[0] + v.y*n.data[3] + v.z*n.data[6],
				 v.x*n.data[1] + v.y*n.data[4] + v.z*n.data[7],
				 v.x*n.data[2] + v.y*n.data[5] + v.z*n.data[8] );
}
vec3 Rotate(vec3 v,axisangle_t n) {
	float32 cosw = cos( n.angle );
	return v * cosw + 
		   Cross( v,n.axis ) * sin( -n.angle ) + 
		   n.axis * Dot( v,n.axis ) * (1.-cosw);
}
vec3 Rotate(vec3 v,quaternion_t r) {
	quaternion_t q = Product( Product( r, asQuaternion( vec4(v.x,v.y,v.z,0.f) ) ), r.inverse() );
	return vec3( q.asVector().xyz() );
}

} }
