#include "core/infi_quaternion.h"
#include "core/infi_methods.h"
#include "core/infi_convert.h"
#include "core/infi_axis_angle.h"

namespace INFI {
namespace core {

namespace {
	using namespace std;
}

Quaternion::Quaternion()
	: i(0),j(0),k(0),w(1) { }
Quaternion::Quaternion(float32 i_,float32 j_,float32 k_,float32 w_)
	: i(i_),j(j_),k(k_),w(w_) { }
	
Quaternion Quaternion::operator+ () const { return *this; }
Quaternion Quaternion::operator- () const { return Quaternion(-i,-j,-k,-w); }

const vec4& Quaternion::asVector() const { return *((vec4*)this); }
Quaternion Quaternion::inverse() const {
	return Quaternion( -i, -j, -k, w );
}

const Quaternion& asQuaternion(const vec4& v) {
	return *((const Quaternion*)(&v));
}

float32 Dot( const Quaternion& a, const Quaternion& b ) { 
	return a.w*b.w + a.i*b.i + a.j*b.j + a.k*b.k;
}
Quaternion Blend( const Quaternion& a, const Quaternion& b, float32 c ) {
	float32 d = Clamp(c),
			  qdot = Dot( a,b ),
			  c2 = 1. - d;
	
	if ( qdot < 0 ) {
		vec4 v1 = a.asVector() * c2,
			 v2 = (-b).asVector() * c,
			 v3 = Normalize( v1 + v2 );
		return asQuaternion(v3);
	} else {
		vec4 v1 = a.asVector() * c2,
			 v2 = b.asVector() * c,
			 v3 = Normalize( v1 + v2 );
		return asQuaternion(v3);
	}
}
Quaternion Concatenate( const Quaternion& a, const Quaternion& b ) {
	vec3 selfv( b.i,b.j,b.k ),
		 othev( a.i,a.j,a.k ),
		 fin = othev * b.w + selfv * a.w + Cross( selfv,othev );
	return Quaternion( fin.x,fin.y,fin.z,b.w*a.w - Dot( selfv,othev ) );
}
Quaternion Integrate( const Quaternion& a, vec3 b, float32 c) {
	float32 vmag = Length(b), w, pass;
	
	if ( pow(vmag,4) / 24. < 0.0000001 ) {
		w = 1. - vmag * vmag / 2.;
		pass = 1. - vmag * vmag / 6.;
	} else {
		w = cos( vmag );
		pass = sin( vmag ) / vmag;
	}
	
	b *= pass;
	Quaternion dq( b.x,b.y,b.z,w );
	
	return Concatenate( dq,a );
}
Quaternion Integrate( const Quaternion& a, const Quaternion& b, float32 c ) {
	return Integrate( a,toAxisAngle(b).simplify(),c );
}
Quaternion Product( const Quaternion& a, const Quaternion& b ) {
	return Quaternion( 	a.w*b.i + a.i*b.w + a.j*b.k - a.k*b.j,
					   	a.w*b.j - a.i*b.k + a.j*b.w + a.k*b.i,
					   	a.w*b.k + a.i*b.j - a.j*b.i + a.k*b.w,
					   	a.w*b.w - a.i*b.i - a.j*b.j - a.k*b.k  );
}

ostream& operator<< ( ostream& out, const Quaternion& q ) {
	out << "( " << q.w << " + " << q.i << "i + " << q.j << "j + " << q.k << "k )";
	return out;
}

} }
