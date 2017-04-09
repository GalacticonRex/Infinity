#include "depend/infi_sdl.hpp"
#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_enum.hpp"
#include "render/gl/infi_gl_context.hpp"
#include "render/gl/infi_gl_context_controller.hpp"

namespace Infinity {
namespace Render {

	infi_gl_t::infi_gl_t( infi_gl_init_t& ini, std::ofstream& err ) :
		_output_log(err),
		_trace_on(false),
		_start(Time::Now()),
		_write_to_log(_output_log),
		extensions(*this),
		version(extensions.version) {
		_output_log << " --- DONE INITIALIZING OPENGL ELEMENTS -----------------" << std::endl;
	}

	void infi_gl_t::Debug_ActivateTrace() {
		_trace_on = true;
		_output_log << " --- ENABLED GL TRACE @ " << (Time::Now()-_start).count() / 1000000000 << " -----------------" << std::endl;
		_output_log << "                TIME | OPERATION" << std::endl;
	}
	void infi_gl_t::Debug_DeactivateTrace() {
		_trace_on = false;
		_output_log << " --- DISABLED GL TRACE @ " << (Time::Now()-_start).count() / 1000000000 << " ----------------" << std::endl;
	}
	void infi_gl_t::Debug_SendMessage( const std::string& msg ) const {
		if ( _trace_on )
			_output_log << std::fixed
						<< std::setprecision( 8 )
						<< std::setw(20)
						<< (Time::Now()-_start).count() / 1000000000
						<< " | " << msg << std::endl;
	}
	void infi_gl_t::Debug_SendWhitespace( uint32 lines ) const {
		if ( _trace_on )
			for ( uint32 i=0;i<lines;i++ )
				_output_log << std::endl;
	}

	// general texture functions
	void infi_gl_t::ActiveTexture( uint32 tex ) const {
		glActiveTexture(tex);
		__log_operation(_start, _output_log, _trace_on, "glActiveTexture(%d)", tex);
	}
	void infi_gl_t::DeleteTextures( uint32 count, const uint32* objs ) const {
		glDeleteTextures(count, objs);
		__log_operation(_start, _output_log, _trace_on, "glDeleteTextures(%d, %p)", count, objs);
	}
	void infi_gl_t::GenTextures( uint32 count, uint32* output ) const {
		glGenTextures(count, output);
		__log_operation(_start, _output_log, _trace_on, "glGenTextures(%d, %p)", count, output);
	}
	void infi_gl_t::GenerateMipmap() const {
		glGenerateMipmap(GL_TEXTURE_2D);
		__log_operation(_start, _output_log, _trace_on, "glGenerateMipmap()" );
	}

	// GL_TEXTURE_2D functions
	void infi_gl_t::BindTexture( uint32 tex ) const {
		glBindTexture(GL_TEXTURE_2D, tex);
		__log_operation(_start, _output_log, _trace_on, "glBindTexture(%d)", tex);
	}
	void infi_gl_t::GetTexImage( int32 level, GLenum format, GLenum type, void* pixels ) const {
		glGetTexImage(GL_TEXTURE_2D, level, format, type, pixels);
		__log_operation(_start, _output_log, _trace_on, "glGetTexImage(%d, %s, %s, %p)", level, glenum(format), glenum(type), pixels);
	}
	void infi_gl_t::TexImage( int32 level, GLenum internalFormat, uint32 width, uint32 height, GLenum format, GLenum type, const void* data ) const {
		glTexImage2D(GL_TEXTURE_2D, level, internalFormat, width, height, 0, format, type, data);
		__log_operation(_start, _output_log, _trace_on, "glTexImage(%d, %s, %d, %d, %s, %s, %p)", level, glenum(internalFormat), width, height, glenum(format), glenum(type), data);
	}
	void infi_gl_t::TexParameterf( GLenum pname, float32 param ) const {
		glTexParameterf(GL_TEXTURE_2D, pname, param);
		__log_operation(_start, _output_log, _trace_on, "glTexParameterf(%s, %f)", glenum(pname), param);
	}
	void infi_gl_t::TexParameterf( GLenum pname, float32* param ) const {
		glTexParameterfv(GL_TEXTURE_2D, pname, param);
		__log_operation(_start, _output_log, _trace_on, "glTexParameterf(%s, %p)", glenum(pname), param);
	}
	void infi_gl_t::TexParameteri( GLenum pname, int32 param ) const {
		glTexParameteri(GL_TEXTURE_2D, pname, param);
		__log_operation(_start, _output_log, _trace_on, "glTexParameteri(%s, %d)", glenum(pname), param);
	}
	void infi_gl_t::TexParameteri( GLenum pname, int32* param ) const {
		glTexParameteriv(GL_TEXTURE_2D, pname, param);
		__log_operation(_start, _output_log, _trace_on, "glTexParameteri(%s, %p)", glenum(pname), param);
	}
	void infi_gl_t::TexStorage( uint32 levels, GLenum format, uint32 w, uint32 h ) const {
		glTexStorage2D(GL_TEXTURE_2D, levels, format, w, h);
		__log_operation(_start, _output_log, _trace_on, "glTexStorage(%d, %s, %d, %d)", levels, glenum(format), w, h);
	}
	void infi_gl_t::TexSubImage( uint32 level, int32 offx, int32 offy, uint32 w, uint32 h, GLenum format, GLenum type, const void* pixels ) const {
		glTexSubImage2D(GL_TEXTURE_2D, level, offx, offy, w, h, format, type, pixels);
		__log_operation(_start, _output_log, _trace_on, "glTexSubImage()");
	}

	// GL_TEXTURE_2D_MULTISAMPLE functions
	void infi_gl_t::BindTextureMultisample( uint32 tex ) const {
		glBindTexture(GL_TEXTURE_2D_MULTISAMPLE , tex);
		__log_operation(_start, _output_log, _trace_on, "glBindTextureMultisample()");
	}
	void infi_gl_t::TexImageMultisample( uint32 samples, GLint format, uint32 width, uint32 height, bool fixloc ) const {
		//glTexImage2D(GL_TEXTURE_2D_MULTISAMPLE, samples, format, width, height, fixloc);
		__log_operation(_start, _output_log, _trace_on, "glTexImageMultisample()");
	}
	void infi_gl_t::TexParameterMultisamplef( GLenum pname, float32 param ) const {
		glTexParameterf(GL_TEXTURE_2D_MULTISAMPLE, pname, param);
		__log_operation(_start, _output_log, _trace_on, "glTexParameterMultisamplef()");
	}
	void infi_gl_t::TexParameterMultisamplef( GLenum pname, float32* param ) const {
		glTexParameterfv(GL_TEXTURE_2D_MULTISAMPLE, pname, param);
		__log_operation(_start, _output_log, _trace_on, "glTexParameterMultisamplef()");
	}
	void infi_gl_t::TexParameterMultisamplei( GLenum pname, int32 param ) const {
		glTexParameteri(GL_TEXTURE_2D_MULTISAMPLE, pname, param);
		__log_operation(_start, _output_log, _trace_on, "glTexParameterMultisamplei()");
	}
	void infi_gl_t::TexParameterMultisamplei( GLenum pname, int32* param ) const {
		glTexParameteriv(GL_TEXTURE_2D_MULTISAMPLE, pname, param);
		__log_operation(_start, _output_log, _trace_on, "glTexParameterMultisamplei()");
	}

