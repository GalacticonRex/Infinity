#ifndef __INFI_GL_CONTAINER_HPP__
#define __INFI_GL_CONTAINER_HPP__

namespace Infinity {
namespace Render {

	struct infi_gl_container {
	protected:
		uint32 _handle;
	public:
		virtual void Update() = 0;
	}

} }

#endif//__INFI_GL_CONTAINER_HPP__