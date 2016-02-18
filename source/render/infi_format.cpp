#include "render/infi_format.h"
#include "render/infi_gl_wrapper.h"


namespace INFI {
namespace render {

infi_field_t::infi_field_t() :
	name( "New Field" ),
	type( INFI_FLOAT ) {
	data.as_float = 1;
	data.normalize = 0;
	data.count = 0;
	data.offset = 0;
}
	
infi_field_t::infi_field_t( const core::string_t& a,
							infi_t b,
							uint32 c,
							bool asf,
							bool norm ) :
	name( a ),
	type( b ) {
	data.as_float = asf;
	data.normalize = norm;
	data.count = c;
	data.offset = 0;
}
	
uint32 infi_field_t::get_size() const {
	return data.count * infi_sizeof( type );
}
void infi_field_t::enable( uint32 slot, uint32 stride ) const {
	InfiGLVertexAttribPointer( slot,
							   data.count,
							   type,
							   data.normalize,
							   stride,
							   (void*) (long) data.offset );
}
void infi_field_t::enable( uint32 slot, uint32 stride, void* retarget ) const {
	InfiGLVertexAttribPointer( slot,
							   data.count,
							   type,
							   data.normalize,
							   stride,
							   (void*)((uint8*)retarget + data.offset) );
}
bool infi_field_t::operator== ( const infi_field_t& nf ) const {
	return ( nf.type == type && nf.data.count == data.count );
}
void infi_field_t::parse( const core::string_t& value ) {
	if ( value == "vec2" ) {
		type = INFI_FLOAT;
		data.count = 2; 
	} else if ( value == "vec3" ) {
		type = INFI_FLOAT;
		data.count = 3;
	} else if ( value == "vec4" ) {
		type = INFI_FLOAT;
		data.count = 4;
	} else if ( value == "mat2" ) {
		type = INFI_FLOAT;
		data.count = 4;
	} else if ( value == "mat3" ) {
		type = INFI_FLOAT;
		data.count = 9;
	} else if ( value == "mat4" ) {
		type = INFI_FLOAT;
		data.count = 16;
	} else if ( value == "float" ) {
		type = INFI_FLOAT;
		data.count = 1;
	} else if ( value == "int" ) {
		type = INFI_INT;
		data.count = 1;
	} else if ( value == "uint" ) {
		type = INFI_UINT;
		data.count = 1;
	} else {
		type = INFI_NONE;
		data.count = 0;
	}
}

infi_compressed_format_t::infi_compressed_format_t()
	: data( NULL ) { ; }
infi_compressed_format_t::infi_compressed_format_t( const infi_compressed_format_t& copy ) {
	if ( copy.data != NULL ) {
		uint32 sz = strlen( (const char*) copy.data );
		data = new uint8[sz+1];
		strcpy( (char*) data, (const char*) copy.data );
	}
}
infi_compressed_format_t::~infi_compressed_format_t() {
	delete[] data;
}

#define CASE_RESULT( c, r ) \
		case c: return r; break;
		
const uint8 INFI_RESOLVE_NEW_FIELD = 15; 
static uint8 translate( infi_t t ) {
	switch( t ) {
		CASE_RESULT( INFI_BOOL, 1 );
		CASE_RESULT( INFI_BYTE, 2 );
		CASE_RESULT( INFI_UBYTE, 3 );
		CASE_RESULT( INFI_SHORT, 4 );
		CASE_RESULT( INFI_USHORT, 5 );
		CASE_RESULT( INFI_FLOAT, 6 );
		CASE_RESULT( INFI_DOUBLE, 7 );
		CASE_RESULT( INFI_INT, 8 );
		CASE_RESULT( INFI_UINT, 9 );
		default:
			return 0;
	}
}

void infi_compressed_format_t::compress( const core::indexable_t<infi_field_t>& obj ) {
	InfiPushFunction( "infi_compressed_format.compress" );
	
	core::array_t<uint8> arr;
	uint8 buffer = 0;
	for ( uint32 i=0;i<obj.size();++i ) {
		uint8 trans = translate( obj[i].type );
		if ( trans == 0 )
			InfiSendError( INFI_TYPE_ERROR,
						   "invalid format field at index %d", i );
		uint8 dtrans = trans | ( trans << 4 );
		
		uint32 j = 0;
		if ( buffer != 0 ) {
			arr.add( (INFI_RESOLVE_NEW_FIELD << 4) | buffer );
			buffer = 0;
		} else {
			arr.add( INFI_RESOLVE_NEW_FIELD | ( trans << 4 ) );
			j = 1;
		}
		for ( ;j<uint32(obj[i].data.count/2);++j )
			arr.add( dtrans );
		if ( obj[i].data.count % 2 )
			buffer = trans;
	}
	arr.add( 0 );
	if ( data == NULL ) {
		data = new uint8[arr.size()];
	} else {
		uint32 sz = strlen( (const char*) data );
		if ( sz < arr.size() ) {
			delete[] data;
			data = new uint8[arr.size()];
		}
	}
	memcpy( data, arr.source(), arr.size() );
	
	InfiPopFunction();
}
bool infi_compressed_format_t::compare( const infi_compressed_format_t& other ) const {
	return ( other.data == NULL ) ? ( data == NULL ) : 
		   ( strcmp( (const char*)data, (const char*)other.data ) == 0 );
}


infi_format_t::infi_format_t() { 
	data.uptodate = 0;
	data.stride = 0;
}
infi_format_t::infi_format_t( const infi_format_t& form ) :
	fields( form.fields ),
	tag( form.tag ),
	data( form.data ) { ; }
	
uint32 infi_format_t::size() const {
	return fields.size();
}
uint32 infi_format_t::stride() const {
	if ( fields.size() == 0 ) {
		return 0;
	} else {
		const infi_field_t& f = fields[fields.size()-1];
		return f.data.offset + f.get_size();
	}
}

uint32 infi_format_t::add( const core::string_t& name,
						   infi_t type,
						   uint32 count ) {
	InfiPushFunction( "infi_format_t.add" );
	infi_field_t nf( name, type, count, true, false );
	nf.data.offset = ( fields.size() == 0 ) ? 0 :
						fields[fields.size()-1].data.offset +
						fields[fields.size()-1].get_size();
	fields.add( nf );
	data.uptodate = false;
	InfiPopFunction();
	return fields.size()-1;
}
uint32 infi_format_t::add( const core::string_t& name, const core::string_t& type ) {
	InfiPushFunction( "infi_format_t.add" );
	uint32 sz = fields.size();
	infi_field_t& nf = fields.add();
	nf.parse( type );
	if ( nf.type == INFI_NONE )
		InfiSendError( INFI_TYPE_ERROR,
					   "cannot add type %s to format", type.localize().source() );
	nf.name = name;
	nf.data.offset = ( sz == 0 ) ? 0 :
						fields[sz-1].data.offset +
						fields[sz-1].get_size();
	data.uptodate = false;
	InfiPopFunction();
	return fields.size()-1;
}
void infi_format_t::finalize() {
	if ( !data.uptodate ) {
		InfiPushFunction( "infi_format_t.finalize" );
		tag.compress( fields );
		data.uptodate = 1;
		InfiPopFunction();
	}
}

void infi_format_t::concat( const infi_format_t* form ) {
	fields.concat( form->fields );
	data.stride += form->data.stride;
	data.uptodate = false;
}

static bool comp_formats( const infi_format_t* A,
						  const infi_format_t* B ) {
	if ( A->fields.size() != B->fields.size() ) {
		return false;
	} if ( !A->data.uptodate || !B->data.uptodate ) {
		for ( uint32 i=0;i<A->fields.size();++i )
			if ( !(A->fields[i] == B->fields[i]) )
				return false;
		return true;
	} else {
		return A->tag.compare( B->tag );
	}
}
bool infi_format_t::compare( infi_format_t* other ) {
	InfiPushFunction( "infi_format_t.compare" );
	this->finalize();
	other->finalize();
	bool ret = comp_formats( this, other );
	InfiPopFunction();
	return ret;
}
bool infi_format_t::compare( infi_format_t const* other ) {
	InfiPushFunction( "infi_format_t.compare" );
	this->finalize();
	bool ret = comp_formats( this, other );
	InfiPopFunction();
	return ret;
}
bool infi_format_t::compare_const( infi_format_t* other ) const {
	InfiPushFunction( "infi_format_t.compare" );
	other->finalize();
	bool ret = comp_formats( this, other );
	InfiPopFunction();
	return ret;
}
bool infi_format_t::compare_const( infi_format_t const* other ) const {
	InfiPushFunction( "infi_format_t.compare" );
	bool ret = comp_formats( this, other );
	InfiPopFunction();
	return ret;
}

bool infi_format_t::operator== ( infi_format_t& other ) {
	return this->compare( &other );
}
bool infi_format_t::operator== ( const infi_format_t& other ) {
	return this->compare( &other );
}
bool infi_format_t::operator== ( infi_format_t& other ) const {
	return this->compare_const( &other );
}
bool infi_format_t::operator== ( const infi_format_t& other ) const {
	return this->compare_const( &other );
}

} }