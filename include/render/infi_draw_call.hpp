#ifndef __INFI_DRAW_CALL_HPP__
#define __INFI_DRAW_CALL_HPP__

namespace Infinity {
namespace Render {

	struct infi_draw_call_t {
	private:
		infi_program_t& _program;
		infi_vertices_t& _vertices;
	public:
		infi_draw_call_t(infi_program_t&, infi_vertices_t&)
	};

} }

#endif//__INFI_DRAW_CALL_HPP__