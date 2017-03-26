#ifndef __VECTOR_BASE_H__
#define __VECTOR_BASE_H__

#include <cmath>
#include <iostream>

#include "base/types.hpp"
#include "base/error_log.hpp"

#include "core/core_defs.hpp"

namespace core {

#define TEMPLATE_NAME 	T1
#define TEMPLATE_NAME2 	T2

#define VECN(n) vec##n##_t<TEMPLATE_NAME>
#define VECN2(n) vec##n##_t<TEMPLATE_NAME2>

#define TEMP1 template<typename TEMPLATE_NAME>
#define TEMP2 template<typename TEMPLATE_NAME2>
#define TEMP3 template<typename TEMPLATE_NAME, typename TEMPLATE_NAME2>

#define DIV1(A,B,a,C) 			A a C B a
#define DIV2(A,B,a,b,C,D) 		DIV1(A,B,a,C) D DIV1(A,B,b,C)
#define DIV3(A,B,a,b,c,C,D) 	DIV2(A,B,a,b,C,D) D DIV1(A,B,c,C)
#define DIV4(A,B,a,b,c,d,C,D) 	DIV3(A,B,a,b,c,C,D) D DIV1(A,B,d,C)

#define OPERATION2(prefix,x,y)		VECN(2) prefix () const;
#define OPERATION3(prefix,x,y,z) 	VECN(3) prefix () const;
#define OPERATION4(prefix,x,y,z,w)	VECN(4) prefix () const;

#define OPERATION22(prefix,x,y)		TEMP1 VECN(2) VECN(2)::prefix () \
									const { return VECN(2)(x,y); }
#define OPERATION23(prefix,x,y,z) 	TEMP1 VECN(3) VECN(2)::prefix () \
									const { return VECN(3)(x,y,z); }
#define OPERATION24(prefix,x,y,z,w)	TEMP1 VECN(4) VECN(2)::prefix () \
									const { return VECN(4)(x,y,z,w); }

#define OPERATION32(prefix,x,y)		TEMP1 VECN(2) VECN(3)::prefix () \
									const { return VECN(2)(x,y); }
#define OPERATION33(prefix,x,y,z) 	TEMP1 VECN(3) VECN(3)::prefix () \
									const { return VECN(3)(x,y,z); }
#define OPERATION34(prefix,x,y,z,w)	TEMP1 VECN(4) VECN(3)::prefix () \
									const { return VECN(4)(x,y,z,w); }

#define OPERATION42(prefix,x,y)		TEMP1 VECN(2) VECN(4)::prefix () \
									const { return VECN(2)(x,y); }
#define OPERATION43(prefix,x,y,z) 	TEMP1 VECN(3) VECN(4)::prefix () \
									const { return VECN(3)(x,y,z); }
#define OPERATION44(prefix,x,y,z,w)	TEMP1 VECN(4) VECN(4)::prefix () \
									const { return VECN(4)(x,y,z,w); }

#define PERMUTE221(x,a,b,FUNC) \
		FUNC(x##a,x,a) \
		FUNC(x##b,x,b)

#define PERMUTE231(prefix,x,y,a,b,FUNC) \
		FUNC(prefix##a,x,y,a) \
		FUNC(prefix##b,x,y,b)

#define PERMUTE232(x,a,b,FUNC) \
		PERMUTE231(x##a,x,a,a,b,FUNC) \
		PERMUTE231(x##b,x,b,a,b,FUNC)

#define PERMUTE241(prefix,x,y,z,a,b,FUNC) \
		FUNC(prefix##a,x,y,z,a) \
		FUNC(prefix##b,x,y,z,b)

#define PERMUTE242(prefix,x,y,a,b,FUNC) \
		PERMUTE241(prefix##a,x,y,a,a,b,FUNC) \
		PERMUTE241(prefix##b,x,y,b,a,b,FUNC) \

#define PERMUTE243(x,a,b,FUNC) \
		PERMUTE242(x##a,x,a,a,b,FUNC) \
		PERMUTE242(x##b,x,b,a,b,FUNC)

#define PERMUTE321(x,a,b,c,FUNC) \
		FUNC(x##a,x,a) \
		FUNC(x##b,x,b) \
		FUNC(x##c,x,c)

#define PERMUTE331(prefix,x,y,a,b,c,FUNC) \
		FUNC(prefix##a,x,y,a) \
		FUNC(prefix##b,x,y,b) \
		FUNC(prefix##c,x,y,c)

#define PERMUTE332(x,a,b,c,FUNC) \
		PERMUTE331(x##a,x,a,a,b,c,FUNC) \
		PERMUTE331(x##b,x,b,a,b,c,FUNC) \
		PERMUTE331(x##c,x,c,a,b,c,FUNC)

#define PERMUTE341(prefix,x,y,z,a,b,c,FUNC) \
		FUNC(prefix##a,x,y,z,a) \
		FUNC(prefix##b,x,y,z,b) \
		FUNC(prefix##c,x,y,z,c)

#define PERMUTE342(prefix,x,y,a,b,c,FUNC) \
		PERMUTE341(prefix##a,x,y,a,a,b,c,FUNC) \
		PERMUTE341(prefix##b,x,y,b,a,b,c,FUNC) \
		PERMUTE341(prefix##c,x,y,c,a,b,c,FUNC)

#define PERMUTE343(x,a,b,c,FUNC) \
		PERMUTE342(x##a,x,a,a,b,c,FUNC) \
		PERMUTE342(x##b,x,b,a,b,c,FUNC) \
		PERMUTE342(x##c,x,c,a,b,c,FUNC)

#define PERMUTE421(x,a,b,c,d,FUNC) \
		FUNC(x##a,x,a) \
		FUNC(x##b,x,b) \
		FUNC(x##c,x,c) \
		FUNC(x##d,x,d)

#define PERMUTE431(prefix,x,y,a,b,c,d,FUNC) \
		FUNC(prefix##a,x,y,a) \
		FUNC(prefix##b,x,y,b) \
		FUNC(prefix##c,x,y,c) \
		FUNC(prefix##d,x,y,d) \

#define PERMUTE432(x,a,b,c,d,FUNC) \
		PERMUTE431(x##a,x,a,a,b,c,d,FUNC) \
		PERMUTE431(x##b,x,b,a,b,c,d,FUNC) \
		PERMUTE431(x##c,x,c,a,b,c,d,FUNC) \
		PERMUTE431(x##d,x,d,a,b,c,d,FUNC) \

#define PERMUTE441(prefix,x,y,z,a,b,c,d,FUNC) \
		FUNC(prefix##a,x,y,z,a) \
		FUNC(prefix##b,x,y,z,b) \
		FUNC(prefix##c,x,y,z,c) \
		FUNC(prefix##d,x,y,z,d)

#define PERMUTE442(prefix,x,y,a,b,c,d,FUNC) \
		PERMUTE441(prefix##a,x,y,a,a,b,c,d,FUNC) \
		PERMUTE441(prefix##b,x,y,b,a,b,c,d,FUNC) \
		PERMUTE441(prefix##c,x,y,c,a,b,c,d,FUNC) \
		PERMUTE441(prefix##d,x,y,d,a,b,c,d,FUNC)

#define PERMUTE443(x,a,b,c,d,FUNC) \
		PERMUTE442(x##a,x,a,a,b,c,d,FUNC) \
		PERMUTE442(x##b,x,b,a,b,c,d,FUNC) \
		PERMUTE442(x##c,x,c,a,b,c,d,FUNC) \
		PERMUTE442(x##d,x,d,a,b,c,d,FUNC)

#define PERMUTE22(a,b,FUNC) \
		PERMUTE221(a,a,b,FUNC) \
		PERMUTE221(b,a,b,FUNC)

#define PERMUTE23(a,b,FUNC) \
		PERMUTE232(a,a,b,FUNC) \
		PERMUTE232(b,a,b,FUNC)

#define PERMUTE24(a,b,FUNC) \
		PERMUTE243(a,a,b,FUNC) \
		PERMUTE243(b,a,b,FUNC)

#define PERMUTE32(a,b,c,FUNC) \
		PERMUTE321(a,a,b,c,FUNC) \
		PERMUTE321(b,a,b,c,FUNC) \
		PERMUTE321(c,a,b,c,FUNC)

#define PERMUTE33(a,b,c,FUNC) \
		PERMUTE332(a,a,b,c,FUNC) \
		PERMUTE332(b,a,b,c,FUNC) \
		PERMUTE332(c,a,b,c,FUNC)

#define PERMUTE34(a,b,c,FUNC) \
		PERMUTE343(a,a,b,c,FUNC) \
		PERMUTE343(b,a,b,c,FUNC) \
		PERMUTE343(c,a,b,c,FUNC)

#define PERMUTE42(a,b,c,d,FUNC) \
		PERMUTE421(a,a,b,c,d,FUNC) \
		PERMUTE421(b,a,b,c,d,FUNC) \
		PERMUTE421(c,a,b,c,d,FUNC) \
		PERMUTE421(d,a,b,c,d,FUNC)

#define PERMUTE43(a,b,c,d,FUNC) \
		PERMUTE432(a,a,b,c,d,FUNC) \
		PERMUTE432(b,a,b,c,d,FUNC) \
		PERMUTE432(c,a,b,c,d,FUNC) \
		PERMUTE432(d,a,b,c,d,FUNC)

#define PERMUTE44(a,b,c,d,FUNC) \
		PERMUTE443(a,a,b,c,d,FUNC) \
		PERMUTE443(b,a,b,c,d,FUNC) \
		PERMUTE443(c,a,b,c,d,FUNC) \
		PERMUTE443(d,a,b,c,d,FUNC)

#define PERMUTE2(a,b,A,B,C) \
		PERMUTE22(a,b,A) \
		PERMUTE23(a,b,B) \
		PERMUTE24(a,b,C)

#define PERMUTE3(a,b,c,A,B,C) \
		PERMUTE32(a,b,c,A) \
		PERMUTE33(a,b,c,B) \
		PERMUTE34(a,b,c,C)

#define PERMUTE4(a,b,c,d,A,B,C) \
		PERMUTE42(a,b,c,d,A) \
		PERMUTE43(a,b,c,d,B) \
		PERMUTE44(a,b,c,d,C)

#define OPERATOR2RE(op) \
		TEMP2 \
		VECN(2) operator op (const VECN2(2)& n) const { \
			return VECN(2)( x op n.x, y op n.y ); }

#define OPERATOR2IP(op) \
		OPERATOR2RE(op) \
		TEMP2 \
		VECN(2)& operator op##= (const VECN2(2)& n) { \
			x op##= n.x; \
			y op##= n.y; \
			return *this; }

#define OPERATOR3RE(op) \
		TEMP2 \
		VECN(3) operator op (const VECN2(3)& n) const { \
			return VECN(3)( x op n.x, y op n.y, z op n.z ); }

#define OPERATOR3IP(op) \
		OPERATOR3RE(op) \
		TEMP2 \
		VECN(3)& operator op##= (const VECN2(3)& n) { \
			x op##= n.x; \
			y op##= n.y; \
			z op##= n.z; \
			return *this; }

#define OPERATOR4RE(op) \
		TEMP2 \
		VECN(4) operator op (const VECN2(4)& n) const { \
			return VECN(4)( x op n.x, y op n.y, z op n.z, w op n.w ); }

#define OPERATOR4IP(op) \
		OPERATOR4RE(op) \
		TEMP2 \
		VECN(4)& operator op##= (const VECN2(4)& n) { \
			x op##= n.x; \
			y op##= n.y; \
			z op##= n.z; \
			w op##= n.w; \
			return *this; }

#define OPERATOR2UN(op) \
		VECN(2) operator op () const { \
			return VECN(2)( op x, op y ); \
		}
#define OPERATOR3UN(op) \
		VECN(3) operator op () const { \
			return VECN(3)( op x, op y, op z ); \
		}
#define OPERATOR4UN(op) \
		VECN(4) operator op () const { \
			return VECN(4)( op x, op y, op z, op w ); \
		}

#define COMPONENT1OP( name1, name2, op ) name1.x op name2
#define COMPONENT2OP( name1, name2, op ) COMPONENT1OP(name1,name2,op), name1.y op name2
#define COMPONENT3OP( name1, name2, op ) COMPONENT2OP(name1,name2,op), name1.z op name2
#define COMPONENT4OP( name1, name2, op ) COMPONENT3OP(name1,name2,op), name1.w op name2

#define COMPONENT1IP( name1, name2, op ) name1.x op name2
#define COMPONENT2IP( name1, name2, op ) COMPONENT1OP(name1,name2,op); name1.y op name2
#define COMPONENT3IP( name1, name2, op ) COMPONENT2OP(name1,name2,op); name1.z op name2
#define COMPONENT4IP( name1, name2, op ) COMPONENT3OP(name1,name2,op); name1.w op name2

#define FULLOPERATOR( n ) \
		OPERATOR ## n ## IP(+) \
		OPERATOR ## n ## IP(-) \
		OPERATOR ## n ## IP(*) \
		OPERATOR ## n ## IP(/) \
		OPERATOR ## n ## UN(-)

#define CTOR2_DEFAULT_ARGS(a,b,c,d) a(TEMPLATE_NAME()), b(TEMPLATE_NAME())
#define CTOR3_DEFAULT_ARGS(a,b,c,d) CTOR2_DEFAULT_ARGS(a,b,c,d), c(TEMPLATE_NAME())
#define CTOR4_DEFAULT_ARGS(a,b,c,d) CTOR3_DEFAULT_ARGS(a,b,c,d), d(TEMPLATE_NAME())

#define CTOR2_BASE_ARGS	const TEMPLATE_NAME& arg1,\
						const TEMPLATE_NAME& arg2
#define CTOR3_BASE_ARGS CTOR2_BASE_ARGS,\
						const TEMPLATE_NAME& arg3
#define CTOR4_BASE_ARGS CTOR3_BASE_ARGS,\
						const TEMPLATE_NAME& arg4

#define CTOR2_BASE_ASSIGN(a,b,c,d) a(arg1), b(arg2)
#define CTOR3_BASE_ASSIGN(a,b,c,d) CTOR2_BASE_ASSIGN(a,b,c,d), c(arg3)
#define CTOR4_BASE_ASSIGN(a,b,c,d) CTOR3_BASE_ASSIGN(a,b,c,d), d(arg4)

#define CTOR2_COPY_ASSIGN(a,b,c,d) a(copy.a), b(copy.b)
#define CTOR3_COPY_ASSIGN(a,b,c,d) CTOR2_COPY_ASSIGN(a,b,c,d), c(copy.c)
#define CTOR4_COPY_ASSIGN(a,b,c,d) CTOR3_COPY_ASSIGN(a,b,c,d), d(copy.d)

#define CTOR2_COPY_EQUALS(a,b,c,d) a = copy.a; b = copy.b;
#define CTOR3_COPY_EQUALS(a,b,c,d) CTOR2_COPY_EQUALS(a,b,c,d) c = copy.c;
#define CTOR4_COPY_EQUALS(a,b,c,d) CTOR3_COPY_EQUALS(a,b,c,d) d = copy.d;

#define CTOR2_LIST_ASSIGN(args,a,b,c,d) a = *(args.begin()+0); \
										b = *(args.begin()+1);
#define CTOR3_LIST_ASSIGN(args,a,b,c,d) CTOR2_LIST_ASSIGN(args,a,b,c,d) \
										c = *(args.begin()+2);
#define CTOR4_LIST_ASSIGN(args,a,b,c,d) CTOR3_LIST_ASSIGN(args,a,b,c,d) \
										d = *(args.begin()+3);

#define FULLCTOR( n, a,b,c,d ) \
	vec##n##_t() : CTOR##n##_DEFAULT_ARGS(a,b,c,d) { ; } \
	vec##n##_t( CTOR##n##_BASE_ARGS ) : CTOR##n##_BASE_ASSIGN(a,b,c,d) { ; } \
	vec##n##_t(const VECN(n)& copy ) \
	: CTOR##n##_COPY_ASSIGN(a,b,c,d) { ; } \
	vec##n##_t(std::initializer_list<TEMPLATE_NAME> args) { \
		if ( args.end() - args.begin() != n ) { \
			Error::send<Error::Fatality::Method>( \
				Error::Type::Init, \
				"invalid number of elements (got %d, need %d)", \
				args.end() - args.begin(), n \
			); \
		} CTOR##n##_LIST_ASSIGN( args, a,b,c,d ) \
	} \
	template<typename TEMPLATE_NAME2> vec##n##_t( const VECN2(n)& copy ) \
	: CTOR##n##_COPY_ASSIGN(a,b,c,d) { } \
	template<typename TEMPLATE_NAME2> vec##n##_t<TEMPLATE_NAME>& \
		operator=( const VECN2(n)& copy ) \
		{ CTOR##n##_COPY_EQUALS(a,b,c,d) return *this; }

#define VECTOR_MATH(n) \
		TEMP1 TEMPLATE_NAME Distance( const VECN(n)& a, const VECN(n)& b )\
			{ return Length(b-a); }\
		TEMP1 float32 Angle(const VECN(n)& a,const VECN(n)& b)\
			{ return acos( ( Dot(a,b) ) / ( Length(a) * Length(b) ) ); }\
		TEMP1 VECN(n) Normalize( const VECN(n)& a )\
			{ return a / Length(a); }\
		TEMP3 VECN(n) operator* ( TEMPLATE_NAME2 a, const VECN(n)& b )\
			{ return VECN(n)( COMPONENT ## n ## OP( b, a, * ) ); }\
		TEMP3 VECN(n) operator* ( const VECN(n)& a, TEMPLATE_NAME2 b )\
			{ return VECN(n)( COMPONENT ## n ## OP( a, b, * ) ); }\
		TEMP3 VECN(n) operator/ ( TEMPLATE_NAME2 a, const VECN(n)& b )\
			{ return VECN(n)( COMPONENT ## n ## OP( b, a, / ) ); }\
		TEMP3 VECN(n) operator/ ( const VECN(n)& a, TEMPLATE_NAME2 b )\
			{ return VECN(n)( COMPONENT ## n ## OP( a, b, / ) ); }\
		TEMP3 VECN(n)& operator*= ( VECN(n)& a, TEMPLATE_NAME2 b )\
			{ COMPONENT ## n ## IP( a, b, *= ); return a; }\
		TEMP3 VECN(n)& operator/= ( VECN(n)& a, TEMPLATE_NAME2 b )\
			{ COMPONENT ## n ## IP( a, b, /= ); return a; }

#define VECTOR_ABBR(n) \
		typedef vec##n##_t<float32> vec##n;\
		typedef vec##n##_t<float32> vec##n##f;\
		typedef vec##n##_t<float64> vec##n##d;\
		typedef vec##n##_t<int32> 	vec##n##i;\
		typedef vec##n##_t<uint32> 	vec##n##ui;\
		typedef vec##n##_t<int8> 	vec##n##c;\
		typedef vec##n##_t<uint8> 	vec##n##uc;\
		typedef vec##n##_t<bool> 	vec##n##b;

TEMP1 struct  vec4_t;
TEMP1 struct  vec3_t;
TEMP1 struct  vec4_t;

TEMP1 struct  vec2_t {

	TEMPLATE_NAME x, y;

	FULLCTOR(2, x,y,z,w)
	FULLOPERATOR(2)

	bool operator== (const VECN(2)& n) const { return ( DIV2(this->,n.,x,y,==,&&) ); }
	bool operator!= (const VECN(2)& n) const { return ( DIV2(this->,n.,x,y,!=,||) ); }

	PERMUTE2(x,y,OPERATION2,OPERATION3,OPERATION4)

};

TEMP1 struct vec3_t {

	TEMPLATE_NAME x, y, z;

	FULLCTOR(3, x,y,z,w)
	FULLOPERATOR(3)

	bool operator== (const VECN(3)& n) const { return ( DIV3(this->,n.,x,y,z,==,&&) ); }
	bool operator!= (const VECN(3)& n) const { return ( DIV3(this->,n.,x,y,z,!=,||) ); }

	PERMUTE3(x,y,z,OPERATION2,OPERATION3,OPERATION4)

};

TEMP1 struct  vec4_t {

	TEMPLATE_NAME x, y, z, w;

	FULLCTOR(4, x,y,z,w);
	FULLOPERATOR(4);

	bool operator== (const VECN(4)& n) const { return ( DIV3(this->,n.,x,y,z,==,&&) ); }
	bool operator!= (const VECN(4)& n) const { return ( DIV3(this->,n.,x,y,z,!=,||) ); }

	PERMUTE4(x,y,z,w,OPERATION2,OPERATION3,OPERATION4);

};

PERMUTE2(x,y,OPERATION22,OPERATION23,OPERATION24);
PERMUTE3(x,y,z,OPERATION32,OPERATION33,OPERATION34);
PERMUTE4(x,y,z,w,OPERATION42,OPERATION43,OPERATION44);

TEMP1 TEMPLATE_NAME Dot( const VECN(2)& a,const VECN(2)& b )
	{ return DIV2(a.,b., x,y, *,+); }
TEMP1 TEMPLATE_NAME Length( const VECN(2)& a )
	{ return std::sqrt( DIV2(a.,a., x,y, *,+) ); }
VECTOR_MATH(2);

TEMP1 TEMPLATE_NAME Dot( const VECN(3)& a,const VECN(3)& b )
	{ return DIV3(a.,b., x,y,z, *,+); }
TEMP1 TEMPLATE_NAME Length( const VECN(3)& a )
	{ return std::sqrt( DIV3(a.,a., x,y,z, *,+) ); }
VECTOR_MATH(3);

TEMP1 TEMPLATE_NAME Dot( const VECN(4)& a,const VECN(4)& b )
	{ return DIV4(a.,b., x,y,z,w, *,+); }
TEMP1 TEMPLATE_NAME Length( const VECN(4)& a )
	{ return std::sqrt( DIV4(a.,a., x,y,z,w, *,+) ); }
VECTOR_MATH(4);

TEMP1 VECN(3) Cross( const VECN(3)& a, const VECN(3)& b ) {
	return VECN(3)( a.y*b.z - a.z*b.y,
					a.z*b.x - a.x*b.z,
					a.x*b.y - a.y*b.x );
}

VECTOR_ABBR(2);
VECTOR_ABBR(3);
VECTOR_ABBR(4);

template<typename T>
std::ostream& operator<< (std::ostream& ostr, const vec2_t<T>& vec ) {
	ostr << "(" << vec.x << ", " << vec.y << ")";
	return ostr;
}
template<typename T>
std::ostream& operator<< (std::ostream& ostr, const vec3_t<T>& vec ) {
	ostr << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return ostr;
}
template<typename T>
std::ostream& operator<< (std::ostream& ostr, const vec4_t<T>& vec ) {
	ostr << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
	return ostr;
}

}

#endif//__VECTOR_BASE_H__
