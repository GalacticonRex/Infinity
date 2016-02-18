#ifndef __INFI_PROGRAM_FORMAT_H__
#define __INFI_PROGRAM_FORMAT_H__

#include "render/infi_format.h"
#include "core/infi_map.h"

namespace INFI {
namespace render {
	
	struct infi_program_format_t {
		const infi_format_t* input;
		const infi_format_t* output;
		
		infi_program_format_t();
		infi_program_format_t( const infi_program_format_t& );
		~infi_program_format_t();
		
		void overwrite_input( const infi_format_t* );
		void append_input( const infi_format_t* );
		void overwrite_output( const infi_format_t* );
		void append_output( const infi_format_t* );
	};
	
} }

#endif//__INFI_PROGRAM_FORMAT_H__