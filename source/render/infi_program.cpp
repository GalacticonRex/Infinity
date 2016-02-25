#include "render/infi_program.h"
#include "render/infi_gl_wrapper.h"
#include <fstream>

namespace INFI {
namespace render {
	
	// vertex slots in <components>
	static const uint32 VERTEX = 0,
						FRAGMENT = 4;

	static void get_binding_type( const core::string_t&, uint32&, infi_t& );

	// ------------------------------------------------
	//    UNIFORM FIELD STUFF
	// ------------------------------------------------
	infi_uniform_field_t::infi_uniform_field_t() :
		typereq( INFI_NONE ),
		countreq( 0 ),
		location( (uint32) -1 ),
		data( NULL ),
		info( NULL ) {
		flags.active = 1;
		flags.uptodate = 0;
		flags.size = 0;
		flags.references = 0;
	}
	infi_uniform_field_t::infi_uniform_field_t(const infi_uniform_field_t& copy) :
		typereq( copy.typereq ),
		countreq( copy.countreq ),
		location( (uint32) -1 ),
		data( new uint8[copy.flags.size] ),
		info( copy.info ) {
		flags.active = copy.flags.active;
		flags.uptodate = copy.flags.uptodate;
		flags.size = copy.flags.size;
		flags.references = copy.flags.references;
	}
	infi_uniform_field_t::~infi_uniform_field_t() {
		delete[] data;
	}
	void infi_uniform_field_t::require( uint32 creq, infi_t treq ) {
		typereq = treq;
		countreq = creq;
	}
	void infi_uniform_field_t::setup( uint32 span, uint8* input, INFI_BindUniform func, bool update ) {
		delete[] data;
		data = new uint8[span];
		memcpy( data, input, span );
		info = func;
		flags.uptodate = false;
		flags.neverflag = update;
		flags.size = span;
		flags.active = true;
	}
	bool infi_uniform_field_t::update( uint32 prog, const core::string_t& data ) {
		if ( info == NULL )
			return false;
		const char* name = data.localize().source();
		if ( location == (uint32)-1 ) {
			location = InfiGLGetUniformLocation( prog, name );
			if ( location == (uint32)-1 ) {
				InfiSendError( INFI_BINDING_ERROR,
							   "shader uniform %s is not used",
							   data.localize().source() );
			}
		}
		return true;
	}
	void infi_uniform_field_t::use() {
		if ( flags.uptodate )
			return;
		this->info( location, this->data );
		if ( !flags.neverflag )
			flags.uptodate = true;
	}
	uint32 infi_uniform_field_t::increment() {
		return ++ flags.references;
	}
	uint32 infi_uniform_field_t::decrement() {
		return -- flags.references;
	}

	infi_uniform_shader_t::infi_uniform_shader_t( infi_uniform_control_t* ctrl ) :
		parent( ctrl ) { }
	infi_uniform_shader_t::~infi_uniform_shader_t() {
		InfiPushFunction( "~infi_uniform_shader_t" );
		if ( parent != NULL )
			for ( uint32 i=0;i<mappings.size();++i ) {
				uint32 index = parent->mappings[mappings[i]];
				if ( parent->data[index].decrement() == 0 ) {
					std::cerr << "KILL " << mappings[i] << std::endl;
					parent->kill_uniform( index );
				}
			}
		InfiPopFunction();
	}

	// ------------------------------------------------
	//    UNIFORM CONTROL STUFF
	// ------------------------------------------------
	infi_uniform_control_t::infi_uniform_control_t() :
		parent( NULL ),
		shaders( new infi_uniform_shader_t*[6] ) {
		for ( uint32 i=0;i<6;++i )
			shaders[i] = NULL;
	}
	infi_uniform_control_t::infi_uniform_control_t( const infi_uniform_control_t& copy ) :
		parent( copy.parent ),
		shaders( new infi_uniform_shader_t*[6] ) {
		for ( uint32 i=0;i<6;++i )
			shaders[i] = copy.shaders[i];
	}

	uint32 infi_uniform_control_t::add_uniform( uint32 count, infi_t type ) {
		InfiPushFunction( "infi_uniform_control_t.add_uniform" );
		infi_uniform_field_t* fld;
		if ( empty.empty() ) {
			fld = &data.add();
		} else {
			fld = &data[empty[0]];
			empty.pop();
		}
		fld->flags.active = true;
		fld->increment();
		fld->require( count, type ); 
		InfiPopFunction();
		return data.size()-1;
	}
	void infi_uniform_control_t::kill_uniform( uint32 index ) {
		InfiPushFunction( "infi_uniform_control_t.kill_uniform" );
		infi_uniform_field_t& fld = data[index];
		if ( fld.flags.active ) {
			empty.push( index );
			
			fld.typereq = INFI_NONE;
			fld.countreq = 0;
			fld.location = (uint32) -1;
			fld.data = NULL;
			fld.info = NULL;
			fld.flags.uptodate = 0;
			fld.flags.size = 0;
			fld.flags.active = false;
			
		}
		InfiPopFunction();
	}

