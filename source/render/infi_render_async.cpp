#include "render/infi_render_async.hpp"
#include "engine/infi_controller.hpp"

namespace Infinity {
namespace Render {

	infi_render_async_t::__async_data__::__async_data__(infi_controller_t& ctrl, infi_async_t::call_order_t& co) :
		control(ctrl), call_order(co) { ; }

	bool infi_render_async_t::__async_loader__::compatible(const infi_gl_t& gl) const {
		return true;
	}
	void infi_render_async_t::__async_loader__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, __async_data__& data) const {
		infi_async_t::runAsyncOperation(data.control, &data.call_order);
	}

	infi_render_async_t::infi_render_async_t(infi_renderer_t& R, const infi_render_module_t::Function& func) :
		_renderer(R) {
		_renderer.command(func);
	}

	infi_render_async_t infi_render_async_t::then(const infi_render_module_t::Function& func) {
		return infi_render_async_t(_renderer, func);
	}
	infi_async_t infi_render_async_t::then(infi_controller_t& ctrl, const infi_update_mngr_module_t::Function& func) {
		infi_async_t async(ctrl, func, true);
		
		__async_loader__ fun;
		__async_data__ dat(ctrl, async.asyncOperation());

		fun.push( _renderer.state(), dat );
		_renderer.command(fun);

		return async;
	}

} }