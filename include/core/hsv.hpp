#ifndef __CORE_HUE_SAT_VAL_HPP__
#define __CORE_HUE_SAT_VAL_HPP__

#include "core/vector.hpp"

namespace core {

	struct hsv_t : public vec3 {
	private:
		void __h(float32);
		void __s(float32);
		void __v(float32);

	public:
		hsv_t(float32 h, float32 s, float32 v);

		float32 hue() const;
		float32 saturation() const;
		float32 value() const;

		void h(float32);
		void s(float32);
		void v(float32);

		void hsv(float32, float32, float32);

		rgba_t toRGB() const;
	};

}

#endif//__HUE_SAT_VAL_HPP__