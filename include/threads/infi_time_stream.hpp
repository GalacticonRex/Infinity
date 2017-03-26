#ifndef __INFI_TIME_STREAM_HPP__
#define __INFI_TIME_STREAM_HPP__

#include <atomic>
#include <mutex>
#include <condition_variable>

#include "base/error_log.hpp"
#include "base/types.hpp"
#include "base/time.hpp"
#include "threads/infi_thread_defs.hpp"
#include "threads/infi_trigger.hpp"

namespace Infinity {

	struct infi_time_stream_t : public infi_trigger_t{
	private:
		infi_trigger_t _scale_change;
		
		std::atomic<bool> _continue;
		std::condition_variable _condition;
		
		std::mutex _lock;

		std::atomic<float64> _scale;
		std::atomic<Time::Point> _current_global;
		std::atomic<float64> _current_local;

	public:
		infi_time_stream_t();
		infi_time_stream_t(float64);

		infi_time_stream_t& operator= ( float64 );
		float64 scale() const;
		operator float64() const;

		float64 localTime() const;

		float64 globalToLocal(Time::Point) const;
		Time::Point localToGlobal(float64) const;

		float64 lastTimeLocal() const;
		Time::Point lastTimeGlobal() const;

		void restart();

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

#endif//__INFI_TIME_STREAM_HPP__