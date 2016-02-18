#include "render/infi_formatted_buffer.h"
#include "core/infi_bitfield.h"
#include <set>

namespace INFI {
namespace render {
	 
	infi_formatter_buffer_internal_t::infi_formatter_buffer_internal_t(
		const infi_buffer_t* b,
		const infi_format_t* a,
		bool inter ) :
		buffer( b ),
		arrangement( a ),
		attach_points( new uint32[a->size()] ) {
		data.interleaved = inter;
		data.references = 1;
	}
	infi_formatter_buffer_internal_t::~infi_formatter_buffer_internal_t() {
		delete[] attach_points;
	}
	
	infi_formatted_buffer_t::infi_formatted_buffer_t() :
		internal(NULL) { ; }
	infi_formatted_buffer_t::infi_formatted_buffer_t( const infi_buffer_t* b,
													  const infi_format_t* f,
													  bool inter ) :
		internal( new infi_formatter_buffer_internal_t( b,f,inter ) ) {
		for ( uint32 i=0;i<f->size();++i )
			internal->attach_points[i] = i;
	}
	infi_formatted_buffer_t::infi_formatted_buffer_t( const infi_buffer_t* b,
													  const infi_format_t* f,
													  const core::indexable_t<uint32>& attach,
													  bool inter ) :
		internal( new infi_formatter_buffer_internal_t( b,f,inter ) ) {
		InfiPushFunction( "infi_formatted_buffer_t.ctor" );
		uint32 sz = attach.size();
		if ( sz != f->size() )
			InfiSendError( INFI_BINDING_ERROR,
						   "cannot bind %d attributes to a format with %d attributes",
						   sz, f->size() );
		
		core::bitfield_t checker;
		for ( uint32 i=0;i<sz;++i ) {
			if ( checker[i] )
				InfiSendError( INFI_INDEX_ERROR,
							   "duplicate index %d in format", attach[i] );
			checker.set( i );
			internal->attach_points[i] = attach[i];
		}
		InfiPopFunction();
	}
	infi_formatted_buffer_t::infi_formatted_buffer_t( const infi_buffer_t* b,
													  const infi_format_t* f,
													  std::initializer_list<uint32> attach,
													  bool inter ) :
		internal( new infi_formatter_buffer_internal_t( b,f,inter ) ) {
		InfiPushFunction( "infi_formatted_buffer_t.ctor" );
		uint32 sz = attach.end() - attach.begin();
		if ( sz != f->size() )
			InfiSendError( INFI_BINDING_ERROR,
						   "cannot bind %d attributes to a format with %d attributes",
						   sz, f->size() );
		
		core::bitfield_t checker;
		auto iter = attach.begin();
		for ( uint32 i=0;i<sz;++i ) {
			uint32 val = *iter;
			if ( checker[val] )
				InfiSendError( INFI_INDEX_ERROR,
							   "duplicate index %d in format", val );
			checker.set( val );
			internal->attach_points[i] = val;
		}
		InfiPopFunction();
	}
	infi_formatted_buffer_t::infi_formatted_buffer_t( const infi_formatted_buffer_t& copy ) :
		internal( copy.internal ) { ++ internal->data.references; }
	infi_formatted_buffer_t::~infi_formatted_buffer_t() {
		if ( internal != NULL && !(-- internal->data.references ) )
			delete internal;
	}
	
	void infi_formatted_buffer_t::enable() const {
		InfiPushFunction( "infi_formatted_buffer.enable" );
		if ( internal == NULL || internal->arrangement == NULL ) {
			InfiSendError( INFI_BINDING_ERROR,
						   "formatted buffer does not have a format" );
		} else {
			uint32 sz = internal->arrangement->size();
			uint32 fstride = internal->arrangement->stride();
			for ( uint32 i=0;i<sz;++i ) {
				uint32 slot = internal->attach_points[i];
				internal->arrangement->fields[i].enable( slot, fstride );
			}
		}
		InfiPopFunction();
	}
	void infi_formatted_buffer_t::enable( uint32 i ) const {
		InfiPushFunction( "infi_formatted_buffer.enable" );
		if ( internal == NULL || internal->arrangement == NULL ) {
			InfiSendError( INFI_BINDING_ERROR,
						   "formatted buffer does not have a format" );
		} else {
			uint32 sz = internal->arrangement->size();
			if ( i >= sz )
				InfiSendError( INFI_INDEX_ERROR,
							   "cannot enable attribute %d out of %d", i, sz );
			uint32 fstride = internal->arrangement->stride();
			uint32 slot = internal->attach_points[i];
			internal->arrangement->fields[i].enable( slot, fstride );
		}
		InfiPopFunction();
	}
	
} }
