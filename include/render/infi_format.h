#ifndef __INFI_VERTEX_FORMAT_H__
#define __INFI_VERTEX_FORMAT_H__

#include "render/infi_gl_control.h"
#include "render/infi_render_structs.h"

namespace INFI {
namespace render {
	
struct infi_field_t {
	core::string_t name;
	infi_t type;
	struct {
		uint32 as_float 	: 1;
		uint32 normalize 	: 1;
		uint32 count		: 10;
		uint32 offset		: 10;
	} data;
	
	infi_field_t();
	infi_field_t( const core::string_t&,
				  infi_t,
				  uint32,
				  bool,
				  bool );
	uint32 get_size() const;
	void enable( uint32, uint32 ) const;
	void enable( uint32, uint32, void* ) const;
	bool operator== ( const infi_field_t& ) const;
	
	void parse( const core::string_t& );
};

struct infi_compressed_format_t {
	uint8* data;
	
	infi_compressed_format_t();
	infi_compressed_format_t( const infi_compressed_format_t& );
	~infi_compressed_format_t();
	
	void compress( const core::indexable_t<infi_field_t>& );
	bool compare( const infi_compressed_format_t& ) const;
};

// fields holds the data type and counts for each vertex attribute in the format
// tag refers to the finalized version of the format
struct infi_format_t {
	core::array_t<infi_field_t>	fields;	// array of fields
	infi_compressed_format_t	tag;	// compressed version of format for comparison
	struct {
		uint32 uptodate 	: 1;	// check if the format nees to be recompiled
		uint32 stride 	: 15;	// size of the format in bytes
	} data;
	
	infi_format_t();
	infi_format_t( const infi_format_t& );
	
	uint32 size() const;
	uint32 stride() const;
	
	uint32 add( const core::string_t&, infi_t, uint32 = 1 );
	uint32 add( const core::string_t&, const core::string_t& );
	void finalize();
	
	void concat( const infi_format_t* );
	
	bool compare( infi_format_t* );
	bool compare( infi_format_t const* );
	bool compare_const( infi_format_t* ) const;
	bool compare_const( infi_format_t const* ) const;
	
	bool operator== ( infi_format_t& );
	bool operator== ( const infi_format_t& );
	bool operator== ( infi_format_t& ) const;
	bool operator== ( const infi_format_t& ) const;
};

// Standard formats
infi_format_t const* Position2();
infi_format_t const* Position3();
infi_format_t const* Position4();

infi_format_t const* Pos2Tex2();
infi_format_t const* Pos2Tex3();
infi_format_t const* Pos2Tex4();

infi_format_t const* Pos3Tex2();
infi_format_t const* Pos3Tex3();
infi_format_t const* Pos3Tex4();

infi_format_t const* Pos4Tex2();
infi_format_t const* Pos4Tex3();
infi_format_t const* Pos4Tex4();

infi_format_t const* Position2Norm();
infi_format_t const* Position3Norm();
infi_format_t const* Position4Norm();

infi_format_t const* Pos2Tex2Norm();
infi_format_t const* Pos2Tex3Norm();
infi_format_t const* Pos2Tex4Norm();

infi_format_t const* Pos3Tex2Norm();
infi_format_t const* Pos3Tex3Norm();
infi_format_t const* Pos3Tex4Norm();

infi_format_t const* Pos4Tex2Norm();
infi_format_t const* Pos4Tex3Norm();
infi_format_t const* Pos4Tex4Norm();

} }

#endif // __INFI_VERTEX_FORMAT_H__