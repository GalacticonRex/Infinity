#ifndef __INFI_PROGRAM_H__
#define __INFI_PROGRAM_H__

#include "render/infi_program_format.h"
#include "core/infi_bitfield.h"
#include "core/infi_queue.h"

namespace INFI {
namespace render {
	
	typedef void (*INFI_BindUniform)( uint32, uint8* );
	
	struct infi_uniform_field_t;
	struct infi_uniform_shader_t;
	struct infi_uniform_control_t;
	
	// a single uniquely named uniform 
	struct infi_uniform_field_t {
		struct {
			uint32 active		: 1; // is the uniform alive in the array 
			uint32 uptodate	: 1; // is the uniform up-to-date in the shader
			uint32 neverflag	: 1; // never flag this uniform as up-to-date
			uint32 references : 3; // how many shaders are using this uniform
			uint32 size		: 26; // size of data (in bytes)
		} flags;
		infi_t				typereq;	// required type (e.g. float32)
		uint32				countreq;	// required count (e.g. 5 floats)
		uint32 				location;	// the binding location for the GL
		uint8* 				data;		// the raw data
		INFI_BindUniform 	info;		// the function used to bind the raw data
		
		infi_uniform_field_t();
		infi_uniform_field_t(const infi_uniform_field_t&);
		~infi_uniform_field_t();
		
		// set requirements for the uniform
		void require( uint32, infi_t );
		
		// setup the actual data of the shader
		void setup( uint32, uint8*, INFI_BindUniform, bool = false );
		
		// check if the uniform is in use, if so set the location value
		bool update( uint32, const core::string_t& );
		
		// bind the data to the shader
		void use();
		
		// multiple shaders can share the same uniforms,
		// keep track of how many shaders are referencing
		// this uniform
		uint32 increment();
		uint32 decrement();
	};
	
	// all of the uniforms associated with a single shader
	struct infi_uniform_shader_t {
		infi_uniform_control_t* parent;
		core::array_t<core::string_t> mappings;
		
		infi_uniform_shader_t( infi_uniform_control_t* );
		~infi_uniform_shader_t();
	};
	
	// controls all the uniforms of all shaders in a program
	struct infi_uniform_control_t {
		infi_program_t* 					parent;
		infi_uniform_shader_t**				shaders;
		core::array_t<infi_uniform_field_t> data;
		core::queue_t<uint32>				empty;
		core::map_t<core::string_t,uint32> 	mappings;
		core::map_t<core::string_t,uint32> 	samplers;
		
		infi_uniform_control_t();
		infi_uniform_control_t(const infi_uniform_control_t&);
		
		uint32 add_uniform( uint32, infi_t );
		void kill_uniform( uint32 );
		
		// tokens are paired off [type,name,etc...]
		void push( uint32, const core::array_t<core::string_t>& );
		
		// remove the uniforms associated with the specified shader
		void pop( uint32 );
		
		// bind all not up-to-date uniforms
		void use( uint32 );
	};
	
	// a single shader program
	struct infi_program_t {
		infi_program_format_t	format;			// what kind of data does the program need
		infi_uniform_control_t	uniforms;		// uniform control
		int32* 					components;		// shader handles
		uint32 					handle;			// program handle
		uint32 					version;		// version number of the program
		
		struct {
			// are these shaders active
			uint32 vertex   : 1;
			uint32 geometry : 1;
			uint32 tessctrl : 1;
			uint32 tesseval : 1;
			uint32 fragment : 1;
			uint32 compute  : 1;
			
			// is the program compiled
			uint32 uptodate : 1;
			
			// no fragment shader
			uint32 raster_discard : 1;
		} flags;
		
		uint32 active_shaders() const;
		void refresh_uniforms();
		
		void compile();
		
		// set uniforms
		void uniformi( const core::string_t&, int32 );
		void uniformi( const core::string_t&, InfiGetter<int32> );
		
		void uniformf( const core::string_t&, float32 );
		void uniformf( const core::string_t&, InfiGetter<float32> );
		
		void uniform2f( const core::string_t&, const core::vec2& );
		void uniform2f( const core::string_t&, InfiGetter<core::vec2> );
		
		void uniform3f( const core::string_t&, const core::vec3& );
		void uniform3f( const core::string_t&, InfiGetter<core::vec3> );
		
		void uniform4f( const core::string_t&, const core::vec4& );
		void uniform4f( const core::string_t&, InfiGetter<core::vec4> );
		
		void uniformMat2( const core::string_t&, const core::mat2& );
		void uniformMat2( const core::string_t&, InfiGetter<core::mat2> );
		
		void uniformMat3( const core::string_t&, const core::mat3& );
		void uniformMat3( const core::string_t&, InfiGetter<core::mat3> );
		
		void uniformMat4( const core::string_t&, const core::mat4& );
		void uniformMat4( const core::string_t&, InfiGetter<core::mat4> );
		
		void uniformSampler( const core::string_t&, infi_texture_t* );
		void uniformSampler( const core::string_t&, InfiGetter<infi_texture_t*> );
	};
	
	// create a new, empty shader program
	INFI_FUNCTION( infi_program_t*, InfiCreateProgram, () );
	INFI_FUNCTION( void, InfiDestroyProgram, ( infi_program_t* ) );
	
	// define individual shaders
	// auto formats the program
	INFI_FUNCTION( void, InfiVertexShader, ( infi_program_t*, const core::string_t& ) );
	INFI_FUNCTION( void, InfiFragmentShader, ( infi_program_t*, const core::string_t& ) );
	
	INFI_FUNCTION( void, InfiVertexShaderFromFile, ( infi_program_t*, const core::string_t& ) );
	INFI_FUNCTION( void, InfiFragmentShaderFromFile, ( infi_program_t*, const core::string_t& ) );
	
	// push and pop the program from the state stack
	INFI_FUNCTION( infi_program_t*, InfiCurrentProgram, () );
	INFI_FUNCTION( void, InfiPushProgram, ( infi_program_t* ) );
	INFI_FUNCTION( void, InfiPopProgram, () );
	
} }

#endif//__INFI_PROGRAM_H__