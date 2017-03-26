#include "core/quaternion.hpp"
#include "core/methods.hpp"
#include "core/convert.hpp"
#include "core/axis_angle.hpp"

namespace core {

namespace {
	using namespace std;
}

quaternion_t::quaternion_t()
	: i(0),j(0),k(0),w(1) { }
quaternion_t::quaternion_t(float32 i_,float32 j_,float32 k_,float32 w_)
	: i(i_),j(j_),k(k_),w(w_) { }

quaternion_t quaternion_t::operator+ () const { return *this; }
quaternion_t quaternion_t::operator- () const { return quaternion_t(-i,-j,-k,-w); }

const vec4& quaternion_t::asVector() const { return *((vec4*)this); }
quaternion_t quaternion_t::inverse() const {
	return quaternion_t( -i, -j, -k, w );
}

const quaternion_t& asQuaternion(const vec4& v) {
	return *((const quaternion_t*)(&v));
}

float32 Dot( const quaternion_t& a, const quaternion_t& b ) {
	return a.w*b.w + a.i*b.i + a.j*b.j + a.k*b.k;
}
quaternion_t Blend( const quaternion_t& a, const quaternion_t& b, float32 c ) {
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
quaternion_t Concatenate( const quaternion_t& a, const quaternion_t& b ) {
	vec3 selfv( b.i,b.j,b.k ),
		 othev( a.i,a.j,a.k ),
		 fin = othev * b.w + selfv * a.w + Cross( selfv,othev );
	return quaternion_t( fin.x,fin.y,fin.z,b.w*a.w - Dot( selfv,othev ) );
}
quaternion_t Integrate( const quaternion_t& a, vec3 b, float32 c) {
	b /= 2.0f;

	float32 vmag = Length(b), w, pass;

	if ( pow(vmag,4) / 24. < 0.0000001 ) {
		w = 1. - vmag * vmag / 2.;
		pass = 1. - vmag * vmag / 6.;
	} else {
		w = cos( vmag );
		pass = sin( vmag ) / vmag;
	}

	b *= pass;
	quaternion_t dq( b.x,b.y,b.z,w );

	return Concatenate( dq,a );
}
quaternion_t Integrate( const quaternion_t& a, const quaternion_t& b, float32 c ) {
	return Integrate( a,toAxisAngle(b).simplify(),c );
}
quaternion_t Product( const quaternion_t& a, const quaternion_t& b ) {
	return quaternion_t(a.w*b.i + a.i*b.w + a.j*b.k - a.k*b.j,
					   	a.w*b.j - a.i*b.k + a.j*b.w + a.k*b.i,
					   	a.w*b.k + a.i*b.j - a.j*b.i + a.k*b.w,
					   	a.w*b.w - a.i*b.i - a.j*b.j - a.k*b.k  );
}

ostream& operator<< ( ostream& out, const quaternion_t& q ) {
	out << "( " << q.w << " + " << q.i << "i + " << q.j << "j + " << q.k << "k )";
	return out;
}

}
