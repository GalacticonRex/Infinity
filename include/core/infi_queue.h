#ifndef __INFI_QUEUE_H__
#define __INFI_QUEUE_H__

#include "core/infi_resizable.h"
#include "main/infi_error.h"
#include <iostream>

namespace INFI {
namespace core {

template<typename T>
struct queue_t : resizable_t<T> {
	uint32	start,
			current,
			sz;
	
	queue_t() : resizable_t<T>(),
				start(0), 
				current(0), 
				sz(0) { }
	
	void resize() {
		if ( sz >= resizable_t<T>::allocated() ) {
			
			T* old = resizable_t<T>::copy_array(
							resizable_t<T>::create_array( sz+1 ),
							sz - start, 
							start );
			
			memcpy( resizable_t<T>::get_data() + sz,
					old,
					current * sizeof(T) ); 
			
			free( old );
			current = start + sz;
		}
	}
	
	T& push() {
		resize();
		++ sz;
		uint32 old = current;
		current = (current+1) % resizable_t<T>::allocated();
		return resizable_t<T>::get_data()[old];
	}
	T& push( const T& x ) {
		return ( push() = x );
	}
	
	void clear() {
		sz = 0;
		start = 0;
		current = 0;
	}
	
	uint32 popindex() {
		InfiPushFunction( "queue_t.popindex" );
		if ( sz == 0 )
			InfiSendError( INFI_UNDERFLOW_ERROR,
						   "Cannot pop from an empty queue" );
		
		uint32 old = start;
		start = get_actual_index(0);
		-- sz;
		
		InfiPopFunction();
		return old;
	}
	void pop() {
		InfiPushFunction( "queue_t.pop" );
		(void) popindex();
		InfiPopFunction();
	}
	void pop( T& output ) {
		InfiPushFunction( "queue_t.pop" );
		output = resizable_t<T>::get_data()[popindex()];
		InfiPopFunction();
	}
	
	// pops <i> values from the front
	void popuntil( uint32 i ) {
		InfiPushFunction( "queue_t.popuntil" );
		if ( sz < i )
			InfiSendError( INFI_UNDERFLOW_ERROR,
						   "Cannot pop %d values from %d sized queue", i, sz );
		
		start = get_actual_index(i);
		sz -= i;
		InfiPopFunction();
	};
	
	T& operator[] ( uint32 i ) {
		InfiPushFunction( "queue_t.[]" );
		if ( i >= sz )
			InfiSendError( INFI_INDEX_ERROR,
						   "Cannot index location %d out of %d", i, sz );
		InfiPopFunction();
		return resizable_t<T>::get_item( get_actual_index(i) );
	}
	const T& operator[] ( uint32 i ) const {
		InfiPushFunction( "queue_t.[]" );
		if ( i >= sz )
			InfiSendError( INFI_INDEX_ERROR,
						   "Cannot index location %d out of %d", i, sz );
		InfiPopFunction();
		return resizable_t<T>::get_item( get_actual_index(i) );
	}
	
	T& fromend( uint32 i ) {
		InfiPushFunction( "queue_t.fromend" );
		if ( i >= sz )
			InfiSendError( INFI_INDEX_ERROR,
						   "Cannot index location %d out of %d", i, sz );
		InfiPopFunction();
		return resizable_t<T>::get_item( get_actual_index(i) );
	}
	const T& fromend( uint32 i ) const {
		InfiPushFunction( "queue_t.fromend" );
		if ( i >= sz )
			InfiSendError( INFI_INDEX_ERROR,
						   "Cannot index location %d out of %d", i, sz );
		InfiPopFunction();
		return resizable_t<T>::get_item( get_actual_index(i) );
	}
	
	uint32 size() const { return sz; }
	bool empty() const { return sz == 0; }
	
	uint32 get_inverse_index( uint32 x ) const {
		return (current - (x+1) + resizable_t<T>::allocated())
								% resizable_t<T>::allocated();
	}
	uint32 get_actual_index( uint32 x ) const {
		return (start + x)%resizable_t<T>::allocated();
	}
	uint32 get_apparent_index( uint32 x ) const {
		return ( x + resizable_t<T>::allocated() - start )
					% resizable_t<T>::allocated();
	}
};

template<typename T>
std::ostream& operator<< ( std::ostream& ostr, const queue_t<T>& block ) {
	ostr << "{ ";
	for ( uint32 i=0;i<block.allocated();++i ) {
		if ( i == block.current )
			ostr << "] ";
		if ( i == block.start )
			ostr << "[ ";
		ostr << block.get_data()[i] << " ";
	}
	ostr << "}";
	return ostr;
}

} }

#endif//__INFI_QUEUE_H__
