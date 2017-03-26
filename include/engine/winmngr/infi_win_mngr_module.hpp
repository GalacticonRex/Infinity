#ifndef __INFI_WINDOW_MANAGER_MODULE_HPP__
#define __INFI_WINDOW_MANAGER_MODULE_HPP__

#include "engine/infi_engine_defs.hpp"
#include "modules/infi_module_defs.hpp"
#include "modules/infi_module.hpp"
#include "modules/infi_interpreter.hpp"
#include "modules/infi_dispatcher.hpp"
#include "components/infi_component_defs.hpp"

namespace Infinity {

	struct infi_win_mngr_module_t {
		typedef infi_module_t<infi_window_t*, infi_window_t*, infi_renderable_t*> module;
		typedef infi_interpreter_t<infi_window_t*, infi_window_t*, infi_renderable_t*> interpreter;

		static const uint32 Refresh = 1;
		static const uint32 DestroyWindow = 2;
		static const uint32 BindRenderable = 3;

		typedef infi_dispatcher_t<infi_win_mngr_module_t::Refresh,infi_window_t*> refresh;
		typedef infi_dispatcher_t<infi_win_mngr_module_t::DestroyWindow,infi_window_t*> destroyWindow;
		typedef infi_dispatcher_t<infi_win_mngr_module_t::BindRenderable,infi_renderable_t*> bindRenderable;
	};

	template<> template<> 
	void infi_win_mngr_module_t::interpreter::interpret<0>(infi_event_queue_t&, const infi_event_queue_t::message&);
	
}

#endif//__INFI_WINDOW_MANAGER_THREAD_HPP__