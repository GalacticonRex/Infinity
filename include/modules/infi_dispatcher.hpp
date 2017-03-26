#ifndef __INFI_DISPTACHER_HPP__
#define __INFI_DISPTACHER_HPP__

#include "threads/infi_event_queue.hpp"

namespace Infinity {

	template<uint32 Code, typename State>
	struct infi_dispatcher_t {
	private:
		infi_event_queue_t& _queue;
		
	public:
		infi_dispatcher_t(infi_event_queue_t& q)
			: _queue(q) { ; }

		static State& resolve(const infi_event_queue_t::message& msg) {
			return *((State*)msg.data);
		}

		State& operator()(const infi_event_queue_t::message& msg) {
			return *((State*)msg.data);
		}

		void operator()(const State& st) {
			State& allocd = _queue.template push<State>(st);
			_queue.write({Code,&allocd});
		}

		void operator()(infi_time_stream_t& ts, float64 sec, const State& st) {
			State& allocd = _queue.template push<State>(st);
			_queue.write(ts, sec, {Code,&allocd});
		}
	};

}

#endif//__INFI_DISPTACHER_HPP__