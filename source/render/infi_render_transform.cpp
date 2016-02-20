#include "core/infi_transform_stack.h"
#include "core/infi_methods.h"
#include "render/infi_render_transform.h"
#include "render/infi_render.h"

namespace INFI {
namespace render {
	
	namespace {
		using namespace core;
	}
	
	static transform4 transform_stack;

	const mat4& InfiGetTransform() { 
		return transform_stack.get();
	}
	
	void InfiResetTransform() {
		transform_stack.reset();
		InfiLSignalTransformChange();
	}
	void InfiPushTransform() {
		transform_stack.push();
	}
	void InfiPushNewTransform() {
		transform_stack.push_new();
	}
	void InfiPushTransform( const mat4& mat ) {
		transform_stack.push();
		transform_stack.mult( mat );
		InfiLSignalTransformChange();
	}

	void InfiAddTransform( const mat4& mat ) { 
		transform_stack.mult( mat );
		InfiLSignalTransformChange();
	}

	void InfiTranslate( const vec2& v ) {
		mat4 m = ExpandMat4( TranslationMatrix( v ) );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiTranslate( const vec3& v ) {
		mat4 m = TranslationMatrix( v );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiTranslate( float32 x, float32 y ) {
		InfiTranslate( vec2( x, y ) );
	}
	void InfiTranslate( float32 x, float32 y, float32 z ) {
		InfiTranslate( vec3( x, y, z ) );
	}
	void InfiRotate( float32 angle ) {
		mat4 m = ExpandMat4( toMatrix( angle ) );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiRotate( const eulerangles_t& eul ) {
		mat4 m = ExpandMat4( toMatrix( eul ) );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiRotate( const axisangle_t& aa ) {
		mat4 m = ExpandMat4( toMatrix( aa ) );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiRotate( const quaternion_t& quat ) {
		mat4 m = ExpandMat4( toMatrix( quat ) );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiScale( float32 x ) {
		mat4 m = ExpandMat4( ScalingMatrix( vec2(x,x) ) );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiScale( const vec2& v ) {
		mat4 m = ExpandMat4( ScalingMatrix( v ) );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiScale( const vec3& v ) {
		mat4 m = ScalingMatrix( v );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiScale( float32 x, float32 y ) {
		mat4 m = ExpandMat4( ScalingMatrix( vec2(x,y) ) );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	void InfiScale( float32 x, float32 y, float32 z ) {
		mat4 m = ScalingMatrix( vec3(x,y,z) );
		transform_stack.mult( m );
		InfiLSignalTransformChange();
	}
	
	void InfiPopTransform() { 
		InfiPushFunction( "InfiPopTransform" );
		transform_stack.pop();
		InfiLSignalTransformChange();
		InfiPopFunction();
	}

} }