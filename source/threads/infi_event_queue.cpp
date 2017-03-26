#include <iostream>
#include "threads/infi_event_queue.hpp"

namespace Infinity {

	std::ostream& operator<< (std::ostream& ostr, const infi_event_queue_t::message_t& msg) {
		ostr << "[" << msg.data().code << ", " << msg.data().data << "]";
		return ostr;
	}

	bool infi_event_queue_t::message_t::operator<(const infi_event_queue_t::message_t& other) const {
		return (other._start_stream + other._time < _start_stream + _time);
	}

	infi_event_queue_t::message_t::message_t() :
		_start_global(Time::Now()),
		_start_stream(0),
		_time(0.0),
		_data({0,NULL}) { ; }

	infi_event_queue_t::message_t::message_t(const infi_time_stream_t& str, float64 w, message d) :
		_start_global(Time::Now()),
		_start_stream(str.globalToLocal(_start_global)),
		_time(w),
		_data(d) { ; }

	Time::Point infi_event_queue_t::message_t::startGlobal() const {
		return _start_global;
	}
	float64 infi_event_queue_t::message_t::startLocal() const {
		return _start_stream;
	}
	float64 infi_event_queue_t::message_t::wait() const {
		return _time;
	}
	infi_event_queue_t::message infi_event_queue_t::message_t::data() const {
		return _data;
	}

	bool infi_event_queue_t::stream_ref_t::__sort_streams(infi_event_queue_t::stream_ref_t* const& A, infi_event_queue_t::stream_ref_t* const& B) {
		return (A->_logged_value < B->_logged_value);
	}

	infi_event_queue_t::stream_ref_t::stream_ref_t(const infi_time_stream_t* str) :
		_source(str),
		_index(-1),
		_logged_value(Time::Point::max()) { ; }

	void infi_event_queue_t::stream_ref_t::rebind(const infi_time_stream_t* str) {
		_source = str;
	}
	const infi_time_stream_t* infi_event_queue_t::stream_ref_t::stream() const {
		return _source;
	}
	Time::Point infi_event_queue_t::stream_ref_t::waitUntil() const {
		return _logged_value;
	}
	uint32 infi_event_queue_t::stream_ref_t::remaining() const {
		return _messages.size();
	}
	void infi_event_queue_t::stream_ref_t::move(uint32 x) {
		_index = x;
	}
	uint32 infi_event_queue_t::stream_ref_t::index() const {
		return _index;
	}
	void infi_event_queue_t::stream_ref_t::push(message_t msg) {
		if ( _messages.size() == 0 || msg < _messages.top() ) {
			_messages.push(msg);
			calculateValue();
		} else
			_messages.push(msg);
	}
	infi_event_queue_t::message_t infi_event_queue_t::stream_ref_t::pop() {
		if ( _messages.empty() )
			return message_t();

		message_t msg = _messages.top();
		_messages.pop();

		calculateValue();

		return msg;
	}
	infi_event_queue_t::message_t infi_event_queue_t::stream_ref_t::peek() const {
		if ( _messages.empty() )
			return message_t();

		return _messages.top();
	}

	void infi_event_queue_t::stream_ref_t::calculateValue() {
		if ( _messages.empty() || _source->scale() == 0 ) {
			_logged_value = Time::Point::max();
		} else {
			const message_t& top = _messages.top();
			float64 last = _source->lastTimeLocal();
			if ( top.startLocal() >= last ) {
				_logged_value = top.startGlobal() + Time::Frame(top.wait() / _source->scale());
			} else {
				float64 dif = last - top.startLocal();
				float64 rem = top.wait() - dif;
				_logged_value = _source->lastTimeGlobal() + Time::Frame(rem / _source->scale());
			}
		}
	}

