#ifndef __INFI_RENDER_RESOURCE_HPP__
#define __INFI_RENDER_RESOURCE_HPP__

#include "render/infi_render_defs.hpp"

namespace Infinity {
namespace Render {

	struct infi_resource_t {
	protected:
		uint32 _handle;

	public:
		infi_resource_t(uint32 hnd) :
			_handle(hnd) { ; }

		uint32 handle() const {
			return _handle;
		}
		
		virtual bool ready() const = 0;
	};

} }

#endif//__INFI_RENDER_RESOURCE_HPP__