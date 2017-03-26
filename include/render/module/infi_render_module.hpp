#ifndef __INFI_RENDER_MODULE_HPP__
#define __INFI_RENDER_MODULE_HPP__

#include <condition_variable>

#include "modules/infi_module_defs.hpp"
#include "modules/infi_interpreter.hpp"
#include "modules/infi_dispatcher.hpp"
#include "components/infi_window.hpp"
#include "engine/winmngr/infi_win_mngr_module.hpp"
#include "threads/infi_generic_queue.hpp"

namespace Infinity {
namespace Render {

	struct infi_render_module_t {
		typedef std::function<void(const infi_gl_t&, infi_gl_context_controller_t&, infi_default_queue_t&)> Function;

		typedef infi_module_t<infi_gl_queue_t*, infi_window_t*, infi_window_t*> module;
		typedef infi_interpreter_t<infi_gl_queue_t*, infi_window_t*, infi_window_t*> interpreter;
		
		static void run(std::condition_variable&,
						const char*,
						infi_root_module_t&,
						infi_display_list_t&,
						module&,
						infi_win_mngr_module_t::refresh&,
						Render::infi_gl_shared_t&,
						Render::infi_gl_context_access_t&);

		static const uint32 Draw = 1;
		static const uint32 CreateContext = 2;
		static const uint32 DestroyContext = 3;

		typedef infi_dispatcher_t<infi_render_module_t::Draw,infi_gl_queue_t*> draw;
		typedef infi_dispatcher_t<infi_render_module_t::CreateContext,infi_window_t*> createContext;
		typedef infi_dispatcher_t<infi_render_module_t::DestroyContext,infi_window_t*> destroyContext;
	};

}

	template<> template<>
	void Render::infi_render_module_t::interpreter::interpret<0>(infi_event_queue_t&, const infi_event_queue_t::message&);

}

#endif//__INFI_RENDER_MODULE_HPP__
