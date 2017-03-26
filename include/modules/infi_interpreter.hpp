#ifndef __INFI_INTEPRETER_HPP__
#define __INFI_INTEPRETER_HPP__

#include <tuple>
#include "modules/infi_module_defs.hpp"
#include "threads/infi_event_queue.hpp"

namespace Infinity {

	template<typename _T>
	struct infi_process_message_t {
		virtual void interpret(_T&) = 0;
	};

	template<typename... _Elems>
	struct infi_interpreter_t {
	private:
		template<std::size_t _N>
		using __input__ = typename std::tuple_element<_N, std::tuple<_Elems...>>;

		template<std::size_t _N>
		using __type__ = typename std::tuple_element<_N, std::tuple<_Elems...>>::type;

		std::tuple<infi_process_message_t<_Elems>*...> _processes;
		
	public:
		infi_interpreter_t(std::tuple<infi_process_message_t<_Elems>*...> proc) :
			_processes(proc) { ; }

		template<uint32 _Code>
		void process(infi_event_queue_t& q, __type__<_Code>& d) {
			infi_process_message_t<__type__<_Code>>* proc = std::get<_Code>(_processes);	
			proc -> interpret(d);
		}

		template<uint32 _Code = sizeof...(_Elems)>
		void interpret(infi_event_queue_t& q, const infi_event_queue_t::message& msg) {
			constexpr uint32 code_value = _Code - 1;
			if ( msg.code == _Code ) {
				__type__<code_value>* data = (__type__<code_value>*)msg.data;
				process<code_value>(q, *data);
				q.pop(data);
			} else {
				interpret<code_value>(q, msg);
			}
		}
	};

	/*template<typename... _Elems> template<>
	void infi_interpreter_t<_Elems...>::interpret<0>(infi_event_queue_t&, const infi_event_queue_t::message& code) {
		Error::send<Error::Fatality::Thread>(
			Error::Type::Index,
			"Cannot process message with index %d",
			msg.code
		);
	}*/

}

#endif//__INFI_INTEPRETER_HPP__