#include "render/module/infi_render_module.hpp"
#include "render/module/infi_render_recv.hpp"
#include "render/module/infi_render_interpreter.hpp"
#include "engine/winmngr/infi_win_mngr_module.hpp"
#include "engine/infi_root_module.hpp"
#include "render/gl/infi_gl_init.hpp"
#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_context_controller.hpp"
#include "modules/infi_error_handler.hpp"

namespace Infinity {

	template<> template<>
	void Render::infi_render_module_t::interpreter::interpret<0>(infi_event_queue_t&, const infi_event_queue_t::message& msg) {
		Error::send<Error::Fatality::Thread>(
			Error::Type::Index,
			"Cannot process message with index %d",
			msg.code
		);
	}
	
namespace Render {

	void infi_render_module_t::run( std::condition_variable& cond,
									const char* fname,
									infi_root_module_t& rt,
									infi_display_list_t& dsp,
									module& mod,
									infi_win_mngr_module_t::refresh& r,
									infi_gl_shared_t& shr,
									infi_gl_context_access_t& ctxacc) {
		std::ofstream output(fname);

		infi_gl_init_t init(rt, dsp);
		infi_gl_t gl(init, output);
		infi_gl_context_controller_t ctx(gl, shr, ctxacc, rt.baseWindow());

		shr.allocate_texture_units(gl);
		gl.Debug_ActivateTrace();

		// let the controlling thread know the renderer is done
		cond.notify_all();

		infi_render_interpreter_t interpreter(rt, gl, ctx, r);
		mod.interpreter(interpreter);
		mod.run();
		
		output.close();
	}


	infi_render_reciever_t::infi_render_reciever_t(infi_render_module_t::module& mod) :
		draw(mod.dispatcher<1>()),
		createContext(mod.dispatcher<2>()),
		destroyContext(mod.dispatcher<3>()),
		terminate(mod) { ; }


	infi_render_interpreter_t::infi_render_interpreter_t(infi_root_module_t& rt,
														 infi_gl_t& gl,
														 infi_gl_context_controller_t& ctx,
														 infi_win_mngr_module_t::refresh& r) :
		infi_render_module_t::interpreter(std::make_tuple(&_draw, &_create_context, &_destroy_context)),
		_root(rt),
		_gl(gl),
		_gl_ctx(ctx),
		_refresh(r),
		_draw(*this),
		_create_context(*this),
		_destroy_context(*this) { ; }

	infi_render_interpreter_t::~infi_render_interpreter_t() {

	}

	infi_render_interpreter_t::__draw__::__draw__(infi_render_interpreter_t& i) : _src(i) { ; }
	void infi_render_interpreter_t::__draw__::interpret(infi_gl_queue_t*& q) {
		q -> draw(_src._gl, _src._gl_ctx);
	}
	infi_render_interpreter_t::__create_context__::__create_context__(infi_render_interpreter_t& i) : _src(i) { ; }
	void infi_render_interpreter_t::__create_context__::interpret(infi_window_t*& w) {
		w -> createContext(_src._gl_ctx);
		_src._refresh( w );
	}
	infi_render_interpreter_t::__destroy_context__::__destroy_context__(infi_render_interpreter_t& i) : _src(i) { ; }
	void infi_render_interpreter_t::__destroy_context__::interpret(infi_window_t*& w) {
		w -> deleteContext(_src._gl_ctx);
		_src._root.destroyWindow( w );
	}

} }