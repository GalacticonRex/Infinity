#ifndef __INFI_DISPTACH_TERMINATE_HPP__
#define __INFI_DISPTACH_TERMINATE_HPP__

#include "modules/infi_module.hpp"
#include "threads/infi_event_queue.hpp"

namespace Infinity {

	struct infi_dispatch_terminate_t {
	private:
		infi_event_queue_t& _queue;
	public:
		infi_dispatch_terminate_t(infi_module_base_t& m)
			: _queue(m.exposeQueue()) { ; }
			
		void operator()() {
			_queue.write({0,NULL});
		}
	};

}

#endif//__INFI_DISPTACH_TERMINATE_HPP__