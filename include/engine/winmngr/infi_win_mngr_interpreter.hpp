#ifndef __INFI_WINDOW_MANAGER_INTERPRETER_HPP__
#define __INFI_WINDOW_MANAGER_INTERPRETER_HPP__

#include "engine/winmngr/infi_win_mngr_module.hpp"
#include "modules/infi_interpreter.hpp"
#include "components/infi_window.hpp"

#include "render/module/infi_render_module.hpp"

namespace Infinity {
	struct infi_win_mngr_interpreter_t : public infi_win_mngr_module_t::interpreter {
	private:
		struct __refresh__ : public infi_process_message_t<infi_window_t*> {
		private:
			infi_win_mngr_interpreter_t& _src;
		public:
			__refresh__(infi_win_mngr_interpreter_t&);
			void interpret(infi_window_t*&);
		};
		struct __destroy_window__ : public infi_process_message_t<infi_window_t*> {
		private:
			infi_win_mngr_interpreter_t& _src;
		public:
			__destroy_window__(infi_win_mngr_interpreter_t&);
			void interpret(infi_window_t*&);
		};
		struct __bind_renderable__ : public infi_process_message_t<infi_renderable_t*> {
		private:
			infi_win_mngr_interpreter_t& _src;
		public:
			__bind_renderable__(infi_win_mngr_interpreter_t&);
			void interpret(infi_renderable_t*&);
		};

		infi_window_t* _rendering;
		uint32 _active_windows;

		Render::infi_renderer_t _renderer;

		infi_win_mngr_module_t::refresh& _refresh_dsp;
		infi_win_mngr_module_t::destroyWindow& _destroy_window_dsp;
		Render::infi_render_module_t::destroyContext& _destroy_context_dsp;

		__refresh__ _refresh;
		__destroy_window__ _destroy_window;
		__bind_renderable__ _bind_renderable;

	public:
		infi_win_mngr_interpreter_t(infi_controller_t&,
									infi_win_mngr_module_t::refresh&,
									infi_win_mngr_module_t::destroyWindow&,
									Render::infi_render_module_t::destroyContext& );
		~infi_win_mngr_interpreter_t();
	};

}

#endif//__INFI_WINDOW_MANAGER_INTERPRETER_HPP__