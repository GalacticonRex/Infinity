#ifndef __INFI_EVENT_CLOCK_HPP__
#define __INFI_EVENT_CLOCK_HPP__

#include <atomic>
#include <mutex>
#include <condition_variable>

#include "base/error_log.hpp"
#include "base/types.hpp"
#include "base/time.hpp"
#include "components/infi_clock.hpp"
#include "threads/infi_thread_defs.hpp"
#include "threads/infi_event_trigger.hpp"

namespace Infinity {

	struct infi_event_clock_t : public infi_clock_t, public infi_event_trigger_t<infi_event_clock_t*> {
	private:
		std::atomic<bool> _continue;
		std::condition_variable _condition;
		
		std::mutex _lock;

	public:
		infi_event_clock_t();
		infi_event_clock_t(float64 scale);
		
		void reset();
		void interrupt();

		// wait for a single cycle
		// returns the amount of time left to wait
		// triggered when time scale changes
		// returns -1 when interrupt is triggered
		float64 wait(float64);
		float64 wait(std::condition_variable&, float64);

		// wait until the amount of time has passed
		bool wait_for(float64);
	};

}

#endif//__INFI_EVENT_CLOCK_HPP__