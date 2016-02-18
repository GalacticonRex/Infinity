#ifndef __INFI_HEAP_H__
#define __INFI_HEAP_H__

#include "main/infi_error.h"
#include "core/infi_sort.h"

namespace INFI {
namespace core {

#define __infi__heapPrev( x ) (x>>1)
#define __infi__heapLeft( x ) ((x<<1)+1)
#define __infi__heapRight( x ) ((x+1)<<1)

template<typename T, SortFunction<T> func>
struct heap_t {
	T* data;
	uint32 alloc;
	uint32 next;
	
	heap_t() : data( new T[8] ), alloc( 8 ), next( 0 ) { }
	~heap_t() { delete[] data; }
	
	uint32 verifydown( uint32 x ) {
		while ( true ) {
			uint32 l = __infi__heapLeft( x );
			uint32 r = __infi__heapRight( x );
			
			bool gol = ( r >= next || func( data[l], data[r] ) );
			uint32 f = (gol) ? l : r;
			
			if ( f < next && func( data[f], data[x] ) ) {
				T tmp = data[x];
				data[x] = data[f];
				data[f] = tmp;
				x = f;
			} else return x;
		}
	}
	void verifyup( uint32 x ) {
		uint32 p;
		while ( x != 0 && func( data[x], data[(p=__infi__heapPrev(x))] ) ) {
			T tmp = data[x];
			data[x] = data[p];
			data[p] = tmp;
			x = p;
		}
	}
	
	T operator[] ( uint32 x ) const {
		InfiPushFunction( "heap_t.[]" );
		if ( x >= next )
			InfiSendError( INFI_INDEX_ERROR,
						   "Cannot index element %d out of %d", x, next );
		InfiPopFunction();
		return data[x];
	}
	
	void insert( const T& obj ) {
		if ( next == alloc ) {
			uint32 oldalloc = alloc;
			alloc *= 2;
			T* tmp = new T[alloc];
			memcpy( tmp, data, oldalloc*sizeof(T) );
			free( data );
			data = tmp;
		}
		data[next] = obj;
		next ++ ;
		
		verifyup( next - 1 );
	}
	void remove( uint32 x = 0 ) {
		InfiPushFunction( "heap_t.remove" );
		if ( next == 0 || x >= next )
			InfiSendError( INFI_INDEX_ERROR,
						   "could not pop index %d out of %d", x, next );
		data[x] = data[next-1];
		verifydown( x );
		next -- ;
		InfiPopFunction();
	}
	
	bool empty() const { return ( next == 0 ); }
	uint32 size() const { return next; }
	int32 indexof( const T& obj ) const {
		for ( uint32 i=0;i<next;i++ )
			if ( data[i] == obj )
				return i;
		return -1;
	}
};

template<typename T, SortFunction<T> S>
std::ostream& operator<< ( std::ostream& ostr, const heap_t<T,S>& hp ) {
	for ( uint32 i=0;i<hp.next;i++ ) {
		ostr << hp.data[i] << " ";
	}
	return ostr;
}

} }

#endif//__INFI_HEAP_H__