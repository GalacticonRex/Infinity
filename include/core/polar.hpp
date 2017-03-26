#ifndef __CORE_POLAR_HPP__
#define __CORE_POLAR_HPP__

#include "core/vector.hpp"

namespace core {

	struct polar_t : public vec2 {
	public:
		polar_t();
		polar_t(float32 r, float32 a);

		float32 radius() const;
		float32 angle() const;
		
		void radius(float32);
		void angle(float32);

		vec2 toCartesian() const;

		static polar_t toPolar(const vec2&);
	};

}

#endif//__CORE_POLAR_HPP__
