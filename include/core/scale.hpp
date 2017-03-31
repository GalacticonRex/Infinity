#ifndef __SCALE_3_HPP__
#define __SCALE_3_HPP__

#include "base/structure.hpp"

#include "core/vector.hpp"

namespace core {

	struct scale3_t : public vec3 {
		scale3_t() : vec3(1,1,1) { ; }
		scale3_t(float32 x) : vec3(x,1,1) { ; }
		scale3_t(float32 x, float32 y) : vec3(x,y,1) { ; }
		scale3_t(float32 x, float32 y, float32 z) : vec3(x,y,z) { ; }
		scale3_t(vec2 xy) : vec3(xy.x,xy.y,1) { ; }
		scale3_t(vec2 xy, float32 z) : vec3(xy.x,xy.y,z) { ; }
		scale3_t(float32 x, vec2 yz) : vec3(x,yz.x,yz.y) { ; }

		scale3_t& operator= (float32 xyz) {
			vec3::x = xyz;
			vec3::y = xyz;
			vec3::z = xyz;
			return *this;
		}
	};

}

#endif//__INFI_SCALE_HPP__