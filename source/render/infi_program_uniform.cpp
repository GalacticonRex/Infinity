#include "render/infi_program.h"
#include "render/infi_gl_wrapper.h"
#include "render/infi_texture.h"

namespace INFI {
namespace render {
	
	static bool infi_transform_change = true;
	void InfiLSignalTransformChange() {
		infi_transform_change = true;
	}
	
	static bool check_binding_name( infi_t, INFI_BindUniform );
	
	static void infi_int( uint32 uni, uint8* data ) {
		InfiGLUniformi( uni, *((int32*)data) );
	}
	static void infi_intget( uint32 uni, uint8* data ) {
		InfiGetter<int32> ptr = *((InfiGetter<int32>*)data);
		InfiGLUniformi( uni, ptr() );
	}
	static void infi_float( uint32 uni, uint8* data ) {
		InfiGLUniformf( uni, *((float32*)data) );
	}
	static void infi_floatget( uint32 uni, uint8* data ) {
		InfiGetter<float32> ptr = *((InfiGetter<float32>*)data);
		InfiGLUniformf( uni, ptr() );
	}
	static void infi_vec2( uint32 uni, uint8* data ) {
		core::vec2& v = *((core::vec2*)data);
		InfiGLUniformf( uni, v.x, v.y );
	}
	static void infi_vec2get( uint32 uni, uint8* data ) {
		InfiGetter<core::vec2> ptr = *((InfiGetter<core::vec2>*)data);
		core::vec2 v = ptr();
		InfiGLUniformf( uni, v.x, v.y );
	}
	static void infi_vec3( uint32 uni, uint8* data ) {
		core::vec3& v = *((core::vec3*)data);
		InfiGLUniformf( uni, v.x, v.y, v.z );
	}
	static void infi_vec3get( uint32 uni, uint8* data ) {
		InfiGetter<core::vec3> ptr = *((InfiGetter<core::vec3>*)data);
		core::vec3 v = ptr();
		InfiGLUniformf( uni, v.x, v.y, v.z );
	}
	static void infi_vec4( uint32 uni, uint8* data ) {
		core::vec4& v = *((core::vec4*)data);
		InfiGLUniformf( uni, v.x, v.y, v.z, v.w );
	}
	static void infi_vec4get( uint32 uni, uint8* data ) {
		InfiGetter<core::vec4> ptr = *((InfiGetter<core::vec4>*)data);
		core::vec4 v = ptr();
		InfiGLUniformf( uni, v.x, v.y, v.z, v.w );
	}
	static void infi_mat2( uint32 uni, uint8* data ) {
		InfiGLUniform( uni, *((core::mat2*)data) );
	}
	static void infi_mat2get( uint32 uni, uint8* data ) {
		InfiGetter<core::mat2> ptr = *((InfiGetter<core::mat2>*)data);
		InfiGLUniform( uni, ptr() );
	}
	static void infi_mat3( uint32 uni, uint8* data ) {
		InfiGLUniform( uni, *((core::mat3*)data) );
	}
	static void infi_mat3get( uint32 uni, uint8* data ) {
		InfiGetter<core::mat3> ptr = *((InfiGetter<core::mat3>*)data);
		InfiGLUniform( uni, ptr() );
	}
	static void infi_mat4( uint32 uni, uint8* data ) {
		InfiGLUniform( uni, *((core::mat4*)data) );
	}
	static void infi_mat4get( uint32 uni, uint8* data ) {
		InfiGetter<core::mat4> ptr = *((InfiGetter<core::mat4>*)data);
		InfiGLUniform( uni, ptr() );
	}
	
	struct texture_active_pair {
		infi_texture_t* tex;
		uint32 act;
	};
	struct texturefunc_active_pair {
		InfiGetter<infi_texture_t*> tex;
		uint32 act;
	};
	
	static void bind_texture( uint32 uni, infi_texture_t* tex, uint32 act) {
		InfiGLPushTexture( tex->handle, act );
		InfiGLUniformi( uni, act );
	}
	static void infi_texture( uint32 uni, uint8* data ) {
		texture_active_pair tex = *((texture_active_pair*)data);
		bind_texture( uni, tex.tex, tex.act );
	}
	static void infi_textureget( uint32 uni, uint8* data ) {
		texturefunc_active_pair tex = *((texturefunc_active_pair*)data);
		bind_texture( uni, tex.tex(), tex.act );
	}

