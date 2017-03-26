#ifndef __TYPES_H__
#define __TYPES_H__

#include "lib_export.hpp"

#define MATH_PI 3.1415926535897932384626
#define MATH_TAU 6.2831853071795864769252
#define MATH_E  2.7182818284590452353603

typedef unsigned char 			uint8;
typedef unsigned short 			uint16;
typedef unsigned int 			uint32;
typedef long long unsigned int 	uint64;
typedef char 					int8;
typedef short 					int16;
typedef int 					int32;
typedef long long int 			int64;
typedef float					float32;
typedef double					float64;

class Function {
public:
	template<typename T> using get = T (*)();
	template<typename T> using set = void (*)( T );
};

#endif//__TYPES_H__
