#include "render/infi_sync_renderer.hpp"
#include "render/infi_renderer.hpp"

namespace Infinity {
namespace Render {

	infi_synchronized_renderer_t::Acquire::Acquire(infi_synchronized_renderer_t& r) :
		_handle(r) { _handle._lock.lock(); }
	infi_synchronized_renderer_t::Acquire::~Acquire() {
		_handle._renderer.flush();
		_handle._lock.unlock();
	}
	infi_renderer_t* infi_synchronized_renderer_t::Acquire::operator->() {
		return &_handle._renderer;
	}
	infi_renderer_t& infi_synchronized_renderer_t::Acquire::source() {
		return _handle._renderer;
	}
	const infi_renderer_t& infi_synchronized_renderer_t::Acquire::source() const {
		return _handle._renderer;
	}
	infi_synchronized_renderer_t::Acquire::operator infi_renderer_t&() {
		return _handle._renderer;
	}

	infi_synchronized_renderer_t::infi_synchronized_renderer_t(infi_renderer_t& r) :
		_renderer(r) { ; }

} }