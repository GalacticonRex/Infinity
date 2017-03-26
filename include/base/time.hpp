#ifndef __TIME_HPP__
#define __TIME_HPP__

#include <chrono>
#include <mutex>

#include "base/types.hpp"

namespace Time {
	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::duration<float64> Frame;
	typedef std::chrono::time_point<std::chrono::high_resolution_clock, Frame> Point;
	typedef std::lock_guard<std::mutex> LockGuard;
	typedef std::unique_lock<std::mutex> UniqueLock;

	inline Time::Point Now() { return Clock::now(); }
}

#endif//__TIME_HPP__