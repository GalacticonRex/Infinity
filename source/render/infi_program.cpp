#include "render/objects/basic/infi_program.hpp"
#include "render/gl/infi_gl_context_controller.hpp"
#include "render/objects/basic/infi_buffer_object.hpp"
#include "render/infi_sync_renderer.hpp"

namespace Infinity {
namespace Render {

	void infi_program_t::__link_program__::__check_shader(const infi_gl_t& gl, const char* name, uint32 shader) const {
		int32 done = 0;
		gl.GetShaderiv( shader, GL_COMPILE_STATUS, &done);

		if ( done == GL_FALSE ) {
			int32 maxlen = 0;
			gl.GetShaderiv( shader, GL_INFO_LOG_LENGTH, &maxlen );

			char* infolog = new char[maxlen+1];
			gl.GetShaderInfoLog( shader, maxlen, &maxlen, infolog );
			gl.DeleteShader( shader );

			Error::send<Error::Fatality::Fatal>(
				Error::Type::Graphics,
				"Error compiling %s:\r\n%s",
				name, infolog
			);

			delete[] infolog;
		}
	}
	void infi_program_t::__link_program__::__check_program(const infi_gl_t& gl, uint32 handle) const {
		int32 is_linked;
		gl.GetProgramiv(handle, GL_LINK_STATUS, &is_linked);
		if ( is_linked == GL_FALSE ) {
			int32 maxlen = 0;
			gl.GetProgramiv(handle, GL_INFO_LOG_LENGTH, &maxlen);

			char* infolog = new char[maxlen+1];
			gl.GetProgramInfoLog(handle, maxlen, &maxlen, infolog);

			gl.DeleteProgram(handle);

			Error::send<Error::Fatality::Fatal>(
				Error::Type::Graphics,
				"Shader program could not compile:\r\n%s",
				infolog
			);

			delete[] infolog;
		}
	}
	bool infi_program_t::__link_program__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__link_program__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, infi_program_t*& state) const {
		//Error::define_scope __scope__("Link Shader Program");

		infi_program_t& program = *state;
		uint32 handle = ctx.shared.program(program._handle);

		uint32 vshader = 0, fshader = 0;

		vshader = gl.CreateShader(GL_VERTEX_SHADER);
		gl.ShaderSource(vshader, 1, &program.vertex, NULL);
		gl.CompileShader(vshader);

		__check_shader(gl, "Vertex Shader", vshader);

		gl.AttachShader(handle, vshader);

		if ( program.fragment != NULL ) {
			fshader = gl.CreateShader(GL_FRAGMENT_SHADER);
			gl.ShaderSource(fshader, 1, &program.fragment, NULL);
			gl.CompileShader(fshader);

			__check_shader(gl, "Fragment Shader", fshader);

			gl.AttachShader(handle, fshader);
		}

		gl.LinkProgram(handle);
		if ( vshader != 0 )
			gl.DeleteShader( vshader );
		if ( fshader != 0 )
			gl.DeleteShader( fshader );

		__check_program(gl, handle);

		char buffer[512];
		uint32 count = 0;
		int32 len = 0;
		int32 size = 0;
		GLenum type;

		gl.GetProgramiv(handle, GL_ACTIVE_UNIFORMS, (int32*)&count);
		for (uint32 i=0;i<count;i++ ) {
			gl.GetActiveUniform(handle, i, 512, &len, &size, &type, buffer);
			program._uniforms[buffer] = gl.GetUniformLocation(handle, buffer);
			program._uniform_types.push_back(type);
		}

		std::vector<infi_vertex_format_t::attribute> attr;

		gl.GetProgramiv(handle, GL_ACTIVE_ATTRIBUTES, (int32*)&count);
		for (uint32 i=0;i<count;i++ ) {
			gl.GetActiveAttrib(handle, i, 512, &len, &size, &type, buffer);
			uint32 id = gl.GetAttribLocation(handle, buffer);
			program._attributes[buffer] = id;
			program._attrib_types.push_back(type);
			attr.push_back({id,type,(uint32)size});
		}

		program.format = infi_vertex_format_t(attr);

		program._linked ++ ;
	}

