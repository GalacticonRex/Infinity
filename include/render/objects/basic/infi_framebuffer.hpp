#ifndef __INFI_FRAMEBUFFER_HPP__
#define __INFI_FRAMEBUFFER_HPP__

#include "core/vector.hpp"
#include "render/infi_renderer.hpp"
#include "render/infi_render_resource.hpp"

namespace Infinity {
namespace Render {

	struct infi_framebuffer_t : public infi_resource_t {
	private:
		bool _ready;
		core::rgba_t _clear_color;
		core::vec2i _dimensions;

	public:
		struct DEFINE_EXPORT Bind {
		private:
			infi_renderer_t& _renderer;
			infi_framebuffer_t& _fbo;

		public:
			Bind(infi_renderer_t&, infi_framebuffer_t&);
			~Bind();

			void clear();
			void clear(const core::rgba_t&);
			void texture(infi_texture_t&, uint32 = 0);
		};

		infi_framebuffer_t();
		infi_framebuffer_t(infi_renderer_t&);
		infi_framebuffer_t(infi_renderer_t&, const core::rgba_t&);

		void create(infi_renderer_t&);
		bool ready() const;
		
		const core::vec2i& dimensions() const;
		const core::rgba_t& clearColor() const;
	};

} }

#endif//__INFI_FRAMEBUFFER_HPP__