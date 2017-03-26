#include "core/matrix.hpp"
namespace core {
	mat3 translate3 ( vec2 n )
	{
		mat3 tor = mat3::identity();
		tor(0,2) = n.x;
		tor(1,2) = n.y;
		return tor;
	}
	mat4 translate4 ( vec3 n )
	{
		mat4 tor = mat4::identity();
		tor(0,3) = n.x;
		tor(1,3) = n.y;
		tor(2,3) = n.z;
		return tor;
	}
	mat3 scale3 ( vec2 n )
	{
		mat3 tor = mat3::identity();
		tor(0,0) = n.x;
		tor(1,1) = n.y;
		return tor;
	}
	mat4 scale4 ( vec3 n )
	{
		mat4 tor = mat4::identity();
		tor(0,0) = n.x;
		tor(1,1) = n.y;
		tor(2,2) = n.z;
		return tor;
	}
	mat3 ortho3( vec2 start, vec2 finish )
	{
		mat3 ret = mat3::identity();

		float32 l = start.x,
			  r = finish.x,
			  t = finish.y,
			  b = start.y;

		ret(0,0) = 2. / ( r - l );
		ret(1,1) = 2. / ( t - b );

		ret(0,2) = -( r + l ) / ( r - l );
		ret(1,2) = -( t + b ) / ( t - b );

		return ret;
	}
	mat3 ortho3( vec2 finish )
	{
		return ortho3(vec2(), finish);
	}
	mat4 ortho4( vec2 start, vec2 finish )
	{
		mat4 ret = mat4::identity();

		float32 l = start.x,
			  r = finish.x,
			  t = finish.y,
			  b = start.y;

		ret(0,0) = 2.f / ( r - l );
		ret(1,1) = 2.f / ( t - b );
		ret(2,2) = 0;

		ret(0,3) = -( r + l ) / ( r - l );
		ret(1,3) = -( t + b ) / ( t - b );
		ret(2,3) = 0;

		return ret;
	}
	mat4 ortho4( vec2 finish )
	{
		return ortho4(vec2(), finish);
	}
	mat4 perspect( float32 fov, float32 ar, float32 close, float32 far )
	{
		mat4 proj = mat4::identity();

		float32 f = tan( fov / 2. );

		proj(0,0) = 1. / ( f * ar );
		proj(1,1) = 1. / ( f );
		proj(2,2) = -( far + close ) / ( far - close );
		proj(2,3) = ( -2 * far * close ) / ( far - close );
		proj(3,2) = -1.;

		return proj;
	}
}