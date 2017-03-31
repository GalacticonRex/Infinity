#include "render/infi_renderer.hpp"
#include "render/gl/infi_gl_queue.hpp"
#include "render/gl/infi_gl_context_access.hpp"

namespace Infinity {
namespace Render {

	bool infi_renderer_t::MakeCurrentContext::compatible(const infi_gl_t& GL) const { return true; }
	void infi_renderer_t::MakeCurrentContext::run(const infi_gl_t& GL, infi_gl_context_controller_t& ctrl, infi_window_t*& state) const {
		state -> makeCurrentContext(ctrl);
	}

	bool infi_renderer_t::SwapContext::compatible(const infi_gl_t& GL) const { return true; }
	void infi_renderer_t::SwapContext::run(const infi_gl_t& GL, infi_gl_context_controller_t& ctrl, infi_window_t*& state) const {
		state -> swapContext(ctrl);
	}

	bool infi_renderer_t::ClearScreen::compatible(const infi_gl_t& gl) const { return true; }
	void infi_renderer_t::ClearScreen::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, core::rgba_t& state) const {
		gl.ClearColor(state.x, state.y, state.z, state.w);
		gl.Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	bool infi_renderer_t::DrawArrays::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_renderer_t::DrawArrays::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, __draw_call__& state) const {
		gl.DrawArrays( state.mode, state.initial, state.count );
	}

	infi_renderer_t::infi_renderer_t(infi_gl_shared_t& sh, infi_gl_context_access_t& ctx, infi_render_module_t::draw& d) :
		_shared(sh),
		_contexts(ctx),
		_draw(d) { ; }

	void infi_renderer_t::setContext(infi_window_t* win) {
		_make_current_context.push(_queue.getStateQueue(), win);
		_queue.push(_make_current_context);
	}
	void infi_renderer_t::swapContext(infi_window_t* win) {
		_swap_context.push(_queue.getStateQueue(), win);
		_queue.push(_swap_context);
	}

	void infi_renderer_t::clearScreen(const core::rgba_t& value) {
		_clear_screen.push(_queue.getStateQueue(), value);
		_queue.push(_clear_screen);
	}

	void infi_renderer_t::drawArrays(DrawMode mode, uint32 count, uint32 initial) {
		_contexts.synchronizeFramebuffer(_queue);
		_draw_arrays.push(_queue.getStateQueue(), {mode, initial, count});
		_queue.push(_draw_arrays);
	}

	uint32 infi_renderer_t::createTexture() {
		return _shared.createTexture(_queue);
	}
	void infi_renderer_t::destroyTexture( uint32 tex ) {
		_shared.destroyTexture(_queue, tex);
	}
	void infi_renderer_t::pushTexture(uint32 tex, uint32 a) {
		_shared.pushTexture(_queue, tex, a);
	}
	uint32 infi_renderer_t::popTexture(uint32 a) {
		return _shared.popTexture(_queue, a);
	}

	uint32 infi_renderer_t::createProgram() {
		return _shared.createProgram(_queue);
	}
	void infi_renderer_t::destroyProgram( uint32 prog ) {
		_shared.destroyProgram(_queue, prog);
	}
	void infi_renderer_t::pushProgram(uint32 prog) {
		_shared.pushProgram(_queue, prog);
	}
	uint32 infi_renderer_t::popProgram() {
		return _shared.popProgram(_queue);
	}

	uint32 infi_renderer_t::createBuffer(BufferBindPoint type) {
		return _shared.createBuffer(_queue, type);
	}
	void infi_renderer_t::destroyBuffer(uint32 buffer) {
		_shared.destroyBuffer(_queue, buffer);
	}
	void infi_renderer_t::pushBuffer(uint32 buffer) {
		_shared.pushBuffer(_queue, buffer);
	}
	void infi_renderer_t::pushBuffer(uint32 buffer, BufferBindPoint type) {
		_shared.pushBuffer(_queue, buffer, type);
	}
	uint32 infi_renderer_t::popBuffer(BufferBindPoint type) {
		return _shared.popBuffer(_queue, type);
	}

	void infi_renderer_t::pushVertexFormat() {
		_shared.pushVertexFormat(_queue);
	}
	void infi_renderer_t::enableVertexAttrib(uint32 i) {
		_shared.enableVertexAttrib(_queue, i);
	}
	void infi_renderer_t::popVertexFormat() {
		_shared.popVertexFormat(_queue);
	}

	uint32 infi_renderer_t::createFramebuffer() {
		return _contexts.createFramebuffer();
	}
	void infi_renderer_t::destroyFramebuffer(uint32 fbo) {
		_contexts.destroyFramebuffer(fbo);
	}
	void infi_renderer_t::pushFramebuffer(uint32 fbo) {
		_contexts.pushFramebuffer(_queue, fbo);
	}
	uint32 infi_renderer_t::popFramebuffer() {
		return _contexts.popFramebuffer(_queue);
	}
	void infi_renderer_t::attachToFramebuffer(uint32 fbo, uint32 tex, uint32 bindpt, uint32 type) {
		_contexts.attachToFramebuffer(fbo, tex, bindpt, type);
	}

	uint32 infi_renderer_t::createVertexArray() {
		return _contexts.createVertexArray();
	}
	void infi_renderer_t::destroyVertexArray(uint32 vao) {
		_contexts.destroyVertexArray(vao);	
	}
	void infi_renderer_t::pushVertexArray(uint32 vao) {
		_contexts.pushVertexArray(_queue, vao);	
	}
	uint32 infi_renderer_t::popVertexArray() {
		return _contexts.popVertexArray(_queue);
	}
	void infi_renderer_t::arrayBufferToVertexArray(uint32 vao, uint32 buf) {
		_contexts.arrayBufferToVertexArray(vao, buf);
	}
	void infi_renderer_t::indexBufferToVertexArray(uint32 vao, uint32 buf) {
		_contexts.indexBufferToVertexArray(vao, buf);
	}
	void infi_renderer_t::vertexSizeToVertexArray(uint32 vao, uint32 size) {
		_contexts.vertexSizeToVertexArray(vao, size);
	}
	void infi_renderer_t::enableVertexArray(uint32 vao, uint32 index, uint32 count, uint32 type, uint32 offset) {
		_contexts.enableVertexArray(vao, index, count, type, offset);
	}
	void infi_renderer_t::disableVertexArray(uint32 vao, uint32 index) {
		_contexts.disableVertexArray(vao, index);
	}

	void infi_renderer_t::pushBlendFunction(const infi_blend_function_bindings_t& b) {
		_contexts.pushBlendFunction(_queue, b);
	}
	void infi_renderer_t::popBlendFunction() {
		_contexts.popBlendFunction(_queue);
	}
	
	void infi_renderer_t::pushBlendEquation(const infi_blend_equation_bindings_t& b) {
		_contexts.pushBlendEquation(_queue, b);
	}
	void infi_renderer_t::popBlendEquation() {
		_contexts.popBlendEquation(_queue);
	}

	infi_default_queue_t& infi_renderer_t::state() {
		return _queue.getStateQueue();
	}
	void infi_renderer_t::command(infi_render_module_t::Function cmd) {
		_queue.push(cmd);
	}
	void infi_renderer_t::operator() (infi_render_module_t::Function cmd) {
		this -> command(cmd);
	}

	void infi_renderer_t::flush() {
		_queue.stop();
		if (!_queue.empty())
			_draw(&_queue);
	}

} }