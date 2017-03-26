#include "core/methods.hpp"

namespace core {
	
/*mat Generalperspect( float wid, float hgt,  ) {
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

}