	// create bind and link shaders
	uint32 infi_gl_t::CreateProgram() const {
		uint32 i = glCreateProgram();
		__log_operation(_start, _output_log, _trace_on, "glCreateProgram() = %d", i);
		return i;
	}
	uint32 infi_gl_t::CreateShader( GLenum type ) const {
		uint32 i = glCreateShader(type);
		__log_operation(_start, _output_log, _trace_on, "glCreateShader(%s) = %d", glenum(type), i);
		return i;
	}
	int32 infi_gl_t::GetAttribLocation( uint32 prog, const char* name ) const {
		int32 i = glGetAttribLocation(prog, name);
		__log_operation(_start, _output_log, _trace_on, "glGetAttribLocation(%d, %s) = %d", prog, name, i);
		return i;
	}
	int32 infi_gl_t::GetFragDataLocation( uint32 prog, const char* fragname ) const {
		int32 i = glGetFragDataLocation(prog, fragname);
		__log_operation(_start, _output_log, _trace_on, "glGetFragDataLocation(%d, %s) = %d", prog, fragname, i);
		return i;
	}
	int32 infi_gl_t::GetUniformLocation( uint32 prog, const char* name ) const {
		int32 i = glGetUniformLocation(prog, name);
		__log_operation(_start, _output_log, _trace_on, "glGetUniformLocation(%d, %s) = %d", prog, name, i);
		return i;
	}

	void infi_gl_t::AttachShader( uint32 prog, uint32 comp ) const {
		glAttachShader(prog, comp);
		__log_operation(_start, _output_log, _trace_on, "glAttachShader(%d, %d)", prog, comp);
	}
	void infi_gl_t::BindAttribLocation( uint32 prog, uint32 attrib, const char* str ) const {
		glBindAttribLocation(prog, attrib, str);
		__log_operation(_start, _output_log, _trace_on, "glBindAttribLocation()");
	}
	void infi_gl_t::BindFragDataLocation( uint32 prog, uint32 location, const char* fragname ) const {
		glBindFragDataLocation(prog, location, fragname);
		__log_operation(_start, _output_log, _trace_on, "glBindFragDataLocation()");
	}
	void infi_gl_t::CompileShader( uint32 shader ) const {
		glCompileShader(shader);
		__log_operation(_start, _output_log, _trace_on, "glCompileShader(%d)", shader);
	}
	void infi_gl_t::DeleteProgram( uint32 prog ) const {
		glDeleteProgram(prog);
		__log_operation(_start, _output_log, _trace_on, "glDeleteProgram()");
	}
	void infi_gl_t::DeleteShader( uint32 shader ) const {
		glDeleteShader(shader);
		__log_operation(_start, _output_log, _trace_on, "glDeleteShader(%d)", shader);
	}
	void infi_gl_t::DetachShader( uint32 prog, uint32 shader ) const {
		glDetachShader(prog, shader);
		__log_operation(_start, _output_log, _trace_on, "glDetachShader()");
	}
	void infi_gl_t::GetActiveAttrib( uint32 prog, uint32 index, uint32 bufsize, int32* length, int32* size, GLenum* type, char* name ) const {
		glGetActiveAttrib(prog, index, bufsize, length, size, type, name);
		__log_operation(_start, _output_log, _trace_on, "glGetActiveAttrib(%d, %d, %d, out %d, out %d, out %s, out %s)",
														prog, index, bufsize, *length, *size, glenum(*type), name);
	}
	void infi_gl_t::GetActiveUniform( uint32 prog, uint32 index, uint32 bufsize, int32* length, int32* size, GLenum* type, char* name ) const {
		glGetActiveUniform(prog, index, bufsize, length, size, type, name);
		__log_operation(_start, _output_log, _trace_on, "glGetActiveUniform(%d, %d, %d, out %d, out %d, out %s, out %s)",
														prog, index, bufsize, *length, *size, glenum(*type), name);
	}
	void infi_gl_t::GetProgramiv( uint32 prog, GLenum pname, int32* output ) const {
		glGetProgramiv(prog, pname, output);
		__log_operation(_start, _output_log, _trace_on, "glGetProgramiv(%d, %s, %p)", prog, glenum(pname), output);
	}
	void infi_gl_t::GetProgramInfoLog( uint32 prog, uint32 maxlen, int32* len, char* output ) const {
		glGetProgramInfoLog(prog, maxlen, len, output);
		__log_operation(_start, _output_log, _trace_on, "glGetProgramInfoLog()");
	}
	void infi_gl_t::GetShaderiv( uint32 shad, GLenum pname, int32* output ) const {
		glGetShaderiv(shad, pname, output);
		__log_operation(_start, _output_log, _trace_on, "glGetShaderiv(%d, %s, %p)", shad, glenum(pname), output);
	}
	void infi_gl_t::GetShaderInfoLog( uint32 shad, uint32 maxlen, int32* len, char* output ) const {
		glGetShaderInfoLog(shad, maxlen, len, output);
		__log_operation(_start, _output_log, _trace_on, "glGetShaderInfoLog()");
	}
	void infi_gl_t::LinkProgram( uint32 prog ) const {
		glLinkProgram(prog);
		__log_operation(_start, _output_log, _trace_on, "glLinkProgram(%d)", prog);
	}
	void infi_gl_t::ShaderSource( uint32 shad, uint32 count, const char** str, const int32* length ) const {
		glShaderSource(shad, count, str, length);
		__log_operation(_start, _output_log, _trace_on, "glShaderSource(%d, %d, %p, %p)", shad, count, str, length);
	}
	void infi_gl_t::UseProgram( uint32 prog ) const {
		glUseProgram(prog);
		__log_operation(_start, _output_log, _trace_on, "glUseProgram(%d)", prog);
	}

