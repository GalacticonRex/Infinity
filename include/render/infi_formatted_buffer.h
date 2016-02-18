#ifndef __INFI_FORMATTED_BUFFER_H__
#define __INFI_FORMATTED_BUFFER_H__

#include "render/infi_buffer.h"
#include "render/infi_format.h"

namespace INFI {
namespace render {
	
	struct infi_formatter_buffer_internal_t {
		// basic data
		const infi_buffer_t* buffer;
		const infi_format_t* arrangement;
		
		// formatting when added
		struct {
			uint32 interleaved : 1;  // is the data in this buffer interleaved or divided by attribute
			uint32 references : 30;
		} data;
		
		uint32* attach_points;
		
		infi_formatter_buffer_internal_t( const infi_buffer_t*,
										  const infi_format_t*,
										  bool );
		~infi_formatter_buffer_internal_t();
	};
	
	struct infi_formatted_buffer_t {
		infi_formatter_buffer_internal_t* internal;
		
		infi_formatted_buffer_t();
		infi_formatted_buffer_t( const infi_buffer_t*,
								 const infi_format_t*,
								 bool = true );
		infi_formatted_buffer_t( const infi_buffer_t*,
								 const infi_format_t*,
								 const core::indexable_t<uint32>&,
								 bool = true );
		infi_formatted_buffer_t( const infi_buffer_t*,
								 const infi_format_t*,
								 std::initializer_list<uint32>,
								 bool = true );
		infi_formatted_buffer_t( const infi_formatted_buffer_t& );
		~infi_formatted_buffer_t();
		
		const infi_buffer_t* buffer() const { return internal->buffer; }
		const infi_format_t* format() const { return internal->arrangement; }
		uint32 index( uint32 i ) const { return internal->attach_points[i]; }
		
		void enable() const;
		void enable( uint32 ) const;
	};
	
} }

#endif//__INFI_FORMATTED_BUFFER_H__