	bool infi_program_t::__assign_uniform_int1__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_int1__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniformi(data.source -> __get_uniform(data.name), data.data);
	}
	bool infi_program_t::__assign_uniform_int1v__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_int1v__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniformiv(data.source -> __get_uniform(data.name), data.count, data.data);
	}

	bool infi_program_t::__assign_uniform_float1__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_float1__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniformf(data.source -> __get_uniform(data.name), data.data);
	}
	bool infi_program_t::__assign_uniform_float1v__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_float1v__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniformfv(data.source -> __get_uniform(data.name), data.count, data.data);
	}

	bool infi_program_t::__assign_uniform_float2__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_float2__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniformf(data.source -> __get_uniform(data.name), data.data);
	}
	bool infi_program_t::__assign_uniform_float3__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_float3__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniformf(data.source -> __get_uniform(data.name), data.data);
	}
	bool infi_program_t::__assign_uniform_float4__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_float4__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniformf(data.source -> __get_uniform(data.name), data.data);
	}

	bool infi_program_t::__assign_uniform_float2x2__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_float2x2__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniform(data.source -> __get_uniform(data.name), data.data);
	}
	bool infi_program_t::__assign_uniform_float3x3__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_float3x3__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniform(data.source -> __get_uniform(data.name), data.data);
	}
	bool infi_program_t::__assign_uniform_float4x4__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__assign_uniform_float4x4__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, data_item& data) const {
		gl.Uniform(data.source -> __get_uniform(data.name), data.data);
	}
	bool infi_program_t::__draw_arrays__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_program_t::__draw_arrays__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, __draw_item__& item) const {
		gl.DrawArrays(item.mode, 0, item.buffer->byteSize() / item.format->byteSize());
	}

	infi_program_t::assign_uniform::assign_uniform(infi_program_t::Bind& b, const std::string& n) :
		_name(n), _program(b) { ; }

	void infi_program_t::assign_uniform::operator=(float32 data) {
		_program.uniform(_name, data);
	}
	void infi_program_t::assign_uniform::operator=(core::vec2 data) {
		_program.uniform(_name, data);
	}
	void infi_program_t::assign_uniform::operator=(core::vec3 data) {
		_program.uniform(_name, data);
	}
	void infi_program_t::assign_uniform::operator=(core::vec4 data) {
		_program.uniform(_name, data);
	}

	infi_program_t::Bind::Bind(infi_renderer_t& r, infi_program_t& prog) :
		_program(prog),
		_renderer(r),
		format(_program.format) {
		if ( _program._handle == 0 ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::Init,
				"cannot bind uninitialized texture!"
			);
		}
		_renderer.pushProgram(_program._handle);
	}
	infi_program_t::Bind::~Bind() {
		_renderer.popProgram();
	}

	void infi_program_t::Bind::uniformi(const std::string& name, int32 data) {
		_program._assign_int1.push(_renderer.state(), {&_program, name, data});
		_renderer(_program._assign_int1);
	}
	void infi_program_t::Bind::uniformiv(const std::string& name, uint32 count, int32* data) {
		_program._assign_int1v.push(_renderer.state(), {&_program, name, count, data});
		_renderer(_program._assign_int1v);
	}
	void infi_program_t::Bind::uniform(const std::string& name, float32 data) {
		_program._assign_float1.push(_renderer.state(), {&_program, name, data});
		_renderer(_program._assign_float1);
	}
	void infi_program_t::Bind::uniformv(const std::string& name, uint32 count, float32* data) {
		_program._assign_float1v.push(_renderer.state(), {&_program, name, count, data});
		_renderer(_program._assign_float1v);
	}

	void infi_program_t::Bind::uniform(const std::string& name, const core::vec2& data) {
		_program._assign_float2.push(_renderer.state(), {&_program, name, data});
		_renderer(_program._assign_float2);
	}
	void infi_program_t::Bind::uniform(const std::string& name, const core::vec3& data) {
		_program._assign_float3.push(_renderer.state(), {&_program, name, data});
		_renderer(_program._assign_float3);
	}
	void infi_program_t::Bind::uniform(const std::string& name, const core::vec4& data) {
		_program._assign_float4.push(_renderer.state(), {&_program, name, data});
		_renderer(_program._assign_float4);
	}
	void infi_program_t::Bind::uniform(const std::string& name, const core::mat2& data) {
		_program._assign_float2x2.push(_renderer.state(), {&_program, name, data});
		_renderer(_program._assign_float2x2);
	}
	void infi_program_t::Bind::uniform(const std::string& name, const core::mat3& data) {
		_program._assign_float3x3.push(_renderer.state(), {&_program, name, data});
		_renderer(_program._assign_float3x3);
	}
	void infi_program_t::Bind::uniform(const std::string& name, const core::mat4& data) {
		_program._assign_float4x4.push(_renderer.state(), {&_program, name, data});
		_renderer(_program._assign_float4x4);
	}

	infi_program_t::assign_uniform infi_program_t::Bind::operator[](const std::string& str) {
		return assign_uniform(*this, str);
	}

	void infi_program_t::Bind::draw(infi_buffer_object_t& arrays) {
		infi_buffer_object_t::Bind bind_Buffer(_renderer, arrays, GL_ARRAY_BUFFER);
		infi_vertex_format_t::Bind bind_Format(_renderer, _program.format);

		_program._draw_arrays.push(_renderer.state(), {GL_TRIANGLES, &arrays, &_program.format});
		_renderer(_program._draw_arrays);
	}
	void infi_program_t::Bind::draw(infi_buffer_object_t& arrays, infi_buffer_object_t& indices) {

	}

	uint32 infi_program_t::__get_uniform(const std::string& name) {
		std::unordered_map<std::string, uint32>::iterator i = _uniforms.find(name);
		if ( i == _uniforms.end() ) {
			Error::send<Error::Fatality::Fatal>(
				Error::Type::Index,
				"Could not find uniform location \"%s\"!",
				name.c_str()
			);
		}
		return (*i).second;
	}
	uint32 infi_program_t::__get_attribute(const std::string& name) {
		std::unordered_map<std::string, uint32>::iterator i = _attributes.find(name);
		if ( i == _attributes.end() ) {
			Error::send<Error::Fatality::Fatal>(
				Error::Type::Index,
				"Could not find attribute location \"%s\"!",
				name.c_str()
			);
		}
		return (*i).second;
	}

	infi_program_t::infi_program_t() :
		infi_resource_t(0),
		_linked(0),
		vertex(NULL),
		fragment(NULL) { ; }
	infi_program_t::infi_program_t(infi_renderer_t& r) :
		infi_resource_t(r.createProgram()),
		_linked(0),
		vertex(NULL),
		fragment(NULL) { ; }

	void infi_program_t::create(infi_synchronized_renderer_t& renderer) {
		infi_synchronized_renderer_t::Acquire r(renderer);
		_handle = r -> createProgram();
	}

	bool infi_program_t::ready() const {
		return (_linked == 2);
	}

	infi_render_async_t infi_program_t::link(infi_renderer_t& r) {
		if ( _linked != 0 ) {
			//Error::define_scope __scope__("infi_program_t.link");
			Error::send<Error::Fatality::Method>(
				Error::Type::Init,
				"Program has already been linked!"
			);
		}
		if ( vertex == NULL ) {
			//Error::define_scope __scope__("infi_program_t.link");
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"Program must have a vertex shader defined!"
			);
		}
		_linker.push(r.state(), this);
		infi_render_async_t next(r, _linker);

		_linked ++ ;

		return next;
	}

} }