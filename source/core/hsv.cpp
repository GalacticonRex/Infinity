#include "core/hsv.hpp"
#include "core/rgba.hpp"

namespace core {

	void hsv_t::__h(float32 h) {
		x = std::max( 0.0f, std::min( 1.0f, h ) );
	}
	void hsv_t::__s(float32 s) {
		y = std::max( 0.0f, std::min( 1.0f, s ) );
	}
	void hsv_t::__v(float32 v) {
		z = std::max( 0.0f, std::min( 1.0f, v ) );
	}

	hsv_t::hsv_t(float32 h, float32 s, float32 v) {
		__h(h);
		__s(s);
		__v(v);
	}

	float32 hsv_t::hue() const {
		return x;
	}
	float32 hsv_t::saturation() const {
		return y;
	}
	float32 hsv_t::value() const {
		return z;
	}

	void hsv_t::h(float32 h) {
		__h(h);
	}
	void hsv_t::s(float32 s) {
		__s(s);
	}
	void hsv_t::v(float32 v) {
		__v(v);
	}

	void hsv_t::hsv(float32 h, float32 s, float32 v) {
		__h(h);
		__s(s);
		__v(v);
	}

	rgba_t hsv_t::toRGB() const {
		int32 i;
		float32 h = x;
		float32 f, p, q, t;
		if ( y == 0 )
			return rgba_t( z,z,z );

		while ( h < 0 )
			h += MATH_PI * 2;
		while ( h >= MATH_PI * 2 )
			h -= MATH_PI * 2;

		h *= 3 / MATH_PI;

		i = std::floor( h );
		f = h - i;
		p = z * ( 1 - y );
		q = z * ( 1 - y * f );
		t = z * ( 1 - y * ( 1 - f ) );

		switch( i ) {
			case 0:
				return rgba_t( z, t, p );
				break;
			case 1:
				return rgba_t( q, z, p );
				break;
			case 2:
				return rgba_t( p, z, t );
				break;
			case 3:
				return rgba_t( p, q, z );
				break;
			case 4:
				return rgba_t( t, p, z );
				break;
			case 5:
				return rgba_t( z, p, q );
				break;
			default:
				return rgba_t();
				break;
		}
	}

}