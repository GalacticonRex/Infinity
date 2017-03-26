#ifndef __MATRIX_N_X_N_234_H__
#define __MATRIX_N_X_N_234_H__

#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstring>

#include "core/vector.hpp"

namespace core {

template<uint32 row,uint32 col>
struct matrix
{
	float32 data[row*col];

	static float32 det( const matrix<row,col>& mat) {
		if ( row!=col )
			return 0;

		if ( row == 1 && col == 1 ) {
			return mat.data[0];
		} else {
			float32 fin = 0;
			for ( uint32 i=0;i<row;i++ )
				fin += pow( -1, int32(i) ) * mat(0,i) * det<row-1,col-1>( mat.submatrix(0,i) );
			return fin;
		}
	}
	static matrix<col,row> transpose( const matrix<row,col>& mat ) {
		matrix<col,row> matret;
		for ( uint32 i=0;i<row;i++ )
			for ( uint32 j=0;j<col;j++ )
				matret.data[i+j*row] = mat.data[j+i*col];
		return matret;
	}

	static constexpr matrix<row,col> identity() {
		if ( row != col ) {
			//Error::define_scope __scope__("matrix.identity");
			Error::send<Error::Fatality::Method>(
				Error::Type::Type,
				"Cannot set non-square matrix (%d x %d) to identity",
				row, col
			);
			return matrix<row,col>();
		}
		matrix<row,col> matret;
		for (uint32 i=0;i<row*row;i++)
			( i%row==i/row ) ? matret.data[i] = 1 :
							   matret.data[i] = 0;
		return matret;
	}

	matrix( void ) { }
	matrix( std::initializer_list< std::initializer_list<float32> > x ) {
		uint32 i = 0, j = 0;
		for ( const auto& l : x ) {
			for ( const auto& v : l ) {
				data[j*row+i] = v;
				++ j;
			}
			++ i;
		}
	}

	bool operator==( const matrix<row,col>& mat ) const {
		for (uint32 i=0;i<row*col;i++)
			if ( data[i] != mat[i] )
				return false;
		return true;
	}
	bool operator!=( const matrix<row,col>& mat ) const {
		for (uint32 i=0;i<row*col;i++)
			if ( data[i] == mat[i] )
				return false;
		return true;
	}

	float32& operator() (uint32 r,uint32 c) { return data[r+c*row]; }
	const float32& operator() (uint32 r,uint32 c) const { return data[r+c*row]; }

	matrix<row,col> operator+ (const matrix<row,col>& mat) const {
		matrix<row,col> matret;
		for ( int32 i=0;i<row*col;i++ )
			matret.data = data[i]+mat.data[i];
		return matret;
	}

	matrix<row,col> operator- (const matrix<row,col>& mat) const {
		matrix<row,col> matret;
		for ( int32 i=0;i<row*col;i++ )
			matret.data = data[i]-mat.data[i];
		return matret;
	}

	void operator+= (const matrix<row,col>& mat) {
		for ( uint32 i=0;i<row*col;i++ )
			data[i] += mat.data[i];
	}

	void operator-= (const matrix<row,col>& mat) {
		for ( uint32 i=0;i<row*col;i++ )
			data[i] -= mat.data[i];
	}

	matrix<row,col> operator* ( float32 x ) const {
		matrix<row,col> mat;
		for ( uint32 i=0;i<row*col;i++ )
			mat.data[i] = data[i] * x;
		return mat;
	}
	matrix<row,col> operator/ ( float32 x ) const {
		matrix<row,col> mat;
		for ( uint32 i=0;i<row*col;i++ )
			mat.data[i] = data[i] / x;
		return mat;
	}
	void operator*= ( float32 x ) {
		for ( uint32 i=0;i<row*col;i++ )
			data[i] *= x;
	}
	void operator/= ( float32 x ) {
		for ( uint32 i=0;i<row*col;i++ )
			data[i] /= x;
	}

	template<uint32 ncol>
	matrix<row,ncol> mult( const matrix<row,col>& mat ) const {
		matrix<row,ncol> matret;
		for ( uint32 i=0;i<row;i++ )
			for ( uint32 j=0;j<ncol;j++ )
			{
				float32 fin = 0;
				for ( uint32 k=0;k<col;k++ )
					fin += data[i+k*row] * mat(k,j);
				matret(i,j) = fin;
			}
		return matret;
	}

