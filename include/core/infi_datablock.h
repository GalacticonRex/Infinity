#ifndef __INFI_DATABLOCK_H__
#define __INFI_DATABLOCK_H__

#include <cstdlib>
#include <cstring>
#include "core/infi_indexable.h"

namespace INFI {
namespace core {
	
	template<typename T>
	struct data_t : mu_indexable_t<T> {
		
		uint32 alloc;
		T* data;
		
		data_t()
			: alloc(0), data(NULL) { ; }
		data_t(uint32 sz)
			: alloc(sz), data(new T[sz]) { ; }
		data_t(uint32 sz, const T* copy)
			: alloc(sz), data(new T[sz]) {
			memcpy( data, copy, sz*sizeof(T) );
		}
		data_t( std::initializer_list<T> obj )
			: alloc( obj.end() - obj.begin() ), data(new T[alloc]) {
			memcpy( data, obj.begin(), alloc*sizeof(T) );
		}
		
		data_t( const data_t<T>& copy )
			: alloc(copy.alloc), data(new T[alloc]) {
			memcpy( data, copy.data, alloc*sizeof(T) );
		}
		
		data_t& operator= ( const data_t& copy ) {
			delete[] data;
			alloc = copy.alloc;
			data = new T[alloc];
			memcpy( data, copy.data, alloc*sizeof(T) );
			return *this;
		}
		data_t& operator= ( std::initializer_list<T> obj ) {
			delete[] data;
			alloc = obj.end() - obj.begin();
			data = new T[alloc];
			memcpy( data, obj.begin(), alloc*sizeof(T) );
			return *this;
		}
		
		~data_t() { delete[] data; }
		
		T* source() {
			return data;
		}
		const T* source() const {
			return data;
		}
		
		T& operator[] ( uint32 id ) {
			InfiPushFunction( "data_t.[]" );
			if ( id >= alloc )
				InfiSendError( INFI_INDEX_ERROR, 
							   "Attempted to access element at %d, maximum %d", id, alloc );
			InfiPopFunction();
			return data[id];
		}
		const T& operator[] ( uint32 id ) const {
			InfiPushFunction( "data_t.[]" );
			if ( id >= alloc )
				InfiSendError( INFI_INDEX_ERROR, 
							   "Attempted to access element at %d, maximum %d", id, alloc );
			InfiPopFunction();
			return data[id];
		}
		
		uint32 size() const {
			return alloc;
		}
		
		void resize( uint32 nalloc ) {
			if ( nalloc <= alloc )
				return;
			
			T* ndata = new T[nalloc];
			if ( data != NULL ) {
				memcpy( ndata, data, alloc * sizeof(T) );
				free( data );
			}
			
			alloc = nalloc;
			data = ndata;
		}
		void concat( const indexable_t<T>& block ) {
			uint32 nalloc = block.size();
			T* ndata = new T[alloc+nalloc];
			
			memcpy( ndata, data, alloc * sizeof(T) );
			memcpy( ndata + alloc, block.source(), block.size() * sizeof(T) );
			
			alloc += nalloc;
			data = ndata;
		}
	};
	
} }

#endif