	// shader uniforms
	void infi_gl_t::Uniformf( uint32 location, float32 a ) const {
		glUniform1f(location, a);
		__log_operation(_start, _output_log, _trace_on, "glUniformf(%d, %f)", location, a);
	}
	void infi_gl_t::Uniformf( uint32 location, float32 a, float32 b ) const {
		glUniform2f(location, a, b);
		__log_operation(_start, _output_log, _trace_on, "glUniformf(%d, %f, %f)", location, a, b);
	}
	void infi_gl_t::Uniformf( uint32 location, float32 a, float32 b, float32 c ) const {
		glUniform3f(location, a, b, c);
		__log_operation(_start, _output_log, _trace_on, "glUniformf(%d, %f, %f, %f)", location, a, b, c);
	}
	void infi_gl_t::Uniformf( uint32 location, float32 a, float32 b, float32 c, float32 d ) const {
		glUniform4f(location, a, b, c, d);
		__log_operation(_start, _output_log, _trace_on, "glUniformf(%d, %f, %f, %f, %f)", location, a, b, c, d);
	}
	void infi_gl_t::Uniformf( uint32 location, const core::vec2& v ) const {
		glUniform2f(location, v.x, v.y);
		__log_operation(_start, _output_log, _trace_on, "glUniformf(%d, %f, %f)", location, v.x, v.y);
	}
	void infi_gl_t::Uniformf( uint32 location, const core::vec3& v ) const {
		glUniform3f(location, v.x, v.y, v.z);
		__log_operation(_start, _output_log, _trace_on, "glUniformf(%d, %f, %f, %f)", location, v.x, v.y, v.z);
	}
	void infi_gl_t::Uniformf( uint32 location, const core::vec4& v ) const {
		glUniform4f(location, v.x, v.y, v.z, v.w);
		__log_operation(_start, _output_log, _trace_on, "glUniformf(%d, %f, %f, %f, %f)", location, v.x, v.y, v.z, v.w);
	}
	void infi_gl_t::Uniformfv( uint32 location, uint32 c, const float32* a ) const {
		glUniform1fv(location, c, a);
		__log_operation(_start, _output_log, _trace_on, "glUniformfv()");
	}
	void infi_gl_t::Uniformfv( uint32 location, uint32 c, const core::vec2* v ) const {
		glUniform2fv(location, c, (const float32*)v);
		__log_operation(_start, _output_log, _trace_on, "glUniformfv()");
	}
	void infi_gl_t::Uniformfv( uint32 location, uint32 c, const core::vec3* v ) const {
		glUniform3fv(location, c, (const float32*)v);
		__log_operation(_start, _output_log, _trace_on, "glUniformfv()");
	}
	void infi_gl_t::Uniformfv( uint32 location, uint32 c, const core::vec4* v ) const {
		glUniform4fv(location, c, (const float32*)v);
		__log_operation(_start, _output_log, _trace_on, "glUniformfv()");
	}
	void infi_gl_t::Uniformi( uint32 location, int32 a ) const {
		glUniform1i(location, a);
		__log_operation(_start, _output_log, _trace_on, "glUniformi(%d, %d)", location, a);
	}
	void infi_gl_t::Uniformi( uint32 location, int32 a, int32 b ) const {
		glUniform2i(location, a, b);
		__log_operation(_start, _output_log, _trace_on, "glUniformi(%d, %d, %d)", location, a, b);
	}
	void infi_gl_t::Uniformi( uint32 location, int32 a, int32 b, int32 c ) const {
		glUniform3i(location, a, b, c);
		__log_operation(_start, _output_log, _trace_on, "glUniformi(%d, %d, %d, %d)", location, a, b, c);
	}
	void infi_gl_t::Uniformi( uint32 location, int32 a, int32 b, int32 c, int32 d ) const {
		glUniform4i(location, a, b, c, d);
		__log_operation(_start, _output_log, _trace_on, "glUniformi(%d, %d, %d, %d, %d)", location, a, b, c, d);
	}
	void infi_gl_t::Uniformi( uint32 location, const core::vec2i& v ) const {
		glUniform2i(location, v.x, v.y);
		__log_operation(_start, _output_log, _trace_on, "glUniformi()");
	}
	void infi_gl_t::Uniformi( uint32 location, const core::vec3i& v ) const {
		glUniform3i(location, v.x, v.y, v.z);
		__log_operation(_start, _output_log, _trace_on, "glUniformi()");
	}
	void infi_gl_t::Uniformi( uint32 location, const core::vec4i& v ) const {
		glUniform4i(location, v.x, v.y, v.z, v.w);
		__log_operation(_start, _output_log, _trace_on, "glUniformi()");
	}
	void infi_gl_t::Uniformiv( uint32 location, uint32 c, const int32* a ) const {
		glUniform1iv(location, c, a);
		__log_operation(_start, _output_log, _trace_on, "glUniformiv()");
	}
	void infi_gl_t::Uniformiv( uint32 location, uint32 c, const core::vec2i* v ) const {
		glUniform2iv(location, c, (const int32*)v);
		__log_operation(_start, _output_log, _trace_on, "glUniformiv()");
	}
	void infi_gl_t::Uniformiv( uint32 location, uint32 c, const core::vec3i* v ) const {
		glUniform3iv(location, c, (const int32*)v);
		__log_operation(_start, _output_log, _trace_on, "glUniformiv()");
	}
	void infi_gl_t::Uniformiv( uint32 location, uint32 c, const core::vec4i* v ) const {
		glUniform4iv(location, c, (const int32*)v);
		__log_operation(_start, _output_log, _trace_on, "glUniformiv()");
	}
	void infi_gl_t::Uniformui( uint32 location, uint32 a ) const {
		glUniform1ui(location, a);
		__log_operation(_start, _output_log, _trace_on, "glUniformui()");
	}
	void infi_gl_t::Uniformui( uint32 location, uint32 a, uint32 b ) const {
		glUniform2ui(location, a, b);
		__log_operation(_start, _output_log, _trace_on, "glUniformui()");
	}
	void infi_gl_t::Uniformui( uint32 location, uint32 a, uint32 b, uint32 c ) const {
		glUniform3ui(location, a, b, c);
		__log_operation(_start, _output_log, _trace_on, "glUniformui()");
	}
	void infi_gl_t::Uniformui( uint32 location, uint32 a, uint32 b, uint32 c, uint32 d ) const {
		glUniform4ui(location, a, b, c, d);
		__log_operation(_start, _output_log, _trace_on, "glUniformui()");
	}
	void infi_gl_t::Uniformui( uint32 location, const core::vec2ui& v ) const {
		glUniform2ui(location, v.x, v.y);
		__log_operation(_start, _output_log, _trace_on, "glUniformui()");
	}
	void infi_gl_t::Uniformui( uint32 location, const core::vec3ui& v ) const {
		glUniform3ui(location, v.x, v.y, v.z);
		__log_operation(_start, _output_log, _trace_on, "glUniformui()");
	}
	void infi_gl_t::Uniformui( uint32 location, const core::vec4ui& v ) const {
		glUniform4ui(location, v.x, v.y, v.z, v.w);
		__log_operation(_start, _output_log, _trace_on, "glUniformui()");
	}
	void infi_gl_t::Uniformuiv( uint32 location, uint32 c, const uint32* a ) const {
		glUniform1uiv(location, c, a);
		__log_operation(_start, _output_log, _trace_on, "glUniformuiv()");
	}
	void infi_gl_t::Uniformuiv( uint32 location, uint32 c, const core::vec2ui* v ) const {
		glUniform2uiv(location, c, (const uint32*)v);
		__log_operation(_start, _output_log, _trace_on, "glUniformuiv()");
	}
	void infi_gl_t::Uniformuiv( uint32 location, uint32 c, const core::vec3ui* v ) const {
		glUniform3uiv(location, c, (const uint32*)v);
		__log_operation(_start, _output_log, _trace_on, "glUniformuiv()");
	}
	void infi_gl_t::Uniformuiv( uint32 location, uint32 c, const core::vec4ui* v ) const {
		glUniform4uiv(location, c, (const uint32*)v);
		__log_operation(_start, _output_log, _trace_on, "glUniformuiv()");
	}
	void infi_gl_t::Uniform( uint32 location, const core::mat2& m ) const {
		glUniformMatrix2fv(location, 1, false, (const float32*)&m);
		__log_operation(_start, _output_log, _trace_on, "glUniform(%d, [%f,%f],[%f,%f])", location,
														m(0,0), m(0,1), 
														m(1,0), m(1,1) );
	}
	void infi_gl_t::Uniform( uint32 location, const core::mat3& m ) const {
		glUniformMatrix3fv(location, 1, false, (const float32*)&m);
		__log_operation(_start, _output_log, _trace_on, "glUniform(%d, [%f,%f,%f],[%f,%f,%f],[%f,%f,%f])", location,
														m(0,0), m(0,1), m(0,2),
														m(1,0), m(1,1), m(1,2),
														m(2,0), m(2,1), m(2,2) );
	}
	void infi_gl_t::Uniform( uint32 location, const core::mat4& m ) const {
		glUniformMatrix4fv(location, 1, false, (const float32*)&m);
		__log_operation(_start, _output_log, _trace_on, "glUniform(%d, [%f,%f,%f,%f],[%f,%f,%f,%f],[%f,%f,%f,%f],[%f,%f,%f,%f])", location,
														m(0,0), m(0,1), m(0,2), m(0,3),
														m(1,0), m(1,1), m(1,2), m(1,3),
														m(2,0), m(2,1), m(2,2), m(2,3),
														m(3,0), m(3,1), m(3,2), m(3,3) );
	}
	void infi_gl_t::Uniformv( uint32 location, uint32 count, const core::mat2* m ) const {
		glUniformMatrix2fv(location, count, false, (const float32*)m);
		__log_operation(_start, _output_log, _trace_on, "glUniformv()");
	}
	void infi_gl_t::Uniformv( uint32 location, uint32 count, const core::mat3* m ) const {
		glUniformMatrix2fv(location, count, false, (const float32*)m);
		__log_operation(_start, _output_log, _trace_on, "glUniformv()");
	}
	void infi_gl_t::Uniformv( uint32 location, uint32 count, const core::mat4* m ) const {
		glUniformMatrix2fv(location, count, false, (const float32*)m);
		__log_operation(_start, _output_log, _trace_on, "glUniformv()");
	}

