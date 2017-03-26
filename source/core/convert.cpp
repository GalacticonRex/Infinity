#include "core/convert.hpp"
#include "core/euler_angles.hpp"
#include "core/axis_angle.hpp"
#include "core/quaternion.hpp"

namespace core {

mat2 toMatrix(float32 ang) {
	float32 s = sin(ang), c = cos(ang);
	return create2( c,-s,s,c );
}

mat3 toMatrix(const eulerangles_t& n)
{
	float32 sr = sin(n.roll),sp = sin(n.pitch),sy = sin(n.yaw),
			   cr = cos(n.roll),cp = cos(n.pitch),cy = cos(n.yaw);

	return create3( cp*cy,  sr*sp*cy + cr*sy, 	-cr*sp*cy + sr*sy,
					-cp*sy, -sr*sp*sy + cr*cy,  cr*sp*sy + cy*sr,
					sp,		-cp*sr,			 	cr*cp );
}
mat3 toMatrix(const axisangle_t& n)
{
	float32 c = cos(n.angle), s = sin(n.angle), t = 1. - c,
			   x = n.axis.x, y = n.axis.y, z = n.axis.z;
	return create3( c + t * x*x, t * x*y + z * s, t * x*z - s * y,
						  t * x*y - s * z, c + t * y*y, t * y*z + s * x,
						  t * x*z + s * y, t * y*z - s * x, c + t * z*z );
}
mat3 toMatrix(const quaternion_t& q)
{
	return create3( 1 - 2*q.j*q.j - 2*q.k*q.k,	2*q.i*q.j + 2*q.k*q.w,	  2*q.i*q.k - 2*q.j*q.w,
						  2*q.i*q.j - 2*q.k*q.w,		1 - 2*q.i*q.i - 2*q.k*q.k,  2*q.j*q.k + 2*q.i*q.w,
						  2*q.i*q.k + 2*q.j*q.w,		2*q.j*q.k - 2*q.i*q.w,	  1 - 2*q.i*q.i - 2*q.j*q.j );
}

eulerangles_t toEuler(const axisangle_t& n)
{
	float32 s = sin(n.angle), c = cos(n.angle), t = 1.-c;
	float32 head, atti, bank;

	if ( n.axis.x*n.axis.z*t+n.axis.y*s > 0.999999 )
	{
		head = MATH_PI / 2;
		atti = 2 * atan2( n.axis.x*sin(n.angle/2),cos(n.angle/2) );
		bank = 0;
	}
	else if ( n.axis.x*n.axis.z*t+n.axis.y*s < -0.999999 )
	{
		head = - MATH_PI / 2;
		atti = - 2 * atan2( n.axis.x*sin(n.angle/2),cos(n.angle/2) );
		bank = 0;
	}
	else
	{
		head = atan2(n.axis.x*s - n.axis.z*n.axis.y*t, 1. - (n.axis.x*n.axis.x + n.axis.y*n.axis.y)*t);
		atti = asin(n.axis.x*n.axis.z*t + n.axis.y*s);
		bank = atan2(n.axis.z*s - n.axis.x*n.axis.y*t, 1. - (n.axis.z*n.axis.z + n.axis.y*n.axis.y)*t);
	}
	return eulerangles_t( bank,atti,head );
}
eulerangles_t toEuler(const mat3& n)
{
	float32 yaw = 0,pitch = 0,roll = 0;
	if ( n.data[2] > 0.999999 )
	{
		yaw = atan2( n.data[6],n.data[8] );
		pitch = MATH_PI / 2.;
		roll = 0;
	}
	else if ( n.data[2] < -0.999999 )
	{
		yaw =  atan2( n.data[6],n.data[8] );
		pitch = - MATH_PI / 2.;
		roll = 0;
	}
	else
	{
		yaw = atan2( -n.data[3] , n.data[0] );
		pitch = asin( n.data[6] );
		roll = atan2( -n.data[7], n.data[8] );
	}
	return eulerangles_t( yaw,pitch,roll );
}

eulerangles_t toEuler(const quaternion_t& q)
{
	float32 head = 0,atti = 0,bank = 0;

	atti = asin( 2*q.i*q.j + 2*q.k*q.w );

	if ( q.i*q.j + q.k*q.w == 0.5 )
	{
		head = 2 * atan2( q.i,q.w );
		bank = 0;
	}
	else if ( q.i*q.j + q.k*q.w == -0.5 )
	{
		head = -2 * atan2( q.i,q.w );
		bank = 0;
	}
	else
	{
		head = atan2( 2*q.j*q.w - 2*q.i*q.k, 1 - 2*q.j*q.j - 2*q.k*q.k );
		bank = atan2( 2*q.i*q.w - 2*q.j*q.k, 1 - 2*q.i*q.i - 2*q.k*q.k );
	}
	return eulerangles_t( bank,atti,head );
}

axisangle_t toAxisAngle(const eulerangles_t& n)
{
	float32 s1=sin(n.yaw/2),s2=sin(n.pitch/2),s3=sin(n.roll/2),
			   c1=cos(n.yaw/2),c2=cos(n.pitch/2),c3=cos(n.roll/2);

	float32 a = 2 * acos( c1*c2*c3 - s1*s2*s3 );
	vec3 v( c1*c2*s3 + s1*s2*c3,
			c1*s2*c3 - s1*c2*s3,
			s1*c2*c3 + c1*s2*s3 );

	if ( Length(v) < 0.0000001 ) return axisangle_t();
	return axisangle_t( a,Normalize( v ) );
}
axisangle_t toAxisAngle(const mat3& n)
{
	return toAxisAngle( toEuler(n) );
}
axisangle_t toAxisAngle(const quaternion_t& q) {
	if ( q.w == 1 ) {
		return axisangle_t( vec3(1,0,0),0 );
	} else {
		float32 s = sqrt( 1 - q.w * q.w );
		return axisangle_t( vec3(q.i/s,q.j/s,q.k/s),2 * acos( q.w ) );
	}
}

quaternion_t toQuaternion(const eulerangles_t& n)
{
	float32 s1=sin(n.yaw/2),s2=sin(n.pitch/2),s3=sin(n.roll/2),
		  c1=cos(n.yaw/2),c2=cos(n.pitch/2),c3=cos(n.roll/2);

	float32 i = c1*c2*c3 - s1*s2*s3,
			   a = 2 * acos( i ),
			   s = sin( a/2. );
	vec3 v = Normalize( vec3( s1*s2*c3 + c1*c2*s3,
							  c1*s2*c3 - s1*c2*s3,
							  s1*c2*c3 + c1*s2*s3 ) ) * s;

	return quaternion_t( v.x,v.y,v.z,i );
}
quaternion_t toQuaternion(const axisangle_t& aa)
{
	float32 s = sin( aa.angle/2. );
	vec3 tmp = aa.axis * s;
	return quaternion_t( tmp.x, tmp.y, tmp.z, cos( aa.angle/2. ) );
}
quaternion_t toQuaternion(const mat3& mat)
{
	return toQuaternion( toEuler( mat ) );
}

}
