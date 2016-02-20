#include "core/infi_methods.h"

namespace INFI {
namespace core {
	
mat3 TranslationMatrix ( vec2 n )
{
	mat3 tor = mat3::identity();
	tor(0,2) = n.x;
	tor(1,2) = n.y;
	return tor;
}
mat4 TranslationMatrix ( vec3 n )
{
	mat4 tor = mat4::identity();
	tor(0,3) = n.x;
	tor(1,3) = n.y;
	tor(2,3) = n.z;
	return tor;
}
mat3 ScalingMatrix ( vec2 n )
{
	mat3 tor = mat3::identity();
	tor(0,0) = n.x;
	tor(1,1) = n.y;
	return tor;
}
mat4 ScalingMatrix ( vec3 n )
{
	mat4 tor = mat4::identity();
	tor(0,0) = n.x;
	tor(1,1) = n.y;
	tor(2,2) = n.z;
	return tor;
}
mat3 OrthoMat3( vec2 start, vec2 finish )
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
mat4 OrthoMat4( vec2 start, vec2 finish )
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
mat4 Perspective( float32 fov, float32 ar, float32 close, float32 far )
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
/*mat GeneralPerspective( float wid, float hgt,  ) {
{
    float va[3], vb[3], vc[3];
    float vr[3], vu[3], vn[3];

    float l, r, b, t, d, M[16];

    // Compute an orthonormal basis for the screen.

    subtract(vr, pb, pa);
    subtract(vu, pc, pa);

    normalize(vr);
    normalize(vu);
    cross_product(vn, vr, vu);
    normalize(vn);

    // Compute the screen corner vectors.

    subtract(va, pa, pe);
    subtract(vb, pb, pe);
    subtract(vc, pc, pe);

    // Find the distance from the eye to screen plane.

    d = -dot_product(va, vn);

    // Find the extent of the perpendicular projection.

    l = dot_product(vr, va) * n / d;
    r = dot_product(vr, vb) * n / d;
    b = dot_product(vu, va) * n / d;
    t = dot_product(vu, vc) * n / d;

    // Load the perpendicular projection.

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(l, r, b, t, n, f);

    // Rotate the projection to be non-perpendicular.

    memset(M, 0, 16 * sizeof (float));

    M[0] = vr[0]; M[4] = vr[1]; M[ 8] = vr[2];
    M[1] = vu[0]; M[5] = vu[1]; M[ 9] = vu[2];
    M[2] = vn[0]; M[6] = vn[1]; M[10] = vn[2];

    M[15] = 1.0f;

    glMultMatrixf(M);

    // Move the apex of the frustum to the origin.

    glTranslatef(-pe[0], -pe[1], -pe[2]);

    glMatrixMode(GL_MODELVIEW);
}*/

float32 rad2deg( float32 x ) { return x * 57.295779513082320876798154; }
float32 deg2rad( float32 x ) { return x * 0.0174532925199432957692369; }

float32 Clamp( float32 val, float32 low, float32 high ) {
	if ( val < low )
		return low;
	else if ( val > high )
		return high;
	else
		return val;
}

int32 MakePow2(int32 n) {
	for (int32 i=1;i!=0;i<<=1)
		if ( n % i == n )
			return i;
	return 0;
}
uint32 MakePow2(uint32 n) {
	for (uint32 i=1;i!=0;i<<=1)
		if ( n % i == n )
			return i;
	return 0;
}

} }