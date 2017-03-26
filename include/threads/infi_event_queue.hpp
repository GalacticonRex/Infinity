#ifndef __INFI_EVENT_QUEUE_HPP__
#define __INFI_EVENT_QUEUE_HPP__

#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include "threads/infi_thread_defs.hpp"
#include "threads/infi_time_stream.hpp"
#include "threads/infi_generic_allocator.hpp"

namespace Infinity {

	struct infi_event_queue_t {
	public:
		struct message {
			uint32 code;
			void* data;
		};

		struct message_t {
		public:
			message_t();
			message_t(const infi_time_stream_t&, float64, message);

			bool operator<(const message_t&) const;

			Time::Point startGlobal() const;
			float64 startLocal() const;
			float64 wait() const;
			message data() const;

		private:
			Time::Point _start_global;
			float64 _start_stream;
			float64 _time;
			message _data;
		};
	private:
		struct stream_ref_t {
		public:
			static bool __sort_streams(stream_ref_t* const&, stream_ref_t* const&);

			stream_ref_t(const infi_time_stream_t*);
			void rebind(const infi_time_stream_t*);

			const infi_time_stream_t* stream() const;

			Time::Point waitUntil() const;
			uint32 remaining() const;
			uint32 index() const;
			message_t peek() const;

			void move(uint32);
			void push(message_t);
			message_t pop();

			void calculateValue();

		private:
			const infi_time_stream_t* _source;
			uint32 _index;
			std::priority_queue<message_t> _messages;
			Time::Point _logged_value;
		};

		struct stream_heap_t : public infi_trigger_t {
		public:
			stream_heap_t();
			~stream_heap_t();

			message_t top();

			void pushImmediate(message);
			void push(infi_time_stream_t*, message_t);
			message pop();

		private:
			void Triggered(infi_trigger_t* sender, bool sig, void* data);

			std::mutex _lock;
			std::condition_variable _condition;

			std::stack<stream_ref_t*> _available;
			std::unordered_map<const infi_time_stream_t*, stream_ref_t*> _mapping;
			std::vector<stream_ref_t*> _data;

			// messages that are requesting immediate processing
			std::queue<message> _immediate;

			stream_ref_t* _get(infi_time_stream_t*);
			void _verify(stream_ref_t*);
			void _push(stream_ref_t*);
			const stream_ref_t* _peek() const;
			stream_ref_t* _pop();

			void _sinkDown(uint32);
			void _bubbleUp(uint32);
		} _streams;

		infi_generic_allocator_t<4096,64> _alloc;

	public:
		infi_event_queue_t();
		~infi_event_queue_t();

		template<typename _T>
		_T& push(const _T& obj) {
			return _alloc.template alloc<_T>(obj);
		}
		template<typename _T>
		void pop(_T* obj) {
			_alloc.template dealloc<_T>(obj);
		}

		void write(message);
		void write(infi_time_stream_t&, float64, message);
		message read();
	};

	std::ostream& operator<< (std::ostream&, const infi_event_queue_t::message_t&);

}

#endif//__INFI_EVENT_QUEUE_HPP__