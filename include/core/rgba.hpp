#ifndef __CORE_RGBA_HPP__
#define __CORE_RGBA_HPP__

#include "core/vector.hpp"

namespace core {

	struct rgba_t : public vec4 {
	private:
		void __r(float32);
		void __g(float32);
		void __b(float32);
		void __a(float32);

	public:
		rgba_t();
		rgba_t(const std::string&);
		rgba_t(float32 r, float32 g, float32 b);
		rgba_t(float32 r, float32 g, float32 b, float32 a);

		float32 r() const;
		float32 g() const;
		float32 b() const;
		float32 a() const;

		void r(float32);
		void g(float32);
		void b(float32);
		void a(float32);

		void rgb(float32, float32, float32);

		void rgba(float32, float32, float32, float32);

		hsv_t toHSV() const;
	};

}

#endif//__CORE_RGBA_HPP__