#include "core/transform.hpp"

namespace core {
	void transform3_t::__calculate() {
		if ( _change_flag != 0 ) {
			_change_flag = 0;
			_value = core::translate4( _position ) *
					 core::expand4( core::toMatrix(_rotation) ) *
					 core::translate4( -_pivot ) *
					 core::scale4( _scale );
		}
	}

	transform3_t::transform3_t() :
		_value(mat4::identity()) {
	}
	transform3_t::transform3_t(core::vec3 pos) :
		_change_flag(1),
		_position(pos) {
		__calculate();
	}
	transform3_t::transform3_t(core::quaternion_t rot) :
		_change_flag(1),
		_rotation(rot) {
		__calculate();
	}
	transform3_t::transform3_t(core::scale3_t scl) :
		_change_flag(1),
		_scale(scl) {
		__calculate();
	}
	transform3_t::transform3_t(core::vec3 pos, core::quaternion_t rot) :
		_change_flag(1),
		_position(pos),
		_rotation(rot) {
		__calculate();
	}
	transform3_t::transform3_t(core::vec3 pos, core::scale3_t scl) :
		_change_flag(1),
		_position(pos),
		_scale(scl) {
		__calculate();
	}
	transform3_t::transform3_t(core::quaternion_t rot, core::scale3_t scl) :
		_change_flag(1),
		_rotation(rot), _scale(scl) {
		__calculate();
	}
	transform3_t::transform3_t(core::vec3 pos, core::quaternion_t rot, core::scale3_t scl) :
		_change_flag(1),
		_position(pos),
		_rotation(rot),
		_scale(scl) {
		__calculate();
	}

	const core::vec3& transform3_t::position() const {
		return _position;
	}
	const core::vec3& transform3_t::pivotPoint() const {
		return _pivot;
	}
	const core::quaternion_t& transform3_t::rotation() const {
		return _rotation;
	}
	const core::scale3_t& transform3_t::scale() const {
		return _scale;
	}

	void transform3_t::position(const core::vec3& pos) {
		_change_flag |= 0x1;
		_position = pos;
	}
	void transform3_t::pivotPoint(const core::vec3& piv) {
		_change_flag |= 0x2;
		_pivot = piv;
	}
	void transform3_t::rotation(const core::quaternion_t& rot) {
		_change_flag |= 0x4;
		_rotation = rot;
	}
	void transform3_t::scale(const core::scale3_t& scl) {
		_change_flag |= 0x8;
		_scale = scl;
	}

	const core::mat4& transform3_t::transform() {
		__calculate();
		return _value;
	}
	transform3_t::operator core::mat4() {
		__calculate();
		return _value;
	}
}