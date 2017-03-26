#ifndef __INFI_CONTROLLER_HPP__
#define __INFI_CONTROLLER_HPP__

#include "modules/infi_error_handler.hpp"

#include "engine/infi_displays.hpp"
#include "engine/infi_root_module.hpp"

#include "engine/winmngr/infi_win_mngr_recv.hpp"
#include "engine/winmngr/infi_win_mngr_interpreter.hpp"

#include "engine/updatemngr/infi_update_mngr_recv.hpp"
#include "engine/updatemngr/infi_update_mngr_interpreter.hpp"

#include "render/module/infi_render_recv.hpp"
#include "render/module/infi_render_interpreter.hpp"

namespace Infinity {

	struct infi_controller_t {
	private:
		struct __module_error_handler__ : public infi_error_handler_t {
		private:
			infi_root_module_t* _root;
		public:
			__module_error_handler__();
			
			void setRootModule(infi_root_module_t*);

			bool handle(infi_named_object_t&, Error::message<Error::Fatality::Fatal>&);
			bool handle(infi_named_object_t&, Error::message<Error::Fatality::Thread>&);
			bool handle(infi_named_object_t&, Error::message<Error::Fatality::Method>&);
			bool handle(infi_named_object_t&, Error::message<Error::Fatality::Warning>&);
		} _error_handler;

		std::thread _render_thr;
		std::thread _update_thr;
		
		infi_display_list_t _displays;

		infi_win_mngr_module_t::module _winmngr;
		infi_update_mngr_module_t::module _update;
		Render::infi_render_module_t::module _render;

		infi_win_mngr_reciever_t _winmngr_recv;
		infi_update_mngr_reciever_t _updatemngr_recv;
		Render::infi_render_reciever_t _render_recv;

		infi_root_module_t _root;
		
	public:
		Render::infi_synchronized_renderer_t renderer;
		infi_update_mngr_module_t::extension& extendWith;
		infi_display_list_t& displays;
		infi_input_events_t& input;
		infi_time_stream_t clock;

		infi_controller_t(infi_lib_init_t&);
		~infi_controller_t();

		infi_window_t& createWindow(const std::string&, const core::vec2ui&, uint32);
		infi_window_t& createWindow(const std::string&, const infi_window_spec_t&);

		Render::infi_renderer_t createRenderer();

		infi_controller_t& doWith( infi_extension_t* );
		infi_controller_t& doWith( infi_extension_t*, float64 );
		infi_controller_t& doWith( infi_extension_t*, infi_time_stream_t&, float64 );
		
		infi_controller_t& doWith( infi_extension_t& );
		infi_controller_t& doWith( infi_extension_t&, float64 );
		infi_controller_t& doWith( infi_extension_t&, infi_time_stream_t&, float64 );

		void abort();
		void run();
	};

}

#endif//__INFI_CONTROLLER_HPP__