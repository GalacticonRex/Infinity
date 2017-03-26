#ifndef __INFI_MODULE_HPP__
#define __INFI_MODULE_HPP__

#include <thread>
#include "base/structure.hpp"
#include "threads/infi_event_queue.hpp"
#include "modules/infi_module_defs.hpp"
#include "modules/infi_dispatcher.hpp"
#include "modules/infi_interpreter.hpp"
#include "modules/infi_error_handler.hpp"

#include "components/infi_named_object.hpp"

namespace Infinity {

	struct infi_module_base_t : infi_named_object_t, does_not_copy {
	protected:
		infi_error_handler_t& _error;
		infi_event_queue_t _queue;
		infi_time_stream_t _ts;

	public:
		infi_module_base_t(const std::string&, infi_error_handler_t&);
		infi_event_queue_t& exposeQueue();

		template<Error::Fatality _Fatal>
		bool handleError( Error::message<_Fatal>& e ) {
			return _error.handle(*this, e);
		}
	};

	template<typename... _Elems>
	struct infi_module_t : infi_module_base_t {
	private:
		infi_interpreter_t<_Elems...>* _process;

	public:
		template<std::size_t _N>
		using input_type = typename std::tuple_element<_N-1, std::tuple<_Elems...>>::type;

		infi_module_t(const std::string& str, infi_error_handler_t& hnd) :
			infi_module_base_t(str, hnd),
			_process(NULL) { ; }

		void interpreter(infi_interpreter_t<_Elems...>& proc) {
			_process = &proc;
		}
		template<std::size_t _N>
		infi_dispatcher_t<_N, input_type<_N>> dispatcher() {
			return infi_dispatcher_t<_N, input_type<_N>>(exposeQueue());
		}

		void run() {
			if ( _process == NULL )
				Error::send<Error::Fatality::Thread>(
					Error::Type::NullDeref,
					"Cannot start module %s, no message interpreter in place!",
					name().c_str()
				);

			while (true) {
				try {
					infi_event_queue_t::message msg;
					while ((msg=_queue.read()).code != 0) {
						 _process -> interpret(_queue, msg);
					}
					break;
				} catch(Error::message<Error::Fatality::Fatal> e) {
					if ( !handleError(e) )
						break;
				} catch(Error::message<Error::Fatality::Thread> e) {
					if ( !handleError(e) )
						break;
				} catch(Error::message<Error::Fatality::Method> e) {
					if ( !handleError(e) )
						break;
				} catch(Error::message<Error::Fatality::Warning> e) {
					if ( !handleError(e) )
						break;
				}
			}
		}
	};

}

#endif//__INFI_MODULE_HPP__