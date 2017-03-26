#ifndef __INFI_TRANSFORM_HPP__
#define __INFI_TRANSFORM_HPP__

#include "core/vector.hpp"
#include "core/matrix.hpp"
#include "core/convert.hpp"
#include "core/scale.hpp"

namespace core {

	struct transform3_t {
	private:
		uint32 _change_flag;
		vec3 _position;
		vec3 _pivot;
		quaternion_t _rotation;
		scale3_t _scale;
		mat4 _value;

		void __calculate();

	public:
		transform3_t(); // none
		transform3_t(vec3 p);  // position
		transform3_t(quaternion_t r);  // rotation
		transform3_t(scale3_t s);  // scale
		transform3_t(vec3 p, quaternion_t r);  // position, rotation
		transform3_t(vec3 p, scale3_t s);  // position, scale
		transform3_t(quaternion_t r, scale3_t s);  // rotation, scale
		transform3_t(vec3 p, quaternion_t r, scale3_t s); //  // position, rotation, scale

		const vec3& position() const;
		const vec3& pivotPoint() const;
		const quaternion_t& rotation() const;
		const scale3_t& scale() const;

		void position(const vec3&);
		void pivotPoint(const vec3&);
		void rotation(const quaternion_t&);
		void scale(const scale3_t&);

		const core::mat4& transform();
		operator mat4();
	};

}

#endif//__INFI_TRANSFORM_HPP__