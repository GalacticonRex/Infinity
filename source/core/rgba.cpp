#include "core/rgba.hpp"
#include "core/hsv.hpp"

namespace core {
	void rgba_t::__r(float32 r) {
		x = std::max( 0.0f, std::min( 1.0f, r ) );
	}
	void rgba_t::__g(float32 g) {
		y = std::max( 0.0f, std::min( 1.0f, g ) );
	}
	void rgba_t::__b(float32 b) {
		z = std::max( 0.0f, std::min( 1.0f, b ) );
	}
	void rgba_t::__a(float32 a) {
		w = std::max( 0.0f, std::min( 1.0f, a ) );
	}

	rgba_t::rgba_t() : vec4(0,0,0,1) { ; }
	rgba_t::rgba_t(const std::string& html) {
		
	}
	rgba_t::rgba_t(float32 r, float32 g, float32 b) {
		__r(r);
		__g(g);
		__b(b);
		__a(1.0f);
	}
	rgba_t::rgba_t(float32 r, float32 g, float32 b, float32 a) {
		__r(r);
		__g(g);
		__b(b);
		__a(a);	
	}

	float32 rgba_t::r() const {
		return x;
	}
	float32 rgba_t::g() const {
		return y;	
	}
	float32 rgba_t::b() const {
		return z;
	}
	float32 rgba_t::a() const {
		return w;
	}

	void rgba_t::r(float32 r) {
		__r(r);
	}
	void rgba_t::g(float32 g) {
		__g(g);
	}
	void rgba_t::b(float32 b) {
		__b(b);
	}
	void rgba_t::a(float32 a) {
		__a(a);
	}

	void rgba_t::rgb(float32 r, float32 g, float32 b) {
		__r(r);
		__g(g);
		__b(b);
	}

	void rgba_t::rgba(float32 r, float32 g, float32 b, float32 a) {
		__r(r);
		__g(g);
		__b(b);
		__a(a);
	}

	hsv_t rgba_t::toHSV() const {
		float32 h, s, v;
		float32 mmin, mmax, delta;

		if( x > y ) {
			if ( y > z ) { // x, y, z
				mmin = z;
				mmax = x;
				delta = mmax - mmin;
				h = ( y - z ) / delta;
			} else if ( x > z ) { // x, z, y
				mmin = y;
				mmax = x;
				delta = mmax - mmin;
				h = ( y - z ) / delta;
			} else { // z, x, y
				mmin = y;
				mmax = z;
				delta = mmax - mmin;
				h = 4 + ( x - y ) / delta;
			}
		} else {
			if ( z > y ) { // z, y, x
				mmin = x;
				mmax = z;
				delta = mmax - mmin;
				h = 4 + ( x - y ) / delta;
			} else if ( z > x ) { // y, z, x
				mmin = x;
				mmax = y;
				delta = mmax - mmin;
				h = 2 + ( z - x ) / delta;
			} else { // y, x, z
				mmin = z;
				mmax = y;
				delta = mmax - mmin;
				h = 2 + ( z - x ) / delta;
			}
		}

		v = mmax;
		if ( mmax != 0 ) {
			s = delta / mmax;
		} else {
			s = 0;
			h = -1;
			return hsv_t(h,s,v);
		}

		h *= MATH_PI / 3;
		while ( h < 0 )
			h += MATH_PI * 2;

		return hsv_t(h,s,v);
	}
}