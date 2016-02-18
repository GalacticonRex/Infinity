#include "main/infi_types.h"

namespace INFI {

#define CASE_RESULT( c, r ) \
		case c: return r; break;
		
uint32 infi_sizeof( infi_t type ) {
	switch( type ) {
		CASE_RESULT( INFI_BOOL, 1 )
		CASE_RESULT( INFI_BYTE, sizeof(int8) )
		CASE_RESULT( INFI_UBYTE, sizeof(uint8) )
		CASE_RESULT( INFI_SHORT, sizeof(int16) )
		CASE_RESULT( INFI_USHORT, sizeof(uint16) )
		CASE_RESULT( INFI_FLOAT, sizeof(float32) )
		CASE_RESULT( INFI_DOUBLE, sizeof(float64) )
		CASE_RESULT( INFI_INT, sizeof(int32) )
		CASE_RESULT( INFI_UINT, sizeof(uint32) )
		CASE_RESULT( INFI_POINTER, sizeof(void*) )
		CASE_RESULT( INFI_MATRIX, 1 )
		CASE_RESULT( INFI_SAMPLER2D, 1 )
		default:
			return 0;
	}
}
const char* infi_typename( infi_t type ) {
	switch( type ) {
		CASE_RESULT( INFI_BOOL, "bool" );
		CASE_RESULT( INFI_BYTE, "int" );
		CASE_RESULT( INFI_UBYTE, "uchar" );
		CASE_RESULT( INFI_SHORT, "short" );
		CASE_RESULT( INFI_USHORT, "ushort" );
		CASE_RESULT( INFI_FLOAT, "float" );
		CASE_RESULT( INFI_DOUBLE, "double" );
		CASE_RESULT( INFI_INT, "int" );
		CASE_RESULT( INFI_UINT, "uint" );
		CASE_RESULT( INFI_POINTER, "pointer" );
		CASE_RESULT( INFI_MATRIX, "matrix" );
		CASE_RESULT( INFI_SAMPLER2D, "sampler2D" );
		default:
			return "none";
	}
}

}
