#include "render/objects/basic/infi_framebuffer.hpp"
#include "render/objects/basic/infi_texture.hpp"
#include "render/infi_sync_renderer.hpp"

namespace Infinity {
namespace Render {

		infi_framebuffer_t::Bind::Bind(infi_renderer_t& r, infi_framebuffer_t& f) :
			_renderer(r), _fbo(f) {
			if ( _fbo._handle == 0 ) {
				Error::send<Error::Fatality::Method>(
					Error::Type::Init,
					"cannot bind uninitialized framebuffer!"
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
			_fbo._ready = true;
		}

		infi_framebuffer_t::infi_framebuffer_t() :
			infi_resource_t(0),
			_ready(false),
			_dimensions(0,0) { ; }
		infi_framebuffer_t::infi_framebuffer_t(infi_renderer_t& r) :
			infi_resource_t(r.createFramebuffer()),
			_ready(false),
			_dimensions(0,0) { ; }
		infi_framebuffer_t::infi_framebuffer_t(infi_renderer_t& r, const core::rgba_t& c) :
			infi_resource_t(r.createFramebuffer()),
			_ready(false),
			_clear_color(c),
			_dimensions(0,0) { ; }

		void infi_framebuffer_t::create(infi_synchronized_renderer_t& renderer) {
			infi_synchronized_renderer_t::Acquire r(renderer);
			_handle = r -> createFramebuffer();
		}

		bool infi_framebuffer_t::ready() const {
			return _ready;
		}

		const core::vec2i& infi_framebuffer_t::dimensions() const {
			return _dimensions;
		}
		const core::rgba_t& infi_framebuffer_t::clearColor() const {
			return _clear_color;
		}

} }