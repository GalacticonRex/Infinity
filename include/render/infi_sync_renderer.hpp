#ifndef __INFI_SYNCHRONIZED_RENDERER_HPP__
#define __INFI_SYNCHRONIZED_RENDERER_HPP__

#include <mutex>
#include "render/infi_render_defs.hpp"

namespace Infinity {
namespace Render {

	struct infi_synchronized_renderer_t {
	private:
		std::mutex _lock;
		infi_renderer_t& _renderer;
	public:
		struct DEFINE_EXPORT Acquire {
		private:
			infi_synchronized_renderer_t& _handle;
		public:
			Acquire(infi_synchronized_renderer_t&);
			~Acquire();
			infi_renderer_t* operator->();
			infi_renderer_t& source();
			const infi_renderer_t& source() const;
			operator infi_renderer_t&();
		};

		infi_synchronized_renderer_t(infi_renderer_t&);
	};

} }

#endif//__INFI_SYNCHRONIZED_RENDERER_HPP__