#ifndef __INFI_EVENT_RATE_HPP__
#define __INFI_EVENT_RATE_HPP__

#include "core/function/constant.hpp"
#include "threads/infi_trigger.hpp"

namespace Infinity {
	
	template<typename _T,
			 typename _RateActive = core::constant<_T>,
			 typename _RateInactive = core::constant<_T>,
			 typename _Conv = _T>
	struct infi_event_rate_t : core::resolvable<_T> {
	private:
		_RateActive _rate_active;
		_RateInactive _rate_inactive;

	public:
		infi_trigger_t event;

		infi_event_rate_t(_RateActive ra, _RateInactive ri) : 
			_rate_active(ra),
			_rate_inactive(ri) { ; }

		_T operator()(_T input) const {
			if ( event ) {
				return _Conv(_rate_active(input));
			} else {
				return _Conv(_rate_inactive(input));
			}
		}
	};

}

#endif//__INFI_EVENT_RATE_HPP__