	void infi_uniform_control_t::push( uint32 shader, const core::array_t<core::string_t>& tokens ) {
		InfiPushFunction( "infi_uniform_control_t.push" );
		if ( shaders[shader] != NULL )
			InfiSendError( INFI_BINDING_ERROR,
						   "shader %d already in use", shader );

		shaders[shader] = new infi_uniform_shader_t( this );
		
		uint32 sampler_index = 0;
		for ( uint32 i=0;i<tokens.size();i+=2 ) {
			const core::string_t& type = tokens[i+0];
			const core::string_t& name = tokens[i+1];

			core::map_t<core::string_t,uint32>::iterator
				finding = mappings.find( name );
				
			if ( finding == mappings.end() ) {
				infi_t infitype = INFI_NONE;
				uint32 inficount = 0;
				if ( type == "sampler2D" ) {
					samplers[name] = sampler_index ++ ;
					inficount = 1;
					infitype = INFI_SAMPLER2D;
				} else {
					get_binding_type( type, inficount, infitype );
				}
				mappings[name] = add_uniform( inficount, infitype );
			}
			
			shaders[shader]->mappings.add( name );
		}
		InfiPopFunction();
	}
	void infi_uniform_control_t::pop( uint32 shader ) {
		std::cerr << "POPPING SHADER " << shader << std::endl;
		InfiPushFunction( "infi_uniform_control_t.pop" );
		if ( shaders[shader] == NULL )
			InfiSendError( INFI_BINDING_ERROR,
						   "shader %d not in use", shader );
		delete shaders[shader];
		shaders[shader] = NULL;
		if ( shader == FRAGMENT ) {
			std::cerr << "CLEAR SAMPLERS" << std::endl;
			samplers.clear();
		}
		std::cerr << "DONE" << std::endl;
		InfiPopFunction();
	}
	void infi_uniform_control_t::use( uint32 prog ) {
		core::map_t<core::string_t,uint32>::iterator
			iter = mappings.begin();
		for ( ;iter!=mappings.end();++iter ) {
			uint32 index = iter->second;
			if ( data[index].update( prog, iter->first ) )
				data[index].use();
		}
	}

	uint32 infi_program_t::active_shaders() const {
		return flags.vertex +
			   flags.geometry +
			   flags.tessctrl +
			   flags.tesseval +
			   flags.fragment +
			   flags.compute;
	}
	void infi_program_t::refresh_uniforms() {
		for ( uint32 i=0;i<uniforms.data.size();++i )
			uniforms.data[i].flags.uptodate = false;
	}

	void infi_program_t::compile() {
		if ( flags.uptodate )
			return;

		InfiPushFunction( "infi_program_t.compile" );
		if ( handle == 0 || components[VERTEX] == 0 )
			InfiSendError( INFI_BINDING_ERROR, "no vertex shader at compile time") ;
			
		InfiGLLinkProgram(handle);
		
		GLint isLinked = 0;
		InfiGLGetProgramiv(handle, GL_LINK_STATUS, &isLinked);
		if ( isLinked == GL_FALSE ) {
			GLint maxlen = 0;
			InfiGLGetProgramiv(handle, GL_INFO_LOG_LENGTH, &maxlen);

			char* infolog = new char[maxlen+1];
			InfiGLGetProgramInfoLog(handle, maxlen, &maxlen, infolog);

			InfiGLDeleteProgram(handle);
			for ( int32 i=0;i<6;i++ )
				if ( components[i] != 0 ) {
					InfiGLDeleteShader( components[i] );
					components[i] = 0;
				}
			handle = 0;

			InfiSendError( INFI_GL_ERROR, "%s", infolog );
			delete[] infolog;
		}
		
		flags.uptodate = 1;
		this->refresh_uniforms();
		
		InfiPopFunction();
	}

	// create a new, empty shader program
	infi_program_t* InfiCreateProgram() {
		infi_program_t* ret = new infi_program_t;
		ret->components = new int32[6];
		for ( uint32 i=0;i<6;++i )
			ret->components[i] = 0;
		ret->uniforms.parent = ret;
		ret->handle = 0;
		ret->version = 0;
		ret->flags.vertex = 0;
		ret->flags.geometry = 0;
		ret->flags.tessctrl = 0;
		ret->flags.tesseval = 0;
		ret->flags.fragment = 0;
		ret->flags.compute = 0;
		ret->flags.uptodate = 0;
		ret->flags.raster_discard = 1;
		ret->flags.has_feedback = 0;
		return ret;
	}

