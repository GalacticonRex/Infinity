#include "core/infi_convert.h"
#include "core/infi_euler_angles.h"
#include "core/infi_axis_angle.h"
#include "core/infi_quaternion.h"

namespace INFI {
namespace core {

vec3 toHSV( float32 r, float32 g, float32 b ) {
	vec3 hsv;
	float32 mmin, mmax, delta;
	
	if( r > g ) {
		if ( g > b ) { // r, g, b
			mmin = b;
			mmax = r;
			delta = mmax - mmin;
			hsv.h = ( g - b ) / delta;
		} else if ( r > b ) { // r, b, g
			mmin = g;
			mmax = r;
			delta = mmax - mmin;
			hsv.h = ( g - b ) / delta;
		} else { // b, r, g
			mmin = g;
			mmax = b;
			delta = mmax - mmin;
			hsv.h = 4 + ( r - g ) / delta;
		}
	} else {
		if ( b > g ) { // b, g, r
			mmin = r;
			mmax = b;
			delta = mmax - mmin;
			hsv.h = 4 + ( r - g ) / delta;
		} else if ( b > r ) { // g, b, r
			mmin = r;
			mmax = g;
			delta = mmax - mmin;
			hsv.h = 2 + ( b - r ) / delta;
		} else { // g, r, b
			mmin = b;
			mmax = g;
			delta = mmax - mmin;
			hsv.h = 2 + ( b - r ) / delta;
		}
	}
	
	hsv.v = mmax;
	if ( mmax != 0 ) {
		hsv.s = delta / mmax;
	} else {
		hsv.s = 0;
		hsv.h = -1;
		return hsv;
	}
	
	hsv.h *= MATH_PI / 3;
	while ( hsv.h < 0 )
		hsv.h += MATH_PI * 2;
	
	return hsv;
}
vec3 toRGB( float32 h, float32 s, float32 v ) {
	int32 i;
	float32 f, p, q, t;
	if ( s == 0 )
		return vec3( v,v,v );
	
	while ( h < 0 )
		h += MATH_PI * 2;
	while ( h >= MATH_PI * 2 )
		h -= MATH_PI * 2;
	
	h *= 3 / MATH_PI;
	
	i = floor( h );
	f = h - i;
	p = v * ( 1 - s );
	q = v * ( 1 - s * f );
	t = v * ( 1 - s * ( 1 - f ) );
	
	switch( i ) {
		case 0:
			return vec3( v, t, p ); 
			break;
		case 1:
			return vec3( q, v, p ); 
			break;
		case 2:
			return vec3( p, v, t ); 
			break;
		case 3:
			return vec3( p, q, v ); 
			break;
		case 4:
			return vec3( t, p, v ); 
			break;
		case 5:
			return vec3( v, p, q ); 
			break;
		default:
			return vec3(); 
			break;
	}
}
	
vec3 toHSV( const vec3& rgb ) {
	return toHSV( rgb.r, rgb.g, rgb.b );
}
vec3 toRGB( const vec3& hsv ) {
	return toRGB( hsv.h, hsv.s, hsv.v );
}


vec2 toCartesian( float32 length, float32 angle ) {
	return vec2( length * cos( angle ), length * sin( angle ) );
}
vec2 toCartesian( vec2 polar ) {
	return vec2( polar.x * cos( polar.y ), polar.x * sin( polar.y ) );
}
vec2 toPolar( float32 x, float32 y ) {
	return vec2( sqrt( x*x + y*y ), atan2( y, x ) );
}
vec2 toPolar( vec2 carte ) {
	return vec2( Length(carte), atan2( carte.y, carte.x ) );
}

mat2 toMatrix(float32 ang) {
	float32 s = sin(ang), c = cos(ang);
	return CreateMatrix( c,-s,s,c );
}

mat3 toMatrix(const EulerAngles& n)
{
	float32 sr = sin(n.roll),sp = sin(n.pitch),sy = sin(n.yaw),
			   cr = cos(n.roll),cp = cos(n.pitch),cy = cos(n.yaw);
			   
	return CreateMatrix(  cp*cy,  sr*sp*cy + cr*sy, -cr*sp*cy + sr*sy,
						  -cp*sy, -sr*sp*sy + cr*cy,  cr*sp*sy + cy*sr,
						   sp,	-cp*sr,			 cr*cp );
}
mat3 toMatrix(const AxisAngle& n)
{
	float32 c = cos(n.angle), s = sin(n.angle), t = 1. - c,
			   x = n.axis.x, y = n.axis.y, z = n.axis.z;
	return CreateMatrix( c + t * x*x, t * x*y + z * s, t * x*z - s * y,
						  t * x*y - s * z, c + t * y*y, t * y*z + s * x,
						  t * x*z + s * y, t * y*z - s * x, c + t * z*z );
}
mat3 toMatrix(const Quaternion& q)
{
	return CreateMatrix( 1 - 2*q.j*q.j - 2*q.k*q.k,	2*q.i*q.j + 2*q.k*q.w,	  2*q.i*q.k - 2*q.j*q.w,
						  2*q.i*q.j - 2*q.k*q.w,		1 - 2*q.i*q.i - 2*q.k*q.k,  2*q.j*q.k + 2*q.i*q.w,
						  2*q.i*q.k + 2*q.j*q.w,		2*q.j*q.k - 2*q.i*q.w,	  1 - 2*q.i*q.i - 2*q.j*q.j );
}

EulerAngles toEuler(const AxisAngle& n)
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
	return EulerAngles( bank,atti,head );
}
EulerAngles toEuler(const mat3& n)
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
	return EulerAngles( yaw,pitch,roll );
}

