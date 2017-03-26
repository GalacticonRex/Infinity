#include "render/infi_framebuffer.hpp"
#include "render/infi_texture.hpp"
#include "render/infi_sync_renderer.hpp"

namespace Infinity {
namespace Render {

		infi_framebuffer_t::Bind::Bind(infi_renderer_t& r, infi_framebuffer_t& f) :
			_renderer(r), _fbo(f) {
			if ( _fbo._handle == 0 ) {
				Error::send<Error::Fatality::Method>(
					Error::Type::Init,
					"cannot bind uninitialized texture!"
				);
			}
			_renderer.pushFramebuffer(_fbo._handle);
		}
		infi_framebuffer_t::Bind::~Bind() {
			_renderer.popFramebuffer();	
		}

		void infi_framebuffer_t::Bind::clear() {
			_renderer.clearScreen(_fbo._clear_color);
		}
		void infi_framebuffer_t::Bind::clear(const core::rgba_t& col) {
			_renderer.clearScreen(col);
		}
		void infi_framebuffer_t::Bind::texture(infi_texture_t& tex, uint32 bindpt) {
			_renderer.attachToFramebuffer(_fbo._handle, tex.handle(), bindpt);
		}

		infi_framebuffer_t::infi_framebuffer_t() :
			_handle(0),
			_dimensions(0,0) { ; }
		infi_framebuffer_t::infi_framebuffer_t(infi_renderer_t& r) :
			_handle(r.createFramebuffer()),
			_dimensions(0,0) { ; }
		infi_framebuffer_t::infi_framebuffer_t(infi_renderer_t& r, const core::rgba_t& c) :
			_handle(r.createFramebuffer()),
			_clear_color(c),
			_dimensions(0,0) { ; }

		void infi_framebuffer_t::create(infi_synchronized_renderer_t& renderer) {
			infi_synchronized_renderer_t::Acquire r(renderer);
			_handle = r -> createFramebuffer();
		}

		const core::vec2i& infi_framebuffer_t::dimensions() const {
			return _dimensions;
		}
		const core::rgba_t& infi_framebuffer_t::clearColor() const {
			return _clear_color;
		}

} }