	static void parse_shader( infi_program_t* prog, uint32 shad, const core::string_t& data ) {
		core::array_t<core::string_t> tokens;
		data.split( {' ',',',';','\t','\n'}, tokens );

		core::array_t<core::string_t> uniforms;

		infi_format_t* input = new infi_format_t;
		infi_format_t* output = new infi_format_t;

		for ( uint32 i=0;i<tokens.size();++i ) {
			if ( tokens[i] == "in" ) {
				input->add( tokens[i+2], tokens[i+1] );
			} else if ( tokens[i] == "out"  ) {
				output->add( tokens[i+2], tokens[i+1] );
			} else if ( tokens[i] == "uniform"  ) {
				uniforms.add( tokens[i+1] );
				uniforms.add( tokens[i+2] );
			}
		}

		switch( shad ) {
			case VERTEX:
				prog->format.overwrite_input( input );
				break;
			case FRAGMENT:
				prog->format.overwrite_output( output );
				break;
		}

		if ( prog->uniforms.shaders[shad] != NULL )
			prog->uniforms.pop( shad );
		prog->uniforms.push( shad, uniforms );
	}
	static void check_shader( uint32 shad ) {
		GLint done = 0;
		InfiGLGetShaderiv( shad, GL_COMPILE_STATUS, &done);

		if ( done == GL_FALSE ) {
			GLint maxlen = 0;
			InfiGLGetShaderiv(shad, GL_INFO_LOG_LENGTH, &maxlen);

			char* infolog = new char[maxlen+1];
			InfiGLGetShaderInfoLog(shad, maxlen, &maxlen, infolog);
			InfiGLDeleteShader(shad);

			InfiSendError( INFI_GL_ERROR, "%s", infolog );

			delete[] infolog;
		}
	}
	static void make_shader( infi_program_t* prog, uint32 index, GLenum stype, const char* data ) {
		if ( prog->handle == 0 )
			prog->handle = InfiGLCreateProgram();

		if ( prog->components[index] != 0 ) {
			prog->uniforms.pop( index );
			InfiGLDetachShader( prog->handle, prog->components[index] );
			InfiGLDeleteShader( prog->components[index] );
		}
		prog->components[index] = InfiGLCreateShader( stype );
		InfiGLShaderSource( prog->components[index],
							1,
							&data,
							0 );
		InfiGLCompileShader( prog->components[index] );
		check_shader(prog->components[index]);
		InfiGLAttachShader( prog->handle, prog->components[index] );
		prog->flags.uptodate = 0;
	}

	void InfiVertexShader( infi_program_t* prog, const core::string_t& data ) {
		InfiPushFunction( "InfiVertexShader" );
		make_shader( prog,
					 VERTEX,
					 GL_VERTEX_SHADER,
					 data.localize().source() );
		parse_shader( prog, VERTEX, data );
		InfiPopFunction();
	}
	void InfiFragmentShader( infi_program_t* prog, const core::string_t& data ) {
		InfiPushFunction( "InfiFragmentShader" );
		make_shader( prog,
					 FRAGMENT,
					 GL_FRAGMENT_SHADER,
					 data.localize().source() );
		parse_shader( prog, FRAGMENT, data );
		prog->flags.raster_discard = 0;
		InfiPopFunction();
	}
	
	typedef void (*ShaderLoader)(infi_program_t*,const core::string_t&);
	void load_file( infi_program_t* prog, ShaderLoader func, const core::string_t& fname ) {  
		const char* cname = fname.localize().source();
		InfiPushFunction( cname );
		std::ifstream t( cname );
		std::string str;

		t.seekg(0, std::ios::end);   
		str.reserve(t.tellg());
		t.seekg(0, std::ios::beg);
		
		str.assign((std::istreambuf_iterator<char>(t)),
					std::istreambuf_iterator<char>());
		
		core::string_t data( str.c_str() );
		func( prog, data );
		InfiPopFunction();
	}
	
	void InfiVertexShaderFromFile( infi_program_t* prog, const core::string_t& fname ) {
		load_file( prog, InfiVertexShader, fname );
	}
	void InfiFragmentShaderFromFile( infi_program_t* prog, const core::string_t& fname ) {
		load_file( prog, InfiFragmentShader, fname );
	}
	
	static core::stack_t<infi_program_t*> programs;
	
	infi_program_t* InfiCurrentProgram() {
		return ( programs.empty() ) ? NULL : *programs;
	}
	void InfiPushProgram( infi_program_t* prog ) {
		InfiPushFunction( "InfiPushProgram" );
		programs.push( prog );
		InfiPopFunction();
	}
	void InfiPopProgram() {
		InfiPushFunction( "InfiPopProgram" );
		programs.pop();
		InfiPopFunction();
	}
	static void get_binding_type( const core::string_t& type, uint32& count, infi_t& infitype ) {
		if ( type == "int" ) {
			infitype = INFI_INT;
			count = 1;
		} else if ( type == "float" ) {
			infitype = INFI_FLOAT;
			count = 1;
		} else if ( type == "vec2" ) {
			infitype = INFI_FLOAT;
			count = 2;
		} else if ( type == "vec3" ) {
			infitype = INFI_FLOAT;
			count = 3;
		} else if ( type == "vec4" ) {
			infitype = INFI_FLOAT;
			count = 4;
		} else if ( type == "mat2" ) {
			infitype = INFI_MATRIX;
			count = 2;
		} else if ( type == "mat3" ) {
			infitype = INFI_MATRIX;
			count = 3;
		} else if ( type == "mat4" ) {
			infitype = INFI_MATRIX;
			count = 4;
		}
	}

} }