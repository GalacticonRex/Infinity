#ifndef __INFI_ARRAY_H__
#define __INFI_ARRAY_H__

#include <string.h>
#include "core/infi_indexable.h"
#include "core/infi_resizable.h"

namespace INFI {
namespace core {
	
	template<typename T>
	struct array_t : mu_indexable_t<T>, resizable_t<T> {
		
		array_t() : sz(0) { ; }
		array_t(uint32 nsz)
			: resizable_t<T>(nsz), sz(nsz) { ; }
		array_t(uint32 nsz, const T* copy)
			: resizable_t<T>(nsz), sz(nsz) {
			memcpy( resizable_t<T>::get_data(), 
					copy, 
					sz*sizeof(T) );
		}
		array_t(std::initializer_list<T> obj )
			: resizable_t<T>(obj.end() - obj.begin()),
			  sz( resizable_t<T>::allocated() ) {
			memcpy( resizable_t<T>::get_data(), 
					obj.begin(), 
					sz*sizeof(T) );
		}
		
		array_t( const array_t<T>& copy )
			: resizable_t<T>(copy), sz(copy.sz) { }
		
		array_t& operator= (const array_t& copy) {
			resizable_t<T>::realloc_array( 0, copy.sz );
			sz = copy.sz;
			memcpy( resizable_t<T>::get_data(), 
					copy.get_data(), 
					sz*sizeof(T) );
			return *this;
		}
		array_t& operator= (std::initializer_list<T> obj) {
			sz = obj.end() - obj.begin();
			resizable_t<T>::realloc_array( 0, sz );
			memcpy( resizable_t<T>::get_data(), obj.begin(), sz*sizeof(T) );
			return *this;
		}
		
		T& operator[] ( uint32 id ) {
			InfiPushFunction( "array_t.[]" );
			if ( id >= sz )
				InfiSendError( INFI_INDEX_ERROR, 
							   "Attempted to access element at %d, maximum %d", id, sz );
			InfiPopFunction();
			return resizable_t<T>::get_item(id);
		}
		const T& operator[] ( uint32 id ) const {
			InfiPushFunction( "array_t.[]" );
			if ( id >= sz )
				InfiSendError( INFI_INDEX_ERROR, 
							   "Attempted to access element at %d, maximum %d", id, sz );
			InfiPopFunction();
			return resizable_t<T>::get_item(id);
		}
		
		uint32 size() const { return sz; }
		
		T* source() { return resizable_t<T>::get_data(); }
		const T* source() const { return resizable_t<T>::get_data(); }
		
		T& add() {
			resizable_t<T>::realloc_array( sz, sz+1 );
			++ sz;
			return resizable_t<T>::get_item(sz-1);
		}
		T& add( const T& n ) {
			return ( add() = n );
		}
		
		uint32& insert( uint32 index ) {
			InfiPushFunction( "array_t.insert" );
			
			if ( index > sz )
				InfiSendError( INFI_INDEX_ERROR,
							   "Attempted to insert at location %d, maximum %d", index, sz );
			
			T* old = resizable_t<T>::copy_array( resizable_t<T>::create_array( sz+1 ), index+1 );
			memcpy( resizable_t<T>::get_data() + index + 1, 
					old + index,
					(sz - index) * sizeof(T) );
			
			free( old );
			
			++ sz;
			
			InfiPopFunction();
			
			return resizable_t<T>::get_item(index);
		}
		uint32& insert( uint32 index, const T& n ) {
			return ( insert( index ) = n );
		}
		
		void remove( uint32 index ) {
			InfiPushFunction( "array_t.remove" );
			if ( index >= sz )
				InfiSendError( INFI_INDEX_ERROR,
							   "Attempted to remove from location %d, maximum %d", index, sz );
			memcpy( resizable_t<T>::get_data() + index,
					resizable_t<T>::get_data() + index + 1, 
					(sz - index) * sizeof(T) ); 
			-- sz;
			InfiPopFunction();
		}
		void remove( uint32 index, uint32 span ) {
			InfiPushFunction( "array_t.remove" );
			if ( span == 0 ) {
				InfiPopFunction();
				return;
			}
			
			if ( index + span > sz )
				InfiSendError( INFI_INDEX_ERROR,
							   "Attempted to remove a span of %d elements from location %d, maximum %d", span, index, sz );
			
			memcpy( resizable_t<T>::get_data() + index,
					resizable_t<T>::get_data() + index + span, 
					(sz - index - span + 1) * sizeof(T) ); 
			sz -= span;	
			InfiPopFunction();
		}
		
		void resize( uint32 nalloc ) {
			resizable_t<T>::realloc_array( sz, nalloc );
			sz = nalloc;
		}
		void concat( const indexable_t<T>& block ) {
			uint32 nalloc = sz + block.size();
			resizable_t<T>::realloc_array( sz, nalloc );
			memcpy( resizable_t<T>::get_data() + sz, 
					block.source(),
					block.size() * sizeof(T) ); 
			sz = nalloc;
		}
		
		void clear() {
			sz = 0;
		}
		
	private:
		
		uint32 sz;
		
	};
	
} }

#endif//__INFI_ARRAY_H__