	matrix<row-1,col-1> submatrix( uint32 r,uint32 c ) const {
		matrix<row-1,col-1> mat;
		uint32 i2 = 0;
		for ( uint32 i=0;i<row-1;i++,i2++ ) {
			if ( r == i ) i2 ++ ;
			uint32 j2 = 0;
			for ( uint32 j=0;j<col-1;j++,j2++ ) {
				if ( c == j ) j2 ++ ;
				mat.data[i+j*(row-1)] = data[i2+j2*row];
			}
		} return mat;
	}

	matrix<row,col> minors() const {
		matrix<row,col> matret;
		for ( uint32 i=0;i<row;i++ )
			for ( uint32 j=0;j<col;j++ )
				matret(i,j) = det<row-1,col-1>( submatrix(i,j) );
		return matret;
	}

	matrix<row,col> cofactors() const {
		matrix<row,col> matret;
		for ( uint32 i=0;i<row;i++ )
			for ( uint32 j=0;j<col;j++ )
				matret(i,j) = std::pow(-1,int32(i+j)) * det<row-1,col-1>( submatrix(i,j) );
		return matret;
	}

	matrix<col,row> inverse() const {
		matrix<col,row> adjugate = matrix<col,row>::transpose( cofactors() );

		float32 mydet = 0;
		for ( uint32 i=0;i<col;i++ )
			mydet += data[i*row] * pow(-1,int32(i)) * adjugate(i,0);
		return adjugate / mydet;
	}