	// blending functions
	void infi_gl_t::BlendColor( float32 r, float32 g, float32 b, float32 a ) const {
		glBlendColor(r, g, b, a);
		__log_operation(_start, _output_log, _trace_on, "glBlendColor(%f, %f, %f, %f)", r, g, b, a);
	}
	void infi_gl_t::BlendEquation( GLenum mode ) const {
		glBlendEquation(mode);
		__log_operation(_start, _output_log, _trace_on, "glBlendEquation(%s)", glenum(mode));
	}
	void infi_gl_t::BlendEquationSeparate( GLenum modea, GLenum modec ) const {
		glBlendEquationSeparate(modea, modec);
		__log_operation(_start, _output_log, _trace_on, "glBlendEquationSeparate(%s, %s)", glenum(modea), glenum(modec));
	}
	void infi_gl_t::BlendFunc( GLenum sfactor, GLenum dfactor ) const {
		glBlendFunc(sfactor, dfactor);
		__log_operation(_start, _output_log, _trace_on, "glBlendFunc(%s, %s)", glenum(sfactor), glenum(dfactor));
	}
	void infi_gl_t::BlendFuncSeparate( GLenum sc, GLenum dc, GLenum sa, GLenum da ) const {
		glBlendFuncSeparate(sc, dc, sa, da);
		__log_operation(_start, _output_log, _trace_on, "glBlendFuncSeparate(%s, %s, %s, %s)", glenum(sc), glenum(dc), glenum(sa), glenum(da));
	}

	// buffer control functions
	void infi_gl_t::BindBuffer( uint32 buf, uint32 obj ) const {
		glBindBuffer(buf, obj);
		__log_operation(_start, _output_log, _trace_on, "glBindBuffer(%s, %d)", glenum(buf), obj);
	}
	void infi_gl_t::BindBufferBase( uint32 buf, uint32 slot, uint32 obj ) const {
		glBindBufferBase(buf, slot, obj);
		__log_operation(_start, _output_log, _trace_on, "glBindBufferBase()");
	}
	void infi_gl_t::BufferData( GLenum buf, uint32 sz, const void* data, GLenum readtype ) const {
		glBufferData(buf, sz, data, readtype);
		__log_operation(_start, _output_log, _trace_on, "glBufferData(%s, %d, %p, %s)", glenum(buf), sz, data, glenum(readtype));
	}
	void infi_gl_t::BufferSubData( GLenum buf, uint32 offset, uint32 size, const void* data ) const {
		glBufferSubData(buf, offset, size, data);
		__log_operation(_start, _output_log, _trace_on, "glBufferSubData()");
	}
	void infi_gl_t::CopyBufferSubData( GLenum r, GLenum w, int32 roff, int32 woff, int32 sz ) const {
		glCopyBufferSubData(r, w, roff, woff, sz);
		__log_operation(_start, _output_log, _trace_on, "glCopyBufferSubData()");
	}
	void infi_gl_t::DeleteBuffers( uint32 count, const uint32* objs ) const {
		glDeleteBuffers(count, objs);
		__log_operation(_start, _output_log, _trace_on, "glDeleteBuffers()");
	}
	void infi_gl_t::GenBuffers( uint32 count, uint32* output ) const {
		glGenBuffers(count, output);
		__log_operation(_start, _output_log, _trace_on, "glGenBuffers(%d, %p)", count, output);
	}
	void infi_gl_t::GetBufferSubData( GLenum target, int32 offset, int32 size, void* output ) const {
		glGetBufferSubData(target, offset, size, output);
		__log_operation(_start, _output_log, _trace_on, "glGetBufferSubData()");
	}
	void* infi_gl_t::MapBuffer( GLenum target, GLenum access ) const {
		void* i = glMapBuffer(target, access);
		__log_operation(_start, _output_log, _trace_on, "%p = glMapBuffer(%s, %s)", i, glenum(target), glenum(access));
		return i;
	}
	void* infi_gl_t::MapBufferRange( GLenum target, int32 offset, uint32 length, GLbitfield access ) const {
		void* i = glMapBufferRange(target, offset, length, access);
		__log_operation(_start, _output_log, _trace_on, "%p = glMapBufferRange(%s, %d, %d, %x)", i, glenum(target), offset, length, access);
		return i;
	}
	void infi_gl_t::UnmapBuffer( GLenum target ) const {
		glUnmapBuffer(target);
		__log_operation(_start, _output_log, _trace_on, "glUnmapBuffer()");
	}

	// framebuffer control functions
	void infi_gl_t::BindFramebuffer( uint32 obj ) const {
		glBindFramebuffer(GL_FRAMEBUFFER, obj);
		__log_operation(_start, _output_log, _trace_on, "glBindFramebuffer(%d)", obj);
	}
	void infi_gl_t::BindFramebufferDraw( uint32 obj ) const {
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, obj);
		__log_operation(_start, _output_log, _trace_on, "glBindFramebufferDraw()");
	}
	void infi_gl_t::BindFramebufferRead( uint32 obj ) const {
		glBindFramebuffer(GL_READ_FRAMEBUFFER, obj);
		__log_operation(_start, _output_log, _trace_on, "glBindFramebufferRead()");
	}
	void infi_gl_t::BlitFramebuffer( int32 srcx0, int32 srcy0, int32 srcx1, int32 srcy1, int32 dstx0, int32 dsty0, int32 dstx1, int32 dsty1, uint32 mask, GLenum filter ) const {
		glBlitFramebuffer(srcx0, srcy0, srcx1, srcy1, dstx0, dsty0, dstx1, dsty1, mask, filter);
		__log_operation(_start, _output_log, _trace_on, "glBlitFramebuffer()");
	}
	GLenum infi_gl_t::CheckFramebufferStatus() const {
		GLenum i = glCheckFramebufferStatus(GL_FRAMEBUFFER);
		__log_operation(_start, _output_log, _trace_on, "glCheckFramebufferStatus() = %s", glenum(i));
		return i;
	}
	void infi_gl_t::Clear( GLenum channels ) const {
		glClear(channels);
		__log_operation(_start, _output_log, _trace_on, "glClear(%x)", channels);
	}
	void infi_gl_t::ClearColor( float32 r, float32 g, float32 b, float32 a ) const {
		glClearColor(r, g, b, a);
		__log_operation(_start, _output_log, _trace_on, "glClearColor(%f, %f, %f, %f)", r, g, b, a);
	}
	void infi_gl_t::DeleteFramebuffers( uint32 count, const uint32* objs ) const {
		glDeleteFramebuffers(count, objs);
		__log_operation(_start, _output_log, _trace_on, "glDeleteFramebuffers()");
	}
	void infi_gl_t::DrawBuffer( GLenum buf ) const {
		glDrawBuffer(buf);
		__log_operation(_start, _output_log, _trace_on, "glDrawBuffer()");
	}
	void infi_gl_t::DrawBuffers( uint32 count, GLenum* buffers ) const {
		glDrawBuffers(count, buffers);
		__log_operation(_start, _output_log, _trace_on, "glDrawBuffers()");
	}
	void infi_gl_t::FramebufferTexture( GLenum attachment, uint32 tex, int32 level ) const {
		glFramebufferTexture(GL_FRAMEBUFFER, attachment, tex, level);
		__log_operation(_start, _output_log, _trace_on, "glFramebufferTexture(%s, %d, %d)", glenum(attachment), tex, level);
	}
	void infi_gl_t::GenFramebuffers( uint32 count, uint32* output ) const {
		glGenFramebuffers(count, output);
		__log_operation(_start, _output_log, _trace_on, "glGenFramebuffers()");
	}

