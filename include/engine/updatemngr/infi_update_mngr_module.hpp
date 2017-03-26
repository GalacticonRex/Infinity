#ifndef __INFI_UPDATE_MANAGER_MODULE_HPP__
#define __INFI_UPDATE_MANAGER_MODULE_HPP__

#include "engine/infi_engine_defs.hpp"
#include "modules/infi_module_defs.hpp"
#include "modules/infi_module.hpp"
#include "modules/infi_interpreter.hpp"
#include "modules/infi_dispatcher.hpp"
#include "threads/infi_typed_allocator.hpp"
#include "components/infi_component_defs.hpp"

namespace Infinity {

	struct infi_update_mngr_module_t {
		typedef std::function<void(infi_controller_t&)> Function;
		typedef infi_module_t<Function, infi_operator_thread_t*> module;
		typedef infi_interpreter_t<Function, infi_operator_thread_t*> interpreter;

		static const uint32 Extension = 1;
		static const uint32 ThreadComplete = 2;

		typedef infi_dispatcher_t<infi_update_mngr_module_t::Extension, Function> extension;
		typedef infi_dispatcher_t<infi_update_mngr_module_t::ThreadComplete, infi_operator_thread_t*> threadComplete;

		static void run(infi_controller_t&,
						module&,
						infi_error_handler_t&,
						uint32,
						extension&,
						threadComplete&);
	};

	template<> template<>
	void infi_update_mngr_module_t::interpreter::interpret<0>(infi_event_queue_t&, const infi_event_queue_t::message&);
	
}

#endif//__INFI_WINDOW_MANAGER_THREAD_HPP__