	template<uint32 sr,uint32 sc,uint32 er,uint32 ec>
	matrix<er-sr,ec-sc> submatrix() const {
		matrix<er-sr,ec-sc> mat;
		for ( uint32 i=sr,i2=0;i<er;i++,i2++ )
			for ( uint32 j=sc,j2=0;j<ec;j++,j2++ )
				mat.data[j2+i2*(ec-sc)] = data[j+i*col];
		return mat;
	}
	template<uint32 nrow,uint32 ncol>
	void splice(uint32 c,uint32 r,const matrix<row,col>& mat) const {
		for ( uint32 i=r;i<r+nrow;i++ )
			for ( uint32 j=c;j<c+ncol;j++ )
				data[i+j*row] = mat( i-r, j-c );
	}
};

typedef matrix<2,2> mat2;
typedef matrix<3,3> mat3;
typedef matrix<4,4> mat4;

template<uint32 row,uint32 col>
inline void PrintMat( const matrix<row,col>& mat ) {
	char buffer[row*col][64];
	uint32 lens[col];
	for ( uint32 j=0;j<col;j++ ) {
		lens[j] = 0;
		for ( uint32 i=0;i<row;i++ ) {
			sprintf( buffer[i+j*row], "%f", mat(i,j) );
			lens[j] = std::max( lens[j], (uint32)strlen( buffer[i+j*row] ) );
		}
	}
	for ( uint32 i=0;i<row;i++ ) {
		std::cout << "| ";
		for ( uint32 j=0;j<col;j++ )
			std::cout << std::setw( lens[j] ) << buffer[i+j*row] << " ";
		std::cout << "|" << std::endl;
	}
}

inline mat2 create2( float32 n00,float32 n01,float32 n10,float32 n11 ) {
	mat2 n;
	n.data[0] = n00; n.data[2] = n01;
	n.data[1] = n10; n.data[3] = n11;
	return n;
}

inline vec2 operator*( const mat2& m, vec2 v ) {
	return vec2( v.x * m.data[0] + v.y * m.data[2],
				 v.x * m.data[1] + v.y * m.data[3] );
}

inline mat2 operator*( const mat2& n, const mat2& m ) {
	return n.mult<2>( m );
}

inline mat3 expand3(const mat2& m) {
	mat3 n;
	n.data[0] = m.data[0]; n.data[3] = m.data[2]; n.data[6] = 0;
	n.data[1] = m.data[1]; n.data[4] = m.data[3]; n.data[7] = 0;
	n.data[2] =		 0; n.data[5] =		 0; n.data[8] = 1;
	return n;
}
inline mat4 expand4(const mat2& m) {
	mat4 n;
	n.data[0] = m.data[0]; n.data[4] = m.data[2]; n.data[ 8] = 0; n.data[12] = 0;
	n.data[1] = m.data[1]; n.data[5] = m.data[3]; n.data[ 9] = 0; n.data[13] = 0;
	n.data[2] =		    0; n.data[6] =		   0; n.data[10] = 1; n.data[14] = 0;
	n.data[3] =		    0; n.data[7] =		   0; n.data[11] = 0; n.data[15] = 1;
	return n;
}

inline void PrintMatrix( const mat2& mat ) { PrintMat<2,2>( mat ); }
inline mat3 create3(  float32 n00,float32 n01,float32 n02,
						   float32 n10,float32 n11,float32 n12,
						   float32 n20,float32 n21,float32 n22 )
{
	mat3 n;
	n.data[0] = n00; n.data[3] = n01; n.data[6] = n02;
	n.data[1] = n10; n.data[4] = n11; n.data[7] = n12;
	n.data[2] = n20; n.data[5] = n21; n.data[8] = n22;
	return n;
}

inline vec3 operator* ( const mat3& m, vec3 v ) {
	return vec3( v.x*m.data[0] + v.y*m.data[3] + v.z*m.data[6],
				 v.x*m.data[1] + v.y*m.data[4] + v.z*m.data[7],
				 v.x*m.data[2] + v.y*m.data[5] + v.z*m.data[8] );
}

inline mat3 operator* ( const mat3& n, const mat3& m ) {
	return n.mult<3>( m );
}

inline mat4 expand4(const mat3& m) {
	mat4 n;
	n.data[ 0] = m.data[0]; n.data[ 4] = m.data[3]; n.data[ 8] = m.data[6]; n.data[12] = 0;
	n.data[ 1] = m.data[1]; n.data[ 5] = m.data[4]; n.data[ 9] = m.data[7]; n.data[13] = 0;
	n.data[ 2] = m.data[2]; n.data[ 6] = m.data[5]; n.data[10] = m.data[8]; n.data[14] = 0;
	n.data[ 3] =		 0; n.data[ 7] =		 0; n.data[11] =		 0; n.data[15] = 1;
	return n;
}

inline void PrintMatrix( const mat3& mat ) { PrintMat<3,3>( mat ); }
inline mat4 create4(  float32 n00,float32 n01,float32 n02,float32 n03,
						   float32 n10,float32 n11,float32 n12,float32 n13,
						   float32 n20,float32 n21,float32 n22,float32 n23,
						   float32 n30,float32 n31,float32 n32,float32 n33 )
{
	mat4 n;
	n.data[0] = n00; n.data[4] = n01; n.data[ 8] = n02; n.data[12] = n03;
	n.data[1] = n10; n.data[5] = n11; n.data[ 9] = n12; n.data[13] = n13;
	n.data[2] = n20; n.data[6] = n21; n.data[10] = n22; n.data[14] = n23;
	n.data[3] = n30; n.data[7] = n31; n.data[11] = n32; n.data[15] = n33;
	return n;
}

inline vec4 operator* ( const mat4& n, vec4 v ) {
	return vec4( v.x * n.data[ 0] + v.y * n.data[ 4] + v.z * n.data[ 8] + v.w * n.data[12],
				 v.x * n.data[ 1] + v.y * n.data[ 5] + v.z * n.data[ 9] + v.w * n.data[13],
				 v.x * n.data[ 2] + v.y * n.data[ 6] + v.z * n.data[10] + v.w * n.data[14],
				 v.x * n.data[ 3] + v.y * n.data[ 7] + v.z * n.data[11] + v.w * n.data[15] );
}
inline mat4 operator* ( const mat4& n, const mat4& m ) {
	return n.mult<4>( m );
}

inline matrix<3,3> reduce3( const mat4& n ) {
	matrix<3,3> m;
	m.data[0] = n.data[0]; m.data[3] = n.data[4]; m.data[6] = n.data[ 8];
	m.data[1] = n.data[1]; m.data[4] = n.data[5]; m.data[7] = n.data[ 9];
	m.data[2] = n.data[2]; m.data[5] = n.data[6]; m.data[8] = n.data[10];
	return m;
}

inline void PrintMatrix( const mat4& mat ) { PrintMat<4,4>( mat ); }

// Create basic matrices
DEFINE_EXPORTED_FUNCTION( mat3, translate3, ( vec2 ) );
DEFINE_EXPORTED_FUNCTION( mat4, translate4, ( vec3 ) );
DEFINE_EXPORTED_FUNCTION( mat3, scale3, ( vec2 ) );
DEFINE_EXPORTED_FUNCTION( mat4, scale4, ( vec3 ) );

DEFINE_EXPORTED_FUNCTION( mat3, ortho3, ( vec2, vec2 ) );
DEFINE_EXPORTED_FUNCTION( mat3, ortho3, ( vec2 ) );
DEFINE_EXPORTED_FUNCTION( mat4, ortho4, ( vec2, vec2 ) );
DEFINE_EXPORTED_FUNCTION( mat4, ortho4, ( vec2 ) );
DEFINE_EXPORTED_FUNCTION( mat4, perspect, ( float32,float32,float32,float32 ) );

}

#endif//__MATRIX_N_X_N_234_H__