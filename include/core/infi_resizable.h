#ifndef __INFI_RESIZABLE_H__
#define __INFI_RESIZABLE_H__

#include "main/infi_types.h"
#include <cstdlib>
#include <cstring>

namespace INFI {
namespace core {
	
	template<typename T>
	struct resizable_t {
		
		resizable_t() : alloc(0), data(NULL) { }
		resizable_t(uint32 nsz) : alloc(nsz), data(new T[alloc]) { }
		resizable_t(const resizable_t<T>& copy ) {
			alloc = copy.alloc;
			data = new T[alloc];
			memcpy( data, copy.data, alloc * sizeof(T) );
		}
		virtual ~resizable_t() { delete[] data; }
		
		uint32 allocated() const { return alloc; }
		
		T* get_data() { return data; }
		const T* get_data() const { return data; }
		
		T& get_item( uint32 i ) { return data[i]; }
		const T& get_item( uint32 i ) const { return data[i]; }
		 
	protected:
		
		// either creates a new array if there is not enough
		// allocated space or returns the current array
		T* create_array( uint32 nsz ) {
			if ( nsz < alloc )
				return data;
			
			uint32 nalloc = (alloc==0) ? 8 : alloc << 1;
			while( nsz > nalloc )
				nalloc <<= 1;
			
			alloc = nalloc;
			
			return new T[nalloc];
		}
		
		// copies the contents of the current array
		// to a new one
		// returns the current array, or a null if
		// the new array is the same as the old
		T* copy_array( T* arg, uint32 gsz, uint32 offset = 0 ) {
			if ( arg == data )
				return NULL;
			
			T* old = data;
			
			if ( data != NULL && gsz != 0 )
				memcpy( arg, data, (gsz+offset) * sizeof(T) );
			
			data = arg;
			
			return old;
		}
		
		// resizes the current array to fit the incoming size
		void realloc_array( uint32 oldsz, uint32 newsz ) {
			free( copy_array( create_array( newsz ), oldsz ) );
		}
		
	private:
		
		uint32 alloc;
		T* data;
		
	};
		
} }

#endif//__INFI_RESIZABLE_H__