EulerAngles toEuler(const Quaternion& q)
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
	return EulerAngles( bank,atti,head );
}

AxisAngle toAxisAngle(const EulerAngles& n)
{
	float32 s1=sin(n.yaw/2),s2=sin(n.pitch/2),s3=sin(n.roll/2),
			   c1=cos(n.yaw/2),c2=cos(n.pitch/2),c3=cos(n.roll/2);
		   
	float32 a = 2 * acos( c1*c2*c3 - s1*s2*s3 );
	vec3 v( c1*c2*s3 + s1*s2*c3,
			c1*s2*c3 - s1*c2*s3,
			s1*c2*c3 + c1*s2*s3 );
	
	if ( Length(v) < 0.0000001 ) return AxisAngle();
	return AxisAngle( a,Normalize( v ) );
}
AxisAngle toAxisAngle(const mat3& n)
{
	return toAxisAngle( toEuler(n) );
}
AxisAngle toAxisAngle(const Quaternion& q) {
	if ( q.w == 1 ) {
		return AxisAngle( vec3(1,0,0),0 );
	} else {
		float32 s = sqrt( 1 - q.w * q.w );
		return AxisAngle( vec3(q.i/s,q.j/s,q.k/s),2 * acos( q.w ) );
	}
}

Quaternion toQuaternion(const EulerAngles& n)
{
	float32 s1=sin(n.yaw/2),s2=sin(n.pitch/2),s3=sin(n.roll/2),
		  c1=cos(n.yaw/2),c2=cos(n.pitch/2),c3=cos(n.roll/2);
		   
	float32 i = c1*c2*c3 - s1*s2*s3, 
			   a = 2 * acos( i ),
			   s = sin( a/2. );
	vec3 v = Normalize( vec3( s1*s2*c3 + c1*c2*s3,
							  c1*s2*c3 - s1*c2*s3,
							  s1*c2*c3 + c1*s2*s3 ) ) * s;
					   
	return Quaternion( v.x,v.y,v.z,i );
}
Quaternion toQuaternion(const AxisAngle& aa)
{
	float32 s = sin( aa.angle/2. );
	vec3 tmp = aa.axis * s;
	return Quaternion( tmp.x, tmp.y, tmp.z, cos( aa.angle/2. ) );
}
Quaternion toQuaternion(const mat3& mat)
{
	return toQuaternion( toEuler( mat ) );
}

} }
