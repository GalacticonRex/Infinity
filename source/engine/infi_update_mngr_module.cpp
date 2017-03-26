#include "engine/updatemngr/infi_update_mngr_module.hpp"
#include "engine/updatemngr/infi_update_mngr_recv.hpp"
#include "engine/updatemngr/infi_update_mngr_interpreter.hpp"
#include "engine/infi_root_module.hpp"
#include "engine/infi_controller.hpp"

namespace Infinity {

	template<> template<>
	void infi_update_mngr_module_t::interpreter::interpret<0>(infi_event_queue_t&, const infi_event_queue_t::message& msg) {
		Error::send<Error::Fatality::Thread>(
			Error::Type::Index,
			"Cannot process message with index %d",
			msg.code
		);
	}

	void infi_update_mngr_module_t::run(infi_controller_t& ctrl,
										module& mod,
										infi_error_handler_t& err,
										uint32 count,
										infi_update_mngr_module_t::extension& ext,
										infi_update_mngr_module_t::threadComplete& thr) {
		infi_update_mngr_interpreter_t updint( ctrl, err, count, ext, thr );
		mod.interpreter(updint);
		mod.run();
	}

	infi_update_mngr_reciever_t::infi_update_mngr_reciever_t(infi_update_mngr_module_t::module& mod) :
		extension(mod.dispatcher<1>()),
		threadComplete(mod.dispatcher<2>()),
		terminate(mod) { ; }

	infi_update_mngr_interpreter_t::infi_update_mngr_interpreter_t(	infi_controller_t& ctrl,
																	infi_error_handler_t& err,
																	uint32 thread_count,
																	infi_update_mngr_module_t::extension& ext,
																	infi_update_mngr_module_t::threadComplete& thr ) :
		infi_update_mngr_module_t::interpreter(std::make_tuple(&_extension_added, &_thread_complete)),
		_threads(thread_count),
		_ctrl(ctrl),
		_ext(ext),
		_pool(thr),
		_extension_added(*this),
		_thread_complete(*this) {
		for ( uint32 i=0;i<_threads.size();i++ ) {
			std::stringstream str;
			str << "Thread " << i;
			_threads[i] = new infi_operator_thread_t(str.str(), ctrl, thr, err);
		}
	}

	infi_update_mngr_interpreter_t::~infi_update_mngr_interpreter_t() {
		for ( uint32 i=0;i<_threads.size();i++ ) {
			delete _threads[i];
		}
	}

	infi_update_mngr_interpreter_t::__extension_added__::__extension_added__(infi_update_mngr_interpreter_t& i) : _src(i) { ; }
	void infi_update_mngr_interpreter_t::__extension_added__::interpret(infi_update_mngr_module_t::Function& func) {
		if ( !_src._queue_threads.empty() ) {
			(*_src._queue_threads.front())(infi_update_mngr_module_t::Function(func));
			_src._queue_threads.pop();
		} else {
			_src._queue_extensions.push(func);
		}
	}
	infi_update_mngr_interpreter_t::__thread_complete__::__thread_complete__(infi_update_mngr_interpreter_t& i) : _src(i) { ; }
	void infi_update_mngr_interpreter_t::__thread_complete__::interpret(infi_operator_thread_t*& thr) {
		if ( !_src._queue_extensions.empty() ) {
			(*thr)(infi_update_mngr_module_t::Function(_src._queue_extensions.front()));
			_src._queue_extensions.pop();
		} else {
			_src._queue_threads.push(thr);
		}
	}
	
}
