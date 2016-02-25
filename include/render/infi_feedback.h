#ifndef __INFI_FEEDBACK_H__
#define __INFI_FEEDBACK_H__

#include "render/infi_program.h"
#include "render/infi_buffer.h"

namespace INFI {
namespace render {
	
	INFI_FUNCTION( void, InfiEnableFeedback, () );
	INFI_FUNCTION( void, InfiDisableFeedback, () );
	
	INFI_FUNCTION(infi_buffer_t const*,InfiAssignFeedback,( infi_program_t*, 		// Shader to Assign to
															const infi_format_t*,	// Vertex Format of Outgoing Data
															uint32 count,			// Number of Outgoing Attributes
															const char** ) );		// ...
	
	INFI_FUNCTION(infi_buffer_t const*,InfiAssignFeedback,( infi_program_t*,
															const infi_format_t*,
															std::initializer_list<const char*> ) );
	
} }

#endif//__INFI_FEEDBACK_H__