	void infi_event_queue_t::stream_heap_t::_sinkDown(uint32 x) {
		while ( true ) {
			uint32 l = ((x<<1)+1);
			uint32 r = ((x+1)<<1);

			bool gol = ( r >= _data.size() || infi_event_queue_t::stream_ref_t::__sort_streams( _data[l], _data[r] ) );
			uint32 f = (gol) ? l : r;

			if ( f < _data.size() && infi_event_queue_t::stream_ref_t::__sort_streams( _data[f], _data[x] ) ) {
				_data[x]->move(f);
				_data[f]->move(x);

				infi_event_queue_t::stream_ref_t* tmp = _data[x];
				_data[x] = _data[f];
				_data[f] = tmp;

				x = f;
			} else return;
		}
	}
	void infi_event_queue_t::stream_heap_t::_bubbleUp(uint32 x) {
		uint32 p;
		while ( x != 0 && infi_event_queue_t::stream_ref_t::__sort_streams( _data[x], _data[(p=((x-1)>>1))] ) ) {
			_data[x]->move(p);
			_data[p]->move(x);

			infi_event_queue_t::stream_ref_t* tmp = _data[x];
			_data[x] = _data[p];
			_data[p] = tmp;

			x = p;
		}
	}
	void infi_event_queue_t::stream_heap_t::_verify(infi_event_queue_t::stream_ref_t* r) {
		infi_event_queue_t::stream_ref_t* top = _data[0];
		if ( r == top ) { 
			_sinkDown(r->index());
		} else {
			_data[r->index()] = top;
			_data[0] = r;

			top->move(r->index());
			r->move(0);

			_sinkDown(r->index());
			_bubbleUp(top->index());
		}
		if ( _data[0] != top ) {
			_condition.notify_all();
		}
	}
	void infi_event_queue_t::stream_heap_t::_push(infi_event_queue_t::stream_ref_t* r) {
		r->move(_data.size());
		_data.push_back(r);
		_bubbleUp(r->index());
	}
	const infi_event_queue_t::stream_ref_t* infi_event_queue_t::stream_heap_t::_peek() const {
		if ( _data.size() == 0 )
			return NULL;
		return _data[0];
	}
	infi_event_queue_t::stream_ref_t* infi_event_queue_t::stream_heap_t::_pop() {
		if ( _data.size() == 0 )
			return NULL;

		infi_event_queue_t::stream_ref_t* ret = _data[0];
		infi_event_queue_t::stream_ref_t* last = _data.back();
		_data.pop_back();

		last->move(0);
		if ( _data.empty() ) {
			_data.push_back(last);
		} else {
			_data[0] = last;
			_sinkDown(0);
		}

		return ret;
	}

	infi_event_queue_t::stream_ref_t* infi_event_queue_t::stream_heap_t::_get(infi_time_stream_t* str) {
		stream_ref_t*& msgs = _mapping[str];
		if ( msgs == NULL ) {
			if ( _available.empty() ) {
				msgs = new stream_ref_t(str);
				(*this).when(*str);
			} else {
				msgs = _available.top();
				_available.pop();
				msgs->rebind(str);
			}
			this->_push(msgs);
		}
		return msgs;
	}

	infi_event_queue_t::stream_heap_t::stream_heap_t() {
		std::lock_guard<std::mutex> lk(_lock);
	}
	infi_event_queue_t::stream_heap_t::~stream_heap_t() {
		std::lock_guard<std::mutex> lk(_lock);
	}

	infi_event_queue_t::message_t infi_event_queue_t::stream_heap_t::top() {
		std::lock_guard<std::mutex> lk(_lock);
		const stream_ref_t* str = this->_peek();
		return str->peek();
	}
	void infi_event_queue_t::stream_heap_t::pushImmediate(message msg) {
		std::lock_guard<std::mutex> lk(_lock);
		_immediate.push(msg);
		_condition.notify_all();
	}
	void infi_event_queue_t::stream_heap_t::push(infi_time_stream_t* str, message_t msg) {
		std::lock_guard<std::mutex> lk(_lock);

		stream_ref_t* msgs = this->_get(str);
		msgs->push(msg);
		this->_verify(msgs);

		_condition.notify_all();
	}
	infi_event_queue_t::message infi_event_queue_t::stream_heap_t::pop() {
		std::unique_lock<std::mutex> lk(_lock);

		Time::Point w;
		do {
			const stream_ref_t* str;
			for( ;; ) {
				str = this->_peek();
				if ( str == NULL && _immediate.empty() )
					_condition.wait(lk);
				else
					break;
			}

			if ( (str == NULL || (w=str->waitUntil()) > Time::Now()) && !_immediate.empty() ) {
				infi_event_queue_t::message msg = _immediate.front();
				_immediate.pop();
				return msg;
			}

		} while ( _condition.wait_until(lk, w) != std::cv_status::timeout );

		stream_ref_t* str = this->_pop();
		message_t msg = str->pop();

		if ( str->remaining() == 0 ) {
			_available.push(str);
			_mapping[str->stream()] = NULL;
		} else {
			str->calculateValue();
			this->_push(str);
		}

		return msg.data();
	}

	void infi_event_queue_t::stream_heap_t::Triggered(infi_trigger_t* sender, bool sig, void* data) {
		if ( sig ) {
			std::lock_guard<std::mutex> lk(_lock);
			infi_time_stream_t* ts = (infi_time_stream_t*)data;
			stream_ref_t* sr = _mapping[ts];
			if ( sr != NULL ) {
				sr->calculateValue();
				this->_verify(sr);
			}
		}
	}

	infi_event_queue_t::infi_event_queue_t() { ; }
	infi_event_queue_t::~infi_event_queue_t() { ; }
	void infi_event_queue_t::write(infi_event_queue_t::message msg) {
		_streams.pushImmediate(msg);
	}
	void infi_event_queue_t::write(infi_time_stream_t& str, float64 w, infi_event_queue_t::message msg) {
		_streams.push(&str, message_t(str,w,msg));
	}
	infi_event_queue_t::message infi_event_queue_t::read() {
		infi_event_queue_t::message msg = _streams.pop();
		return msg;
	}

}