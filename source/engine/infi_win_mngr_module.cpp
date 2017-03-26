#include "engine/winmngr/infi_win_mngr_module.hpp"
#include "engine/infi_root_module.hpp"
#include "render/module/infi_render_module.hpp"
#include "engine/infi_controller.hpp"

namespace Infinity {

	template<> template<> 
	void infi_win_mngr_module_t::interpreter::interpret<0>(infi_event_queue_t&, const infi_event_queue_t::message& msg) {
		Error::send<Error::Fatality::Thread>(
			Error::Type::Index,
			"Cannot process message with index %d",
			msg.code
		);
	}

	infi_win_mngr_reciever_t::infi_win_mngr_reciever_t(infi_win_mngr_module_t::module& mod) :
		refresh(mod.dispatcher<1>()),
		destroyWindow(mod.dispatcher<2>()),
		bindRenderable(mod.dispatcher<3>()),
		terminate(mod) { ; }

	infi_win_mngr_interpreter_t::infi_win_mngr_interpreter_t(infi_controller_t& ctrl,
															 infi_win_mngr_module_t::refresh& r,
															 infi_win_mngr_module_t::destroyWindow& dw,
															 Render::infi_render_module_t::destroyContext& dc) :
		infi_win_mngr_module_t::interpreter(std::make_tuple(&_refresh, &_destroy_window, &_bind_renderable)),
		_rendering(NULL),
		_active_windows(0),
		_renderer(ctrl.createRenderer()),
		_refresh_dsp(r),
		_destroy_window_dsp(dw),
		_destroy_context_dsp(dc),
		_refresh(*this),
		_destroy_window(*this),
		_bind_renderable(*this) {
	}

	infi_win_mngr_interpreter_t::~infi_win_mngr_interpreter_t() {

	}

	infi_win_mngr_interpreter_t::__refresh__::__refresh__(infi_win_mngr_interpreter_t& i) : _src(i){ ; }
	void infi_win_mngr_interpreter_t::__refresh__::interpret(infi_window_t*& win) {
		_src._rendering = win;

		_src._renderer.setContext(_src._rendering);
		_src._renderer.clearScreen(_src._rendering -> clearColor());
		_src._rendering -> __run_render(_src._renderer);
		_src._renderer.swapContext(_src._rendering);
		_src._renderer.flush();

		( !_src._rendering -> isClosing() ) ?
			_src._refresh_dsp(_src._rendering -> timeStream(), _src._rendering -> frameRate(), _src._rendering) :
			_src._destroy_window_dsp(_src._rendering);
	}
	infi_win_mngr_interpreter_t::__destroy_window__::__destroy_window__(infi_win_mngr_interpreter_t& i) : _src(i){ ; }
	void infi_win_mngr_interpreter_t::__destroy_window__::interpret(infi_window_t*& win) {
		_src._destroy_context_dsp(win);
	}
	infi_win_mngr_interpreter_t::__bind_renderable__::__bind_renderable__(infi_win_mngr_interpreter_t& i) : _src(i){ ; }
	void infi_win_mngr_interpreter_t::__bind_renderable__::interpret(infi_renderable_t*& r) {
		r -> OnBind(_src._renderer);
		r -> parent()._renderables.insert( r );
	}

}