#ifndef __INFI_QUATERNION_H__
#define __INFI_QUATERNION_H__

#include "core/infi_vector.h"

namespace INFI {
namespace core {

	struct INFI_EXPORT Quaternion {
		float32 i,j,k,w;
		
		Quaternion();
		Quaternion(float32,float32,float32,float32);
		
		Quaternion operator+ () const;
		Quaternion operator- () const;
		
		const vec4& asVector() const;
		Quaternion inverse() const;
	};

	INFI_FUNCTION( const Quaternion&, asQuaternion, (const vec4&) );

	INFI_FUNCTION( float32, Dot, (const Quaternion&,const Quaternion&) );
	INFI_FUNCTION( Quaternion, Blend, (const Quaternion&,const Quaternion&,float32=.5) );
	INFI_FUNCTION( Quaternion, Concatenate, (const Quaternion&,const Quaternion&) );
	INFI_FUNCTION( Quaternion, Integrate, (const Quaternion&,vec3,float32=1.) );
	INFI_FUNCTION( Quaternion, Integrate, (const Quaternion&,const Quaternion&,float32=1.) );
	INFI_FUNCTION( Quaternion, Product, (const Quaternion&,const Quaternion&) );

	INFI_FUNCTION( std::ostream&, operator<<, ( std::ostream&, const Quaternion& ) );

} }

#endif//__INFI_QUATERNION_H__
