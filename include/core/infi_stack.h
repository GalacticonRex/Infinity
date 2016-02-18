#ifndef __INFI_STACK_H__
#define __INFI_STACK_H__

#include <cstddef>
#include "main/infi_types.h"
#include "main/infi_error.h"

#include "core/infi_resizable.h"

namespace INFI {
namespace core {
	
	template<typename T>
	struct stack_t : resizable_t<T> {
		private:
			
			uint32 sz;
			
		public:
			
		stack_t() : sz(0) { }
		stack_t( const T& item) : resizable_t<T>(1), sz(0) {
			resizable_t<T>::get_item(0) = item;
		}
		stack_t( const stack_t<T>& copy )
			: resizable_t<T>(copy), sz( copy.sz ) { }

		stack_t& operator=( const stack_t& st ) {
			T* nbuffer = resizable_t<T>::realloc_array( 0, st.sz );
			sz = st.sz;
			memcpy( resizable_t<T>::get_data(), 
					st.get_data(),
					sz*sizeof(T) );
			return *this;
		}
		
		void clear() { sz = 0; }
		
		void push() {
			resizable_t<T>::realloc_array( sz, sz + 1 );
			resizable_t<T>::get_item(sz) = T();
			++ sz;
		}
		void push( const T& i ) {
			resizable_t<T>::realloc_array( sz, sz + 1 );
			resizable_t<T>::get_item(sz) = i;
			++ sz;
		}
		
		void pop() {
			if ( sz == 0 )
				return;
			-- sz;
		}
		void pop( T& output ) {
			InfiPushFunction( "stack_t.pop" );
			if ( sz == 0 )
				InfiSendError( INFI_UNDERFLOW_ERROR,
							   "Cannot return first element of empty stack" );
			-- sz;
			output = resizable_t<T>::get_item(sz);
			InfiPopFunction();
		}
		
		T& operator* () {
			InfiPushFunction( "stack_t.deref*" );
			if ( sz == 0 )
				InfiSendError( INFI_UNDERFLOW_ERROR,
							   "Cannot dereference empty stack" );
			InfiPopFunction();
			return resizable_t<T>::get_item(sz-1);
		}
		T& operator[] ( uint32 x ) {
			InfiPushFunction( "stack_t.[]" );
			if ( x >= sz )
				InfiSendError( INFI_INDEX_ERROR,
							   "Cannot fetch element %d of %d", x, sz );
			InfiPopFunction();
			return resizable_t<T>::get_item(sz-x-1);
		}
		const T& operator[] ( uint32 x ) const {
			InfiPushFunction( "stack_t.[]" );
			if ( x >= sz )
				InfiSendError( INFI_INDEX_ERROR,
							   "Cannot fetch element %d of %d", x, sz );
			InfiPopFunction();
			return resizable_t<T>::get_item(sz-x-1);
		}
		
		T& get_base( uint32 x ) {
			InfiPushFunction( "stack_t.get_base" );
			if ( x >= sz )
				InfiSendError( INFI_INDEX_ERROR,
							   "Cannot fetch base element %d of %d", x, sz );
			InfiPopFunction();
			return resizable_t<T>::get_item(x);
		}
		const T& get_base( uint32 x ) const {
			InfiPushFunction( "stack_t.get_base" );
			if ( x >= sz )
				InfiSendError( INFI_INDEX_ERROR,
							   "Cannot fetch base element %d of %d", x, sz );
			InfiPopFunction();
			return resizable_t<T>::get_item(x);
		}
		
		uint32 size() const { return sz; }
		bool empty() const { return ( sz == 0 ); }
	};
	
} }

#endif//__INFI_STACK_H__