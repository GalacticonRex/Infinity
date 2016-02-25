#include "render/infi_buffer.h"
#include "render/infi_gl_wrapper.h"
#include "render/infi_gl_control.h"

namespace INFI {
namespace render {
	
	uint32 infi_buffer_t::mapped_buffer = 0;
	uint8* infi_buffer_t::mapped_data = NULL;
	
	uint32 infi_buffer_t::dbg_handle() const {
		return handle;
	}
	void infi_buffer_t::dbg_print() const {
		std::cerr << "H: " << handle << ", R:" << this->references() << std::endl;
	}
	
	void* infi_buffer_t::map_buffer( const char* func, uint32 buf, uint32 access ) {
		InfiPushFunction( func );
		if ( buf == mapped_buffer ) {
			InfiPopFunction();
			return mapped_data;
		} else if ( buf == 0 ) {
			InfiPopFunction();
			return NULL;
		} else {
			InfiGLSetWriteBuffer( buf );
			mapped_data = (uint8*) InfiGLMapBuffer( GL_COPY_WRITE_BUFFER, access );
			mapped_buffer = buf;
			InfiPopFunction();
			return mapped_data;
		}
	}
	void infi_buffer_t::unmap_buffer( const char* func, uint32 buf ) {
		InfiPushFunction( func );
		if ( buf != mapped_buffer ) {
			InfiPopFunction();
			return;
		}
		InfiGLSetWriteBuffer( mapped_buffer );
		InfiGLUnmapBuffer( GL_COPY_WRITE_BUFFER );
		mapped_data = NULL;
		mapped_buffer = 0;
		InfiPopFunction();
	}
	
	static const uint32 INFI_ORIG_MASK	= 0xFF000000,
						INFI_ARRAY_ORIG = 0x80000000, 
						INFI_INDEX_ORIG = 0x40000000,
						INFI_WRITE_ORIG = 0x20000000,
						INFI_READ_ORIG  = 0x10000000,
						
						INFI_TYPE_MASK	= 0x00FC0000,
						
						INFI_TYPE_READ	= 0x00800000,
						INFI_TYPE_DRAW	= 0x00400000,
						INFI_TYPE_COPY	= 0x00200000,
						
						INFI_TYPE_STRM	= 0x00100000,
						INFI_TYPE_DYNAM	= 0x00080000,
						INFI_TYPE_STAT	= 0x00040000;
						
	static uint32 convert_wrc_enum( INFI_array_write wr ) {
		switch( wr ) {
			case INFI_W_STREAM:
				return INFI_TYPE_DRAW | INFI_TYPE_STRM; break;
			case INFI_W_DYNAMIC:
				return INFI_TYPE_DRAW | INFI_TYPE_DYNAM; break;
			case INFI_W_STATIC:
				return INFI_TYPE_DRAW | INFI_TYPE_STAT; break;
			case INFI_R_STREAM:
				return INFI_TYPE_READ | INFI_TYPE_STRM; break;
			case INFI_R_DYNAMIC:
				return INFI_TYPE_READ | INFI_TYPE_DYNAM; break;
			case INFI_R_STATIC:
				return INFI_TYPE_READ | INFI_TYPE_STAT; break;
			case INFI_C_STREAM:
				return INFI_TYPE_COPY | INFI_TYPE_STRM; break;
			case INFI_C_DYNAMIC:
				return INFI_TYPE_COPY | INFI_TYPE_DYNAM; break;
			case INFI_C_STATIC:
				return INFI_TYPE_COPY | INFI_TYPE_STAT; break;
			default:
				return 0;
		}
	}
	static INFI_array_write convert_wrc_mask( uint32 wr ) {
		wr &= INFI_TYPE_MASK;
		switch( wr ) {
			case INFI_TYPE_DRAW | INFI_TYPE_STRM:
				return INFI_W_STREAM; break;
			case INFI_TYPE_DRAW | INFI_TYPE_DYNAM:
				return INFI_W_DYNAMIC; break;
			case INFI_TYPE_DRAW | INFI_TYPE_STAT:
				return INFI_W_STATIC; break;
			case INFI_TYPE_READ | INFI_TYPE_STRM:
				return INFI_R_STREAM; break;
			case INFI_TYPE_READ | INFI_TYPE_DYNAM:
				return INFI_R_DYNAMIC; break;
			case INFI_TYPE_READ | INFI_TYPE_STAT:
				return INFI_R_STATIC; break;
			case INFI_TYPE_COPY | INFI_TYPE_STRM:
				return INFI_C_STREAM; break;
			case INFI_TYPE_COPY | INFI_TYPE_DYNAM:
				return INFI_C_DYNAMIC; break;
			case INFI_TYPE_COPY | INFI_TYPE_STAT:
				return INFI_C_STATIC; break;
			default:
				return INFI_W_STREAM;
		}
	}
	
	infi_buffer_t::infi_buffer_t( INFI_array_write wr ) :
		infi_storage_t(),
		flags( convert_wrc_enum(wr) ),
		byteuse(0),
		bytesize(0) { }
	infi_buffer_t::infi_buffer_t( const core::indexable_t<uint8>& arr,
								  INFI_array_write wr ) :
		infi_storage_t(),
		flags( convert_wrc_enum(wr) ),
		byteuse( arr.size() ),
		bytesize( arr.size() ) {
		handle = store_create_data();
		InfiGLSetWriteBuffer( handle );
		InfiGLBufferData( GL_COPY_WRITE_BUFFER,
						  bytesize,
						  arr.source(),
						  wr );
		flags |= INFI_WRITE_ORIG;
	}
	infi_buffer_t::infi_buffer_t( const infi_buffer_t& copy ) :
		infi_storage_t( copy ),
		flags( copy.flags ),
		byteuse( copy.byteuse ),
		bytesize( copy.bytesize ) { ; }
	
