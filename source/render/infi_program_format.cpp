#include "render/infi_program_format.h"
#include <iostream>

namespace INFI {
namespace render {
	
	infi_program_format_t::infi_program_format_t() :
		input( NULL ),
		output( NULL ) { }
	infi_program_format_t::infi_program_format_t( const infi_program_format_t& copy ) {
		input = new infi_format_t( *copy.input );
		output = new infi_format_t( *copy.output );
	}
	infi_program_format_t::~infi_program_format_t() {
		delete input;
		delete output;
	}
	
	void infi_program_format_t::overwrite_input( const infi_format_t* form ) {
		delete input;
		input = form;
	}
	void infi_program_format_t::append_input( const infi_format_t* form ) {
		infi_format_t* nform;
		if ( input != NULL ) {
			nform = new infi_format_t( *input );
			nform->concat( form );
			delete input;
		} else {
			nform = new infi_format_t( *form );
		}
		nform->finalize();
		input = nform;
	}
	void infi_program_format_t::overwrite_output( const infi_format_t* form ) {
		delete output;
		output = form;
	}
	void infi_program_format_t::append_output( const infi_format_t* form ) {
		infi_format_t* nform;
		if ( output != NULL ) {
			nform = new infi_format_t( *output );
			nform->concat( form );
			delete output;
		} else {
			nform = new infi_format_t( *form );
		}
		nform->finalize();
		output = nform;
	}
	
} }