#ifndef __infi_root_module_HPP__
#define __infi_root_module_HPP__

#include <unordered_map>
#include <queue>

#include "components/infi_input_events.hpp"
#include "components/infi_window.hpp"

#include "modules/infi_module_defs.hpp"
#include "modules/infi_termination_dispatch.hpp"

#include "render/module/infi_render_module.hpp"
#include "render/infi_renderer.hpp"

namespace Infinity {

	struct infi_root_module_t {
	private:
		infi_window_t* _active;

		uint32 _window_count;
		std::unordered_map<uint32,infi_window_t*> _winids;

		void* _window;
		std::queue<void*> _queue;
		std::mutex _window_create;
		std::mutex _window_destroy;

		uint32 _value_start;
		uint32 _value_create;
		uint32 _value_destroy;
		uint32 _value_terminate;
		uint32 _value_error;

		void* _signal_start;
		void* _signal_create;
		void* _signal_destroy;
		void* _signal_terminate;
		void* _signal_error;

		Render::infi_renderer_t _renderer;

		infi_keyboard_t _keyboard;
		infi_mouse_t _mouse;
		infi_input_events_t _input;

		Render::infi_render_module_t::createContext& _createContext;
		infi_dispatch_terminate_t& _winMngrTerminate;

		void __handle_window_ev( const void* ev );
		void __handle_key_down_ev( const void* ev );
		void __handle_key_up_ev( const void* ev );
		void __handle_mouse_move_ev( const void* ev );
		void __handle_mouse_down_ev( const void* ev );
		void __handle_mouse_up_ev( const void* ev );
		void __handle_mouse_wheel_ev( const void* ev );

		void __gen_window_control(infi_window_t*);
		void __del_window_control(infi_window_t*);

		void __run();

	public:
		infi_root_module_t( infi_controller_t&,
							Render::infi_render_module_t::createContext&,
							infi_dispatch_terminate_t&);
		~infi_root_module_t();

		void signalStart();
		void signalError();
		void signalTerminate();

		void createWindow(infi_window_t*);
		void destroyWindow(infi_window_t*);

		void* baseWindow() const;

		Render::infi_renderer_t& renderer();
		const Render::infi_renderer_t& renderer() const;

		infi_window_t* activeWindow() const;
		infi_window_t* getWindowByID(uint32) const;

		infi_input_events_t& input();
		infi_keyboard_t& getKeys();
		infi_mouse_t& getMouse();

		void run();

	};

}

#endif//__infi_root_module_HPP__