	infi_buffer_t::~infi_buffer_t() {
		decrement();
	}
	
	uint32 infi_buffer_t::store_create_data() {
		uint32 temp;
		InfiGLGenBuffers( 1, &temp );
		return temp;
	}
	uint32 infi_buffer_t::store_copy_data() {
		uint32 temp = this->store_create_data();
		
		InfiGLSetWriteBuffer( temp );
		InfiGLSetReadBuffer( handle );
		
		INFI_array_write wr = convert_wrc_mask(flags);
		InfiGLBufferData( GL_COPY_WRITE_BUFFER, bytesize, 0, wr );
		InfiGLCopyBufferSubData( GL_COPY_READ_BUFFER,
								 GL_COPY_WRITE_BUFFER,
								 0,0, byteuse );
		flags = ( flags & ~INFI_ORIG_MASK ) | INFI_WRITE_ORIG;
		
		return temp;
	}
	void infi_buffer_t::store_destroy_data() {
		InfiGLDeleteBuffers( 1, &handle );
	}
	
	void infi_buffer_t::setData( const core::indexable_t<uint8>& data ) {
		std::cerr << "set data" << std::endl;
		if ( fork_data() || data.size() > bytesize ) {
			InfiGLSetWriteBuffer( handle );
			
			bytesize = data.size();
			
			uint8* current = new uint8[bytesize];
			InfiGLGetBufferSubData( GL_COPY_WRITE_BUFFER,
									0,
									byteuse,
									current );
			
			byteuse = data.size();
			
			InfiGLBufferData( GL_COPY_WRITE_BUFFER,
							  bytesize,
							  current,
							  convert_wrc_mask(flags) );
			flags = ( flags & ~INFI_ORIG_MASK ) | INFI_WRITE_ORIG;
			
			delete[] current;
		} else {
			InfiGLSetWriteBuffer( handle );
			byteuse = std::max( byteuse, data.size() );
		}
		
		InfiGLBufferSubData( GL_COPY_WRITE_BUFFER,
							 0,
							 data.size(),
							 data.source() );
	}
	void infi_buffer_t::setData( uint32 offset, const core::indexable_t<uint8>& data ) {
		if ( fork_data() || data.size() + offset > bytesize ) {
			InfiGLSetWriteBuffer( handle );
			
			bytesize = data.size() + offset;
			
			char* current = new char[bytesize];
			InfiGLGetBufferSubData( GL_COPY_WRITE_BUFFER,
									0,
									byteuse,
									current );
			
			byteuse = data.size() + offset;
			
			InfiGLBufferData( GL_COPY_WRITE_BUFFER,
							  bytesize,
							  current,
							  convert_wrc_mask(flags) );
			flags = ( flags & ~INFI_ORIG_MASK ) | INFI_WRITE_ORIG;
			
			delete[] current;
		} else {
			InfiGLSetWriteBuffer( handle );
			byteuse = std::max( byteuse, data.size() + offset );
		}
		
		InfiGLBufferSubData( GL_COPY_WRITE_BUFFER,
							 offset,
							 data.size(),
							 data.source() );
	}
	void infi_buffer_t::getData( core::data_t<uint8>& output ) const {
		unmap_buffer( "infi_buffer.getData", handle );
		InfiPushFunction( "infi_buffer.getData" );
		InfiGLSetReadBuffer( handle );
		output.resize( bytesize );
		InfiGLGetBufferSubData( GL_COPY_READ_BUFFER,
								0,
								bytesize,
								output.source() );
		InfiPopFunction();
	}
	
	void infi_buffer_t::resizeData( uint32 need ) {
		InfiPushFunction( "infi_buffer.resizeData" );
		if ( fork_data() || need > bytesize ) {
			InfiGLSetWriteBuffer( handle );
			InfiGLBufferData( GL_COPY_WRITE_BUFFER,
							  need,
							  NULL,
							  convert_wrc_mask(flags) );
			bytesize = need;
			byteuse = 0;
		}
		InfiPopFunction();
	}
	
	uint8 infi_buffer_t::operator[] ( uint32 index ) const {
		InfiPushFunction( "infi_buffer.[]" );
		if ( index >= byteuse )
			InfiSendError( INFI_INDEX_ERROR,
						   "cannot index buffer at %d out of %d", index, byteuse );
		InfiPopFunction();
		uint8* mapped = (uint8*) map_buffer( "infi_buffer.[]", handle, GL_READ_WRITE );
		return mapped[index];
	}
	void* infi_buffer_t::operator* () const {
		return map_buffer( "(*infi_buffer)", handle, GL_READ_WRITE );
	}
	
	void const* infi_buffer_t::read() const {
		return map_buffer( "infi_buffer.read", handle, GL_READ_ONLY );
	}
	void* infi_buffer_t::write() const {
		return map_buffer( "infi_buffer.write",handle, GL_WRITE_ONLY );
	}

} }
