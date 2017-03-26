#include "core/polar.hpp"

namespace core {

	polar_t::polar_t() { ; }
	polar_t::polar_t(float32 r, float32 a) :
		vec2(r,a) { ; }

	float32 polar_t::radius() const {
		return x;
	}
	float32 polar_t::angle() const {
		return y;	
	}
	
	void polar_t::radius(float32 r) {
		x = r;
	}
	void polar_t::angle(float32 a) {
		y = a;
	}

	vec2 polar_t::toCartesian() const {
		return vec2( x * std::cos( y ), x * std::sin( y ) );
	}

	polar_t polar_t::toPolar( const core::vec2& v ) {
		return polar_t( std::sqrt( v.x*v.x + v.y*v.y ), std::atan2( v.y, v.x ) );
	}

}