	static infi_uniform_field_t& infi_check_valid_uniform( infi_program_t* prog,
														   const core::string_t& uni,
														   INFI_BindUniform check,
														   uint32 span ) {
		core::map_t<core::string_t,uint32>::iterator
			finding = prog->uniforms.mappings.find( uni );
			
		if ( finding == prog->uniforms.mappings.end() )
			InfiSendError( INFI_BINDING_ERROR,
						   "could not find uniform <%s> in program",
						   uni.localize().source() );

		uint32 index = finding->second;
		infi_uniform_field_t& fld = prog->uniforms.data[index];
		if ( !fld.flags.active )
			InfiSendError( INFI_BINDING_ERROR,
						   "something went wrong with uniform <%s> at location %d",
						   uni.localize().source(), index );
		
		if ( !check_binding_name( fld.typereq, check ) )
			InfiSendError( INFI_BINDING_ERROR,
						   "uniform <%s> must of type %s",
						   uni.localize().source(),
						   infi_typename( fld.typereq ) );
		
		uint32 sz = span / infi_sizeof( fld.typereq );
		if ( fld.countreq != sz )
			InfiSendError( INFI_BINDING_ERROR,
						   "uniform <%s> must have %d elements (got %d)",
						   uni.localize().source(), fld.countreq, sz );
		
		return fld; 
	}
	
	#define UNIFORM( ext, type, check, size, name, never ) \
			void infi_program_t::uniform ## ext( const core::string_t& uni, type value ) { \
				InfiPushFunction( #name ); \
				infi_uniform_field_t& fld = \
					infi_check_valid_uniform( this, uni, check, size ); \
				fld.setup( sizeof(type), (uint8*)&value, check, never ); \
				InfiPopFunction(); \
			}
	
	UNIFORM( i, int32, infi_int, sizeof(int32), UniformInt, false )
	UNIFORM( i, InfiGetter<int32>, infi_intget, sizeof(int32), UniformIntFunc, true )
	
	UNIFORM( f, float32, infi_float, sizeof(float32), UniformFloat, false )
	UNIFORM( f, InfiGetter<float32>, infi_floatget, sizeof(float32), UniformFloatFunc, true )
	
	UNIFORM( 2f, const core::vec2&, infi_vec2, sizeof(core::vec2), UniformVec2, false )
	UNIFORM( 2f, InfiGetter<core::vec2>, infi_vec2get, sizeof(core::vec2), UniformVec2Func, true )
	
	UNIFORM( 3f, const core::vec3&, infi_vec3, sizeof(core::vec3), UniformVec3, false )
	UNIFORM( 3f, InfiGetter<core::vec3>, infi_vec3get, sizeof(core::vec3), UniformVec3Func, true )
	
	UNIFORM( 4f, const core::vec4&, infi_vec4, sizeof(core::vec4), UniformVec4, false )
	UNIFORM( 4f, InfiGetter<core::vec4>, infi_vec4get, sizeof(core::vec4), UniformVec4Func, true )
	
	UNIFORM( Mat2, const core::mat2&, infi_mat2, 2, UniformMatrix2, false )
	UNIFORM( Mat2, InfiGetter<core::mat2>, infi_mat2get, 2, UniformMatrix2Func, true )
	
	UNIFORM( Mat3, const core::mat3&, infi_mat3, 3, UniformMatrix3, false )
	UNIFORM( Mat3, InfiGetter<core::mat3>, infi_mat3get, 3, UniformMatrix3Func, true )
	
	UNIFORM( Mat4, const core::mat4&, infi_mat4, 4, UniformMatrix4, false )
	UNIFORM( Mat4, InfiGetter<core::mat4>, infi_mat4get, 4, UniformMatrix4Func, true )
	
	void infi_program_t::uniformSampler( const core::string_t& uni, infi_texture_t* value ) { \
		InfiPushFunction( "UniformSampler2D" );
		infi_uniform_field_t& fld =
			infi_check_valid_uniform( this, uni, infi_texture, 1 );
			
		uint32 active = uniforms.samplers[uni];
		texture_active_pair t = { value, active };
		fld.setup( sizeof(texture_active_pair), (uint8*)&t, infi_texture, true );
		
		InfiPopFunction();
	}
	void infi_program_t::uniformSampler( const core::string_t& uni, InfiGetter<infi_texture_t*> value ) { \
		InfiPushFunction( "UniformSampler2D" );
		infi_uniform_field_t& fld =
			infi_check_valid_uniform( this, uni, infi_texture, 1 );
			
		uint32 active = uniforms.samplers[uni];
		texturefunc_active_pair t = { value, active };
		fld.setup( sizeof(texture_active_pair), (uint8*)&t, infi_textureget, true );
		
		InfiPopFunction();
	}
	
	static bool check_binding_name( infi_t type, INFI_BindUniform func ) {
		if ( type == INFI_INT ) {
			if (func != infi_int && func != infi_intget)
				return false;
		} else if ( type == INFI_FLOAT ) {
			if (func != infi_float && func != infi_floatget &&
				func != infi_vec2 && func != infi_vec2get &&
				func != infi_vec3 && func != infi_vec3get &&
				func != infi_vec4 && func != infi_vec4get)
				return false;
		} else if ( type == INFI_MATRIX ) {
			if (func != infi_mat2 && func != infi_mat2get &&
				func != infi_mat3 && func != infi_mat3get &&
				func != infi_mat4 && func != infi_mat4get)
				return false;
		} else if ( type == INFI_SAMPLER2D ) {
			if (func != infi_texture && func != infi_textureget)
				return false;
		}
		return true;
	}
	
} }