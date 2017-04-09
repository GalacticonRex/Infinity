#include "render/gl/infi_gl_context.hpp"
#include "render/gl/infi_gl_context_access.hpp"

namespace Infinity {
namespace Render {

infi_framebuffer_bindings_t::infi_framebuffer_bindings_t() :
	handle(0), hash_value(0) { ; }

uint32 infi_framebuffer_bindings_t::generateHash() const {
	uint32 value = 0;
	for ( uint32 i=0;i<bindings.size();i++ ) {
		uint32 temp = (bindings[i].handle ^ bindings[i].type);
		value ^= (temp << i) | (temp >> (32-i));
	}
	return value;
}
void infi_framebuffer_bindings_t::set(uint32 index, uint32 handle, uint32 type) {
	if ( bindings.size() <= index ) {
		bindings.resize(index+1);
	}
	bindings[index].handle = handle;
	bindings[index].type = type;
	hash_value = generateHash();
}
void infi_framebuffer_bindings_t::synchronizeTo(const infi_gl_t& gl, infi_gl_shared_t& shr, infi_framebuffer_bindings_t& fbo) {
	uint32 i = 0;
	for ( ;i<fbo.bindings.size();i++ ) {
		if( bindings.size() <= i ||
			fbo.bindings[i].handle != bindings[i].handle ||
			fbo.bindings[i].type != bindings[i].type ) {
			if ( fbo.bindings[i].type == 0 ) {
				
				shr.pushTexture(gl, fbo.bindings[i].handle);
				gl.FramebufferTexture(GL_COLOR_ATTACHMENT0 + i, shr.texture(fbo.bindings[i].handle), 0);
				shr.popTexture(gl);
				if ( bindings.size() <= i )
					bindings.push_back(fbo.bindings[i]);
				else
					bindings[i] = fbo.bindings[i];

			} else {
				Error::send<Error::Fatality::Fatal>(
					Error::Type::Unimplemented,
					"have not yet implemented renderbuffers :("
				);
			}
		}
	}
	hash_value = fbo.hash_value;
}

infi_vertex_array_bindings_t::infi_vertex_array_bindings_t() :
	handle(0),
	array_buffer_handle(0),
	index_buffer_handle(0),
	vertex_size(0),
	hash_value(0) { ; }

uint32 infi_vertex_array_bindings_t::generateHash() const {
	return 0;
}
void infi_vertex_array_bindings_t::vertexSize(uint32 sz) {
	vertex_size = sz;
}
void infi_vertex_array_bindings_t::set(uint32 index, uint32 count, uint32 type, uint32 offset) {
	if ( bindings.size() <= index ) {
		bindings.resize(index+1);
	}
	
	bindings[index].enabled = true;
	bindings[index].count = count;
	bindings[index].type = type;
	bindings[index].offset = offset;

	hash_value = generateHash();
}
void infi_vertex_array_bindings_t::unset(uint32 index) {
	if ( bindings.size() <= index ) {
		bindings.resize(index+1);
	}

	bindings[index].enabled = false;

	hash_value = generateHash();
}

void infi_vertex_array_bindings_t::synchronizeTo(const infi_gl_t& gl, infi_gl_shared_t& shr, infi_vertex_array_bindings_t& vao) {
	vertex_size = vao.vertex_size;

	if ( vao.array_buffer_handle != array_buffer_handle) {
		gl.BindBuffer(GL_ARRAY_BUFFER, shr.buffer(vao.array_buffer_handle));
		array_buffer_handle = vao.array_buffer_handle;
	}
	
	if ( vao.index_buffer_handle != index_buffer_handle) {
		gl.BindBuffer(GL_ELEMENT_ARRAY_BUFFER, shr.buffer(vao.index_buffer_handle));
		index_buffer_handle = vao.index_buffer_handle;
	}

	uint32 sz = bindings.size();
	uint32 i = 0;
	for ( ;i<vao.bindings.size();i++ ) {
		if( sz <= i  || vao.bindings[i].enabled != bindings[i].enabled ||
						vao.bindings[i].count != bindings[i].count ||
						vao.bindings[i].type != bindings[i].type ) {
			if ( vao.bindings[i].enabled ) {
				__binding__& b = vao.bindings[i];
				gl.EnableVertexAttribArray(i);
				gl.VertexAttribPointer(i, b.count, b.type, false, vao.vertex_size, (void*)(std::size_t)b.offset );
			} else
				gl.DisableVertexAttribArray(i);

			if ( bindings.size() <= i )
				bindings.push_back(vao.bindings[i]);
			else
				bindings[i] = vao.bindings[i];
		}
	}

	if ( i < sz )
		bindings.resize(vao.bindings.size());
	for ( ;i<sz;i++ )
		gl.DisableVertexAttribArray(i);

	hash_value = vao.hash_value;
}

infi_blend_function_bindings_t::infi_blend_function_bindings_t() :
	alpha_only(true),
	source_alpha(GL_ONE),
	destination_alpha(GL_ZERO),
	source_color(0),
	destination_color(0) { ; }

bool infi_blend_function_bindings_t::__sync_func(const infi_gl_t& gl, infi_blend_function_bindings_t& bf) {
	if ( alpha_only ) {
		if ( source_alpha != bf.source_alpha ||
			 destination_alpha != bf.destination_alpha ) {
			gl.BlendFunc(bf.source_alpha, bf.destination_alpha);
			source_alpha = bf.source_alpha;
			destination_alpha = bf.destination_alpha;
			return false;
		}
	} else {
		if ( source_alpha != bf.source_alpha ||
			 source_color != bf.source_color ||
			 destination_alpha != bf.destination_alpha ||
			 destination_color != bf.destination_color ) {

			gl.BlendFuncSeparate(bf.source_color, bf.destination_color,
								 bf.source_alpha, bf.destination_alpha);
			
			source_alpha = bf.source_alpha;
			destination_alpha = bf.destination_alpha;

			source_alpha = bf.source_alpha;
			destination_alpha = bf.destination_alpha;
			return false;
		}
	}
	return true;
}

void infi_blend_function_bindings_t::blendAlphaOnly() {
	alpha_only = true;
}
void infi_blend_function_bindings_t::blendSeparate() {
	alpha_only = false;
}

void infi_blend_function_bindings_t::functionAlpha(uint32 src, uint32 dst) {
	source_alpha = src;
	destination_alpha = dst;
}
void infi_blend_function_bindings_t::functionColor(uint32 src, uint32 dst) {
	if ( alpha_only )
		Error::send<Error::Fatality::Method>(
			Error::Type::Value,
			"Cannot assign color function to alpha-only blend mode"
		);
	source_color = src;
	destination_color = dst;
}

bool infi_blend_function_bindings_t::synchronizeTo(const infi_gl_t& gl, infi_blend_function_bindings_t& bf) {
	bool value = true;
	if ( alpha_only != bf.alpha_only ) {
		if ( !alpha_only ) {
			source_color = 0;
			destination_color = 0;
		}
		alpha_only = bf.alpha_only;
		value = false;
	}
	value = value && __sync_func(gl, bf);
	return value;
}

infi_blend_equation_bindings_t::infi_blend_equation_bindings_t() :
	alpha_only(true),
	mode_alpha(GL_FUNC_ADD),
	mode_color(0) { ; }

bool infi_blend_equation_bindings_t::__sync_mode(const infi_gl_t& gl, infi_blend_equation_bindings_t& bf) {
	if ( alpha_only ) {
		if ( mode_alpha != bf.mode_alpha ) {
			gl.BlendEquation(bf.mode_alpha);
			mode_alpha = bf.mode_alpha;
			return false;
		}
	} else {
		if ( mode_alpha != bf.mode_alpha ||
			 mode_color != bf.mode_color) {
			gl.BlendEquationSeparate(bf.mode_color, bf.mode_alpha);
			mode_alpha = bf.mode_alpha;
			mode_color = bf.mode_color;
			return false;
		}
	} 
	return true;
}
bool infi_blend_equation_bindings_t::synchronizeTo(const infi_gl_t& gl, infi_blend_equation_bindings_t& bf) {
	bool value = true;
	if ( alpha_only != bf.alpha_only ) {
		if ( !alpha_only ) {
			mode_color = 0;
		}
		alpha_only = bf.alpha_only;
		value = false;
	}
	value = value && __sync_mode(gl, bf);
	return value;
}

void infi_blend_equation_bindings_t::blendAlphaOnly() {
	alpha_only = true;
}
void infi_blend_equation_bindings_t::blendSeparate() {
	alpha_only = false;
}

void infi_blend_equation_bindings_t::equationAlpha(uint32 mode) {
	mode_alpha = mode;
}
void infi_blend_equation_bindings_t::equationColor(uint32 mode) {
	if ( alpha_only )
		Error::send<Error::Fatality::Method>(
			Error::Type::Value,
			"Cannot assign color function to alpha-only blend mode"
		);
	mode_color = mode;
}

infi_gl_context_t::infi_gl_context_t( const infi_gl_t& gl, infi_gl_context_access_t& cxt ) :
 	_controller( cxt ) {
 	
 	gl.Enable(GL_TEXTURE_2D);
 	gl.Enable(GL_BLEND);
 	gl.Enable(GL_DEPTH_TEST);
 	gl.Enable(GL_STENCIL_TEST);
 	gl.Enable(GL_CULL_FACE);

 	gl.ShadeModel(GL_SMOOTH);

 	gl.DepthFunc(GL_LEQUAL);
}

infi_framebuffer_bindings_t& infi_gl_context_t::framebuffer(uint32 x) {
	if ( x == 0 ) {
		Error::send<Error::Fatality::Method>(
			Error::Type::NullDeref,
			"Cannot get null framebuffer"
		);
	}
	fbo_ptr& i = _framebuffers[x];
	if ( i == nullptr ) {
		i = &_controller.allocFramebuffer();
	}
	return *i;
}
infi_vertex_array_bindings_t& infi_gl_context_t::vertexArray(uint32 x) {
	if ( x == 0 ) {
		Error::send<Error::Fatality::Method>(
			Error::Type::NullDeref,
			"Cannot get null vertex array"
		);
	}
	vao_ptr& i = _vertex_arrays[x];
	if ( i == nullptr ) {
		i = &_controller.allocVertexArray();
	}
	return *i;
}
infi_transform_feeback_bindings_t& infi_gl_context_t::transformFeedback(uint32 x) {
	if ( x == 0 ) {
		Error::send<Error::Fatality::Method>(
			Error::Type::NullDeref,
			"Cannot get null transform feedback"
		);
	}
	tfo_ptr& i = _transform_feedback[x];
	if ( i == nullptr ) {
		i = &_controller.allocTransformFeedback();
	}
	return *i;
}

const infi_framebuffer_bindings_t& infi_gl_context_t::framebuffer(uint32 x) const {
	std::unordered_map<uint32, fbo_ptr>::const_iterator i = _framebuffers.find(x);
	if ( i == _framebuffers.end() ) {
		Error::send<Error::Fatality::Method>(
			Error::Type::NullDeref,
			"Could not find framebuffer %d in context (try non-const access)", x
		);
	}
	return *(*i).second;
}
const infi_vertex_array_bindings_t& infi_gl_context_t::vertexArray(uint32 x) const {
	std::unordered_map<uint32, vao_ptr>::const_iterator i = _vertex_arrays.find(x);
	if ( i == _vertex_arrays.end() ) {
		Error::send<Error::Fatality::Method>(
			Error::Type::NullDeref,
			"Could not find framebuffer %d in context (try non-const access)", x
		);
	}
	return *(*i).second;
}
const infi_transform_feeback_bindings_t& infi_gl_context_t::transformFeedback(uint32 x) const {
	std::unordered_map<uint32, tfo_ptr>::const_iterator i = _transform_feedback.find(x);
	if ( i == _transform_feedback.end() ) {
		Error::send<Error::Fatality::Method>(
			Error::Type::NullDeref,
			"Could not find framebuffer %d in context (try non-const access)", x
		);
	}
	return *(*i).second;
}

infi_blend_function_bindings_t& infi_gl_context_t::blendFunction() {
	return _blend_function;
}
const infi_blend_function_bindings_t& infi_gl_context_t::blendFunction() const {
	return _blend_function;
}

infi_blend_equation_bindings_t& infi_gl_context_t::blendEquation() {
	return _blend_equation;
}
const infi_blend_equation_bindings_t& infi_gl_context_t::blendEquation() const {
	return _blend_equation;
}

} }
