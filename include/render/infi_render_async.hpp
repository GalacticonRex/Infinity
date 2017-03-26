#ifndef __INFI_RENDER_ASYNC_HPP__
#define __INFI_RENDER_ASYNC_HPP__

#include "components/infi_async.hpp"
#include "render/infi_render_defs.hpp"
#include "render/gl/infi_gl_command.hpp"
#include "render/module/infi_render_module.hpp"

namespace Infinity {
namespace Render {

	struct infi_render_async_t {
	private:
		struct __async_data__ {
			infi_controller_t& control;
			infi_async_t::call_order_t& call_order;

			__async_data__(infi_controller_t&, infi_async_t::call_order_t&);
		};
		struct __async_loader__ : public infi_gl_typed_function_t<__async_data__> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __async_data__&) const;
		};

		infi_renderer_t& _renderer;

	public:
		infi_render_async_t(infi_renderer_t&, const infi_render_module_t::Function&);

		infi_render_async_t then(const infi_render_module_t::Function&);
		infi_async_t then(infi_controller_t&, const infi_update_mngr_module_t::Function&);
	};

} }

#endif//__INFI_RENDER_ASYNC_HPP__