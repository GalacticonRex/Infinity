#ifndef __CORE_CONSTANT_HPP__
#define __CORE_CONSTANT_HPP__

#include "core/function/resolvable.hpp"

namespace core {

	template<typename _T,
			 typename _Value = _T,
			 typename _Conv = _T>
	struct constant : resolvable<_T> {
	private:
		const _Value _value;

	public:
		constant(_Value value) : _value(_Value(value)) { ; }

		_T operator()(_T input) const {
			return _Conv(_value);
		}
	};

}

#endif//__CORE_CONSTANT_HPP__