#ifndef __INFI_RATE_HPP__
#define __INFI_RATE_HPP__

#include "core/function/functions.hpp"
#include "components/infi_clock.hpp"

namespace Infinity {

	template<typename _T,
			 typename _Func,
			 typename _Rate = _T,
			 typename _Conv = _T>
	struct infi_rate_t {
	private:
		_Rate& _clock;
	public:
		_Func resolver;

		infi_rate_t(_Rate& clock, _Func f) :
			_clock(clock), resolver(f) { ; }


		_Rate& getRate() {
			return _clock;
		}
		const _Rate& getRate() const {
			return _clock;
		}

		operator _T() const {
			return _Conv(resolver(_clock));
		}
		_T get() const {
			return _Conv(resolver(_clock));
		}
	};

}

#endif//__INFI_RATE_HPP__