	void infi_gl_t::BindRenderbuffer( uint32 obj ) const {
		glBindRenderbuffer(GL_RENDERBUFFER, obj);
		__log_operation(_start, _output_log, _trace_on, "glBindRenderbuffer()");
	}
	void infi_gl_t::DeleteRenderbuffers( uint32 count, const uint32* objs ) const {
		glDeleteRenderbuffers(count, objs);
		__log_operation(_start, _output_log, _trace_on, "glDeleteRenderbuffers()");
	}
	void infi_gl_t::FramebufferRenderbuffer( GLenum attachment, uint32 buffer ) const {
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, buffer);
		__log_operation(_start, _output_log, _trace_on, "glFramebufferRenderbuffer()");
	}
	void infi_gl_t::GenRenderbuffers( uint32 count, uint32* output ) const {
		glGenRenderbuffers(count, output);
		__log_operation(_start, _output_log, _trace_on, "glGenRenderbuffers()");
	}
	void infi_gl_t::RenderbufferStorage( GLenum format, uint32 width, uint32 height ) const {
		glRenderbufferStorage(GL_RENDERBUFFER, format, width, height);
		__log_operation(_start, _output_log, _trace_on, "glRenderbufferStorage()");
	}
	void infi_gl_t::RenderbufferStorageMultisample( uint32 samples, GLenum format, uint32 width, uint32 height ) const {
		glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, format, width, height);
		__log_operation(_start, _output_log, _trace_on, "glRenderbufferStorageMultisample()");
	}

	// vertex array functions
	void infi_gl_t::DisableVertexAttribArray( uint32 chan ) const {
		glDisableVertexAttribArray(chan);
		__log_operation(_start, _output_log, _trace_on, "glDisableVertexAttribArray(%d)", chan);
	}
	void infi_gl_t::DrawArrays( GLenum style, uint32 start, uint32 count ) const {
		glDrawArrays(style, start, count);
		__log_operation(_start, _output_log, _trace_on, "glDrawArrays(%s, %d, %d)", glenum(style), start, count);
	}
	void infi_gl_t::DrawArraysInstanced( GLenum style, uint32 start, uint32 count, uint32 prim ) const {
		glDrawArraysInstanced(style, start, count, prim);
		__log_operation(_start, _output_log, _trace_on, "glDrawArraysInstanced()");
	}
	void infi_gl_t::DrawElements( GLenum style, uint32 count, GLenum type, void* offset ) const {
		glDrawElements(style, count, type, offset);
		__log_operation(_start, _output_log, _trace_on, "glDrawElements()");
	}
	void infi_gl_t::DrawElementsBaseVertex( GLenum style, uint32 count, GLenum type, void* offset, uint32 base ) const {
		glDrawElementsBaseVertex(style, count, type, offset, base);
		__log_operation(_start, _output_log, _trace_on, "glDrawElementsBaseVertex()");
	}
	void infi_gl_t::DrawElementsInstanced( GLenum style, uint32 count, GLenum type, void* offset, uint32 prim ) const {
		glDrawElementsInstanced(style, count, type, offset, prim);
		__log_operation(_start, _output_log, _trace_on, "glDrawElementsInstanced()");
	}
	void infi_gl_t::DrawElementsInstancedBaseVertex( GLenum style, uint32 count, GLenum type, void* offset, uint32 prim, uint32 base ) const {
		glDrawElementsInstancedBaseVertex(style, count, type, offset, prim, base);
		__log_operation(_start, _output_log, _trace_on, "glDrawElementsInstancedBaseVertex()");
	}
	void infi_gl_t::EnableVertexAttribArray( uint32 chan ) const {
		glEnableVertexAttribArray(chan);
		__log_operation(_start, _output_log, _trace_on, "glEnableVertexAttribArray(%d)", chan);
	}
	void infi_gl_t::VertexAttribPointer( uint32 index, int32 sz, GLenum type, bool normalized, uint32 stride, void* offset ) const {
		glVertexAttribPointer(index, sz, type, normalized, stride, offset);
		__log_operation(_start, _output_log, _trace_on, "glVertexAttribPointer(%d, %d, %s, %s, %d, %d)",
														index, sz, glenum(type), (normalized)?"True":"False", stride, offset);
	}

	void infi_gl_t::BindVertexArray( uint32 obj ) const {
		glBindVertexArray(obj);
		__log_operation(_start, _output_log, _trace_on, "glBindVertexArray(%d)", obj);
	}
	void infi_gl_t::DeleteVertexArrays( uint32 count, const uint32* objs ) const {
		glDeleteVertexArrays(count, objs);
		__log_operation(_start, _output_log, _trace_on, "glDeleteVertexArrays(%d, %p)", count, objs);
	}
	void infi_gl_t::GenVertexArrays( uint32 count, uint32* objs ) const {
		glGenVertexArrays(count, objs);
		__log_operation(_start, _output_log, _trace_on, "glGenVertexArrays(%d, %p)", count, objs);
	}

	// transform feedback functions
	void infi_gl_t::BeginTransformFeedback( GLenum style ) const {
		glBeginTransformFeedback(style);
		__log_operation(_start, _output_log, _trace_on, "glBeginTransformFeedback()");
	}
	void infi_gl_t::EndTransformFeedback() const {
		glEndTransformFeedback();
		__log_operation(_start, _output_log, _trace_on, "glEndTransformFeedback()");
	}
	void infi_gl_t::TransformFeedbackVaryings( uint32 prog, uint32 count, const char** str, GLenum mode ) const {
		glTransformFeedbackVaryings(prog, count, str, mode);
		__log_operation(_start, _output_log, _trace_on, "glTransformFeedbackVaryings()");
	}

	// query objects
	void infi_gl_t::BeginQuery( GLenum type, uint32 query ) const {
		glBeginQuery(type, query);
		__log_operation(_start, _output_log, _trace_on, "glBeginQuery()");
	}
	void infi_gl_t::DeleteQueries( uint32 count, const uint32* objs ) const {
		glDeleteQueries(count, objs);
		__log_operation(_start, _output_log, _trace_on, "glDeleteQueries()");
	}
	void infi_gl_t::EndQuery( GLenum type ) const {
		glEndQuery(type);
		__log_operation(_start, _output_log, _trace_on, "glEndQuery()");
	}
	void infi_gl_t::GenQueries( uint32 count, uint32* objs ) const {
		glGenQueries(count, objs);
		__log_operation(_start, _output_log, _trace_on, "glGenQueries()");
	}
	void infi_gl_t::GetQueryObjectiv( uint32 query, GLenum type, int32* output ) const {
		glGetQueryObjectiv(query, type, output);
		__log_operation(_start, _output_log, _trace_on, "glGetQueryObjectiv()");
	}
	void infi_gl_t::GetQueryObjectuiv( uint32 query, GLenum type, uint32* output ) const {
		glGetQueryObjectuiv(query, type, output);
		__log_operation(_start, _output_log, _trace_on, "glGetQueryObjectuiv()");
	}

	// depth stencil functions
	void infi_gl_t::ColorMask( bool r, bool g, bool b, bool a ) const {
		glColorMask(r, g, b, a);
		__log_operation(_start, _output_log, _trace_on, "glColorMask()");
	}
	void infi_gl_t::ColorMask( bool rgba ) const {
		glColorMask(rgba, rgba, rgba, rgba);
		__log_operation(_start, _output_log, _trace_on, "glColorMask()");
	}
	void infi_gl_t::DepthFunc( GLenum mode ) const {
		glDepthFunc(mode);
		__log_operation(_start, _output_log, _trace_on, "glDepthFunc(%s)", glenum(mode));
	}
	void infi_gl_t::DepthMask( bool active ) const {
		glDepthMask(active);
		__log_operation(_start, _output_log, _trace_on, "glDepthMask()");
	}
	void infi_gl_t::StencilFunc( GLenum func, int32 ref, uint32 mask ) const {
		glStencilFunc(func, ref, mask);
		__log_operation(_start, _output_log, _trace_on, "glStencilFunc()");
	}
	void infi_gl_t::StencilFuncSeparate( GLenum face, GLenum func, int32 ref, uint32 mask ) const {
		glStencilFuncSeparate(face, func, ref, mask);
		__log_operation(_start, _output_log, _trace_on, "glStencilFuncSeparate()");
	}
	void infi_gl_t::StencilMask( uint32 mask ) const {
		glStencilMask(mask);
		__log_operation(_start, _output_log, _trace_on, "glStencilMask()");
	}
	void infi_gl_t::StencilMaskSeparate( GLenum face, uint32 mask ) const {
		glStencilMaskSeparate(face, mask);
		__log_operation(_start, _output_log, _trace_on, "glStencilMaskSeparate()");
	}
	void infi_gl_t::StencilOp( GLenum sfail, GLenum dpfail, GLenum dppass ) const {
		glStencilOp(sfail, dpfail, dppass);
		__log_operation(_start, _output_log, _trace_on, "glStencilOp()");
	}
	void infi_gl_t::StencilOpSeparate( GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass ) const {
		glStencilOpSeparate(face, sfail, dpfail, dppass);
		__log_operation(_start, _output_log, _trace_on, "glStencilOpSeparate()");
	}

	// misc functions
	const uint8* infi_gl_t::GetString( GLenum name ) const {
		const uint8* i = glGetString(name);
		__log_operation(_start, _output_log, _trace_on, "glGetString(%s) = %s", glenum(name), i);
		return i;
	}
	const uint8* infi_gl_t::GetStringi( GLenum name, uint32 index ) const {
		const uint8* i = glGetStringi(name, index);
		__log_operation(_start, _output_log, _trace_on, "glGetStringi(%s, %d) = %s", glenum(name), index, i);
		return i;
	}
	bool infi_gl_t::IsEnabled( GLenum cap ) const {
		bool i = glIsEnabled(cap);
		__log_operation(_start, _output_log, _trace_on, "glIsEnabled(%s) = %s", glenum(cap), (i)?"True":"False");
		return i;
	}

	void infi_gl_t::CullFace( GLenum mode ) const {
		glCullFace(mode);
		__log_operation(_start, _output_log, _trace_on, "glCullFace(%s)", glenum(mode));
	}
	void infi_gl_t::FrontFace( GLenum mode ) const {
		glFrontFace(mode);
		__log_operation(_start, _output_log, _trace_on, "glFrontFace(%s)", glenum(mode));
	}

	void infi_gl_t::Disable( GLenum elem ) const {
		glDisable(elem);
		__log_operation(_start, _output_log, _trace_on, "glDisable(%s)", glenum(elem));
	}
	void infi_gl_t::Enable( GLenum elem ) const {
		glEnable(elem);
		__log_operation(_start, _output_log, _trace_on, "glEnable(%s)", glenum(elem));
	}
	void infi_gl_t::Flush() const {
		glFlush();
		__log_operation(_start, _output_log, _trace_on, "glFlush()");
	}
	void infi_gl_t::Finish() const {
		glFinish();
		__log_operation(_start, _output_log, _trace_on, "glFinish()");
	}
	void infi_gl_t::GetFloatv( GLenum pname, float32* output ) const {
		glGetFloatv(pname, output);
		__log_operation(_start, _output_log, _trace_on, "glGetFloatv(%d, %p)", pname, output);
	}
	void infi_gl_t::GetIntegerv( GLenum pname, int32* output ) const {
		glGetIntegerv(pname, output);
		__log_operation(_start, _output_log, _trace_on, "glGetIntegerv(%d, %p)", pname, output);
	}
	void infi_gl_t::PointSize( float32 size ) const {
		glPointSize(size);
		__log_operation(_start, _output_log, _trace_on, "glPointSize()");
	}
	void infi_gl_t::ShadeModel( GLenum mode ) const {
		glShadeModel(mode);
		__log_operation(_start, _output_log, _trace_on, "glShadeModel(%s)", glenum(mode));
	}
	void infi_gl_t::Viewport( const core::rect& r ) const {
		glViewport(r.x, r.y, r.w, r.h);
		__log_operation(_start, _output_log, _trace_on, "glViewport()");
	}
	void infi_gl_t::Viewport( int32 x, int32 y, uint32 w, uint32 h ) const {
		glViewport(x, y, w, h);
		__log_operation(_start, _output_log, _trace_on, "glViewport()");
	}

	void infi_gl_t::__log_operation(Time::Point pt, std::ofstream& output, bool inUse, const char* format, ...) const {
		char buffer[1024];

		va_list args;
		va_start( args, format );
		vsprintf( buffer, format, args );
		va_end( args );

		if ( inUse )
			output << std::fixed
				   << std::setprecision( 8 )
				   << std::setw(20)
				   << (Time::Now() - pt).count() / 1000000000
				   << " | "
				   << buffer
				   << std::endl;
		uint32 st;
		if ( (st=glGetError()) != GL_NO_ERROR ) {
			switch( st ) {
				case GL_INVALID_ENUM:
					if ( inUse )
						output << "                     | ERROR INVALID ENUM" << std::endl;
					Error::send<Error::Fatality::Method>(
						Error::Type::Graphics,
						"Invalid Enumeration in %s",
						buffer
					);
					break;
				case GL_INVALID_VALUE:
					if ( inUse )
						output << "                     | ERROR INVALID VALUE" << std::endl;
					Error::send<Error::Fatality::Method>(
						Error::Type::Graphics,
						"Invalid Value in %s",
						buffer
					);
					break;
				case GL_INVALID_OPERATION:
					if ( inUse )
						output << "                     | ERROR INVALID OPERATION" << std::endl;
					Error::send<Error::Fatality::Method>(
						Error::Type::Graphics,
						"Invalid Operation in %s",
						buffer
					);
					break;
				case GL_INVALID_FRAMEBUFFER_OPERATION:
					if ( inUse )
						output << "                     | ERROR INVALID FRAMEBUFFER OPERATION" << std::endl;
					Error::send<Error::Fatality::Method>(
						Error::Type::Graphics,
						"Invalid Framebuffer Operation in %s",
						buffer
					);
					break;
				case GL_OUT_OF_MEMORY:
					if ( inUse )
						output << "                     | ERROR OUT OF MEMORY" << std::endl;
					Error::send<Error::Fatality::Method>(
						Error::Type::Graphics,
						"Out of Memory in %s",
						buffer
					);
					break;
				case GL_STACK_UNDERFLOW:
					if ( inUse )
						output << "                     | ERROR STACK UNDERFLOW" << std::endl;
					Error::send<Error::Fatality::Method>(
						Error::Type::Graphics,
						"Stack Underflow in %s",
						buffer
					);
					break;
				case GL_STACK_OVERFLOW:
					if ( inUse )
						output << "                     | ERROR STACK OVERFLOW" << std::endl;
					Error::send<Error::Fatality::Method>(
						Error::Type::Graphics,
						"Stack Overflow in %s",
						buffer
					);
					break;
				default:
					if ( inUse )
						output << "                     | ERROR UNKNOWN" << std::endl;
					Error::send<Error::Fatality::Method>(
						Error::Type::Graphics,
						"Unknown in %s",
						buffer
					);
					break;
			}
		}

		output.flush();
	}

	infi_gl_t::__write_to_log__::__write_to_log__(std::ofstream& output) {
		output << " --- BEGIN INITIALIZING OPENGL ELEMENTS -----------------" << std::endl;
		output << "                TIME | OPERATION" << std::endl;
	}

	AttribType infi_gl_t::TYPE_BYTE = GL_BYTE;
	AttribType infi_gl_t::TYPE_UNSIGNED_BYTE = GL_UNSIGNED_BYTE;
	AttribType infi_gl_t::TYPE_SHORT = GL_SHORT;
	AttribType infi_gl_t::TYPE_UNSIGNED_SHORT = GL_UNSIGNED_SHORT;
	AttribType infi_gl_t::TYPE_INT = GL_INT;
	AttribType infi_gl_t::TYPE_UNSIGNED_INT = GL_UNSIGNED_INT;
	AttribType infi_gl_t::TYPE_HALF_FLOAT = GL_HALF_FLOAT;
	AttribType infi_gl_t::TYPE_FLOAT = GL_FLOAT;
	AttribType infi_gl_t::TYPE_DOUBLE = GL_DOUBLE;
	AttribType infi_gl_t::TYPE_FIXED = GL_FIXED;

	ShaderAttribType infi_gl_t::FLOAT_VEC1 = GL_FLOAT;
	ShaderAttribType infi_gl_t::FLOAT_VEC2 = GL_FLOAT_VEC2;
	ShaderAttribType infi_gl_t::FLOAT_VEC3 = GL_FLOAT_VEC3;
	ShaderAttribType infi_gl_t::FLOAT_VEC4 = GL_FLOAT_VEC4;
	ShaderAttribType infi_gl_t::FLOAT_MAT2 = GL_FLOAT_MAT2;
	ShaderAttribType infi_gl_t::FLOAT_MAT3 = GL_FLOAT_MAT3;
	ShaderAttribType infi_gl_t::FLOAT_MAT4 = GL_FLOAT_MAT4;
	ShaderAttribType infi_gl_t::FLOAT_MAT2x3 = GL_FLOAT_MAT2x3;
	ShaderAttribType infi_gl_t::FLOAT_MAT2x4 = GL_FLOAT_MAT2x4;
	ShaderAttribType infi_gl_t::FLOAT_MAT3x2 = GL_FLOAT_MAT3x2;
	ShaderAttribType infi_gl_t::FLOAT_MAT3x4 = GL_FLOAT_MAT3x4;
	ShaderAttribType infi_gl_t::FLOAT_MAT4x2 = GL_FLOAT_MAT4x2;
	ShaderAttribType infi_gl_t::FLOAT_MAT4x3 = GL_FLOAT_MAT4x3;
	ShaderAttribType infi_gl_t::INT_VEC1 = GL_INT;
	ShaderAttribType infi_gl_t::INT_VEC2 = GL_INT_VEC2;
	ShaderAttribType infi_gl_t::INT_VEC3 = GL_INT_VEC3;
	ShaderAttribType infi_gl_t::INT_VEC4 = GL_INT_VEC4;
	ShaderAttribType infi_gl_t::UNSIGNED_INT_VEC1 = GL_UNSIGNED_INT;
	ShaderAttribType infi_gl_t::UNSIGNED_INT_VEC2 = GL_UNSIGNED_INT_VEC2;
	ShaderAttribType infi_gl_t::UNSIGNED_INT_VEC3 = GL_UNSIGNED_INT_VEC3;
	ShaderAttribType infi_gl_t::UNSIGNED_INT_VEC4 = GL_UNSIGNED_INT_VEC4;
	ShaderAttribType infi_gl_t::DOUBLE_VEC1 = GL_DOUBLE;
	ShaderAttribType infi_gl_t::DOUBLE_VEC2 = GL_DOUBLE_VEC2;
	ShaderAttribType infi_gl_t::DOUBLE_VEC3 = GL_DOUBLE_VEC3;
	ShaderAttribType infi_gl_t::DOUBLE_VEC4 = GL_DOUBLE_VEC4;
	ShaderAttribType infi_gl_t::DOUBLE_MAT2 = GL_DOUBLE_MAT2;
	ShaderAttribType infi_gl_t::DOUBLE_MAT3 = GL_DOUBLE_MAT3;
	ShaderAttribType infi_gl_t::DOUBLE_MAT4 = GL_DOUBLE_MAT4;
	ShaderAttribType infi_gl_t::DOUBLE_MAT2x3 = GL_DOUBLE_MAT2x3;
	ShaderAttribType infi_gl_t::DOUBLE_MAT2x4 = GL_DOUBLE_MAT2x4;
	ShaderAttribType infi_gl_t::DOUBLE_MAT3x2 = GL_DOUBLE_MAT3x2;
	ShaderAttribType infi_gl_t::DOUBLE_MAT3x4 = GL_DOUBLE_MAT3x4;
	ShaderAttribType infi_gl_t::DOUBLE_MAT4x2 = GL_DOUBLE_MAT4x2;
	ShaderAttribType infi_gl_t::DOUBLE_MAT4x3 = GL_DOUBLE_MAT4x3;

	uint32 infi_gl_t::sizeOf(ShaderAttribType t) {
		switch(t) {
			case GL_FLOAT:
				return sizeof(float32);
				break;
			case GL_FLOAT_VEC2:
				return sizeof(float32) * 2;
				break;
			case GL_FLOAT_VEC3:
				return sizeof(float32) * 3;
				break;
			case GL_FLOAT_VEC4:
				return sizeof(float32) * 4;
				break;
			case GL_FLOAT_MAT2:
				return sizeof(float32) * 2 * 2;
				break;
			case GL_FLOAT_MAT3:
				return sizeof(float32) * 3 * 3;
				break;
			case GL_FLOAT_MAT4:
				return sizeof(float32) * 4 * 4;
				break;
			case GL_FLOAT_MAT2x3:
				return sizeof(float32) * 2 * 3;
				break;
			case GL_FLOAT_MAT2x4:
				return sizeof(float32) * 2 * 4;
				break;
			case GL_FLOAT_MAT3x2:
				return sizeof(float32) * 3 * 2;
				break;
			case GL_FLOAT_MAT3x4:
				return sizeof(float32) * 3 * 4;
				break;
			case GL_FLOAT_MAT4x2:
				return sizeof(float32) * 4 * 2;
				break;
			case GL_FLOAT_MAT4x3:
				return sizeof(float32);
				break;
			case GL_INT:
				return sizeof(int32);
				break;
			case GL_INT_VEC2:
				return sizeof(int32) * 2;
				break;
			case GL_INT_VEC3:
				return sizeof(int32) * 3;
				break;
			case GL_INT_VEC4:
				return sizeof(int32) * 4;
				break;
			case GL_UNSIGNED_INT:
				return sizeof(uint32);
				break;
			case GL_UNSIGNED_INT_VEC2:
				return sizeof(uint32) * 2;
				break;
			case GL_UNSIGNED_INT_VEC3:
				return sizeof(uint32) * 3;
				break;
			case GL_UNSIGNED_INT_VEC4:
				return sizeof(uint32) * 4;
				break;
			case GL_DOUBLE:
				return sizeof(float64);
				break;
			case GL_DOUBLE_VEC2:
				return sizeof(float64) * 2;
				break;
			case GL_DOUBLE_VEC3:
				return sizeof(float64) * 3;
				break;
			case GL_DOUBLE_VEC4:
				return sizeof(float64) * 4;
				break;
			case GL_DOUBLE_MAT2:
				return sizeof(float64) * 2 * 2;
				break;
			case GL_DOUBLE_MAT3:
				return sizeof(float64) * 3 * 3;
				break;
			case GL_DOUBLE_MAT4:
				return sizeof(float64) * 4 * 4;
				break;
			case GL_DOUBLE_MAT2x3:
				return sizeof(float64) * 2 * 3;
				break;
			case GL_DOUBLE_MAT2x4:
				return sizeof(float64) * 2 * 4;
				break;
			case GL_DOUBLE_MAT3x2:
				return sizeof(float64) * 3 * 2;
				break;
			case GL_DOUBLE_MAT3x4:
				return sizeof(float64) * 3 * 4;
				break;
			case GL_DOUBLE_MAT4x2:
				return sizeof(float64) * 4 * 2;
				break;
			case GL_DOUBLE_MAT4x3:
				return sizeof(float64) * 4 * 3;
				break;
			default:
				return 0;
				break;
		}
	}
	bool infi_gl_t::getComponents(ShaderAttribType input, AttribType& out1, uint32& out2) {
		switch(input) {
			case GL_FLOAT:
				out1 = GL_FLOAT;
				out2 = 1;
				break;
			case GL_FLOAT_VEC2:
				out1 = GL_FLOAT;
				out2 = 2;
				break;
			case GL_FLOAT_VEC3:
				out1 = GL_FLOAT;
				out2 = 3;
				break;
			case GL_FLOAT_VEC4:
				out1 = GL_FLOAT;
				out2 = 4;
				break;
			case GL_FLOAT_MAT2:
				out1 = GL_FLOAT;
				out2 = 4;
				break;
			case GL_FLOAT_MAT3:
				out1 = GL_FLOAT;
				out2 = 9;
				break;
			case GL_FLOAT_MAT4:
				out1 = GL_FLOAT;
				out2 = 16;
				break;
			case GL_FLOAT_MAT2x3:
				out1 = GL_FLOAT;
				out2 = 6;
				break;
			case GL_FLOAT_MAT2x4:
				out1 = GL_FLOAT;
				out2 = 8;
				break;
			case GL_FLOAT_MAT3x2:
				out1 = GL_FLOAT;
				out2 = 6;
				break;
			case GL_FLOAT_MAT3x4:
				out1 = GL_FLOAT;
				out2 = 12;
				break;
			case GL_FLOAT_MAT4x2:
				out1 = GL_FLOAT;
				out2 = 8;
				break;
			case GL_FLOAT_MAT4x3:
				out1 = GL_FLOAT;
				out2 = 12;
				break;
			case GL_INT:
				out1 = GL_INT;
				out2 = 1;
				break;
			case GL_INT_VEC2:
				out1 = GL_INT;
				out2 = 2;
				break;
			case GL_INT_VEC3:
				out1 = GL_INT;
				out2 = 3;
				break;
			case GL_INT_VEC4:
				out1 = GL_INT;
				out2 = 4;
				break;
			case GL_UNSIGNED_INT:
				out1 = GL_UNSIGNED_INT;
				out2 = 1;
				break;
			case GL_UNSIGNED_INT_VEC2:
				out1 = GL_UNSIGNED_INT;
				out2 = 2;
				break;
			case GL_UNSIGNED_INT_VEC3:
				out1 = GL_UNSIGNED_INT;
				out2 = 3;
				break;
			case GL_UNSIGNED_INT_VEC4:
				out1 = GL_UNSIGNED_INT;
				out2 = 4;
				break;
			case GL_DOUBLE:
				out1 = GL_DOUBLE;
				out2 = 1;
				break;
			case GL_DOUBLE_VEC2:
				out1 = GL_DOUBLE;
				out2 = 2;
				break;
			case GL_DOUBLE_VEC3:
				out1 = GL_DOUBLE;
				out2 = 3;
				break;
			case GL_DOUBLE_VEC4:
				out1 = GL_DOUBLE;
				out2 = 4;
				break;
			case GL_DOUBLE_MAT2:
				out1 = GL_DOUBLE;
				out2 = 4;
				break;
			case GL_DOUBLE_MAT3:
				out1 = GL_DOUBLE;
				out2 = 9;
				break;
			case GL_DOUBLE_MAT4:
				out1 = GL_DOUBLE;
				out2 = 16;
				break;
			case GL_DOUBLE_MAT2x3:
				out1 = GL_DOUBLE;
				out2 = 6;
				break;
			case GL_DOUBLE_MAT2x4:
				out1 = GL_DOUBLE;
				out2 = 8;
				break;
			case GL_DOUBLE_MAT3x2:
				out1 = GL_DOUBLE;
				out2 = 6;
				break;
			case GL_DOUBLE_MAT3x4:
				out1 = GL_DOUBLE;
				out2 = 12;
				break;
			case GL_DOUBLE_MAT4x2:
				out1 = GL_DOUBLE;
				out2 = 8;
				break;
			case GL_DOUBLE_MAT4x3:
				out1 = GL_DOUBLE;
				out2 = 12;
				break;
			default:
				return false;
				break;
		}
		return true;
	}

	DrawMode infi_gl_t::POINTS = GL_POINTS;
	DrawMode infi_gl_t::LINE_STRIP = GL_LINE_STRIP;
	DrawMode infi_gl_t::LINE_LOOP = GL_LINE_LOOP;
	DrawMode infi_gl_t::LINES = GL_LINES;
	DrawMode infi_gl_t::LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY;
	DrawMode infi_gl_t::LINES_ADJACENCY = GL_LINES_ADJACENCY;
	DrawMode infi_gl_t::TRIANGLE_STRIP = GL_TRIANGLE_STRIP;
	DrawMode infi_gl_t::TRIANGLE_FAN = GL_TRIANGLE_FAN;
	DrawMode infi_gl_t::TRIANGLES = GL_TRIANGLES;
	DrawMode infi_gl_t::TRIANGLE_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY;
	DrawMode infi_gl_t::TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY;
	DrawMode infi_gl_t::PATCHES = GL_PATCHES;

	BufferBindPoint infi_gl_t::ARRAY_BUFFER = GL_ARRAY_BUFFER;
	BufferBindPoint infi_gl_t::ATOMIC_COUNTER_BUFFER = GL_ATOMIC_COUNTER_BUFFER;
	BufferBindPoint infi_gl_t::COPY_READ_BUFFER = GL_COPY_READ_BUFFER;
	BufferBindPoint infi_gl_t::COPY_WRITE_BUFFER = GL_COPY_WRITE_BUFFER;
	BufferBindPoint infi_gl_t::DISPATCH_INDIRECT_BUFFER = GL_DISPATCH_INDIRECT_BUFFER;
	BufferBindPoint infi_gl_t::DRAW_INDIRECT_BUFFER = GL_DRAW_INDIRECT_BUFFER;
	BufferBindPoint infi_gl_t::ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER;
	BufferBindPoint infi_gl_t::PIXEL_PACK_BUFFER = GL_PIXEL_PACK_BUFFER;
	BufferBindPoint infi_gl_t::PIXEL_UNPACK_BUFFER = GL_PIXEL_UNPACK_BUFFER;
	BufferBindPoint infi_gl_t::QUERY_BUFFER = GL_QUERY_BUFFER;
	BufferBindPoint infi_gl_t::SHADER_STORAGE_BUFFER = GL_SHADER_STORAGE_BUFFER;
	BufferBindPoint infi_gl_t::TEXTURE_BUFFER = GL_TEXTURE_BUFFER;
	BufferBindPoint infi_gl_t::TRANSFORM_FEEDBACK_BUFFER = GL_TRANSFORM_FEEDBACK_BUFFER;
	BufferBindPoint infi_gl_t::UNIFORM_BUFFER = GL_UNIFORM_BUFFER;


	template<> bool infi_gl_t::getComponents<float32>(AttribType& type, uint32& count) {
		type = TYPE_FLOAT;
		count = 1;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::vec2>(AttribType& type, uint32& count) {
		type = TYPE_FLOAT;
		count = 2;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::vec3>(AttribType& type, uint32& count) {
		type = TYPE_FLOAT;
		count = 3;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::vec4>(AttribType& type, uint32& count) {
		type = TYPE_FLOAT;
		count = 4;
		return true;
	}

	template<> bool infi_gl_t::getComponents<int32>(AttribType& type, uint32& count) {
		type = TYPE_INT;
		count = 1;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::vec2i>(AttribType& type, uint32& count) {
		type = TYPE_INT;
		count = 2;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::vec3i>(AttribType& type, uint32& count) {
		type = TYPE_INT;
		count = 3;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::vec4i>(AttribType& type, uint32& count) {
		type = TYPE_INT;
		count = 4;
		return true;
	}

	template<> bool infi_gl_t::getComponents<uint32>(AttribType& type, uint32& count) {
		type = TYPE_UNSIGNED_INT;
		count = 1;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::vec2ui>(AttribType& type, uint32& count) {
		type = TYPE_UNSIGNED_INT;
		count = 2;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::vec3ui>(AttribType& type, uint32& count) {
		type = TYPE_UNSIGNED_INT;
		count = 3;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::vec4ui>(AttribType& type, uint32& count) {
		type = TYPE_UNSIGNED_INT;
		count = 4;
		return true;
	}

	template<> bool infi_gl_t::getComponents<core::mat2>(AttribType& type, uint32& count) {
		type = TYPE_FLOAT;
		count = 4;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::mat3>(AttribType& type, uint32& count) {
		type = TYPE_FLOAT;
		count = 9;
		return true;
	}
	template<> bool infi_gl_t::getComponents<core::mat4>(AttribType& type, uint32& count) {
		type = TYPE_FLOAT;
		count = 16;
		return true;
	}

} }