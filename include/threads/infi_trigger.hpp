#ifndef __INFI_EVENT_H__
#define __INFI_EVENT_H__

#include <set>
#include <unordered_map>
#include <functional>

#include "base/error_log.hpp"
#include "base/structure.hpp"
#include "threads/infi_thread_defs.hpp"

namespace Infinity {

// can only have 134,217,728 inputs per event :(
struct infi_trigger_t {
protected:

	typedef std::multiset<infi_trigger_t*>::iterator iterator;

	struct {
		unsigned hidden 		: 1;
		unsigned signalled 		: 1;
		unsigned true_on_zero 	: 1;
		signed	 direction 		: 2;
		unsigned count			: 27;
	} _data;

	std::size_t _hash_value;
	std::multiset<infi_trigger_t*> _output;
	std::multiset<infi_trigger_t*> _input;

	bool __invalidated() const;
	void __generate_hash();

	void __add_input(infi_trigger_t*);
	void __add_output(infi_trigger_t*);
	bool __remove_input(infi_trigger_t*);
	bool __remove_output(infi_trigger_t*);

	void __handle_input(infi_trigger_t*, bool, void*);

	void __set_and();
	void __set_or();
	void __set_nand();
	void __set_nor();

	bool __is_and() const;
	bool __is_or() const;
	bool __is_nand() const;
	bool __is_nor() const;

protected:

	virtual void Triggered(infi_trigger_t* source, bool signal, void* data) = 0;

public:

	infi_trigger_t();
	infi_trigger_t( bool init );
	infi_trigger_t( const infi_trigger_t& );
	infi_trigger_t( infi_trigger_t&& );
	virtual ~infi_trigger_t();

	std::size_t gethash() const;
	bool isSignalled() const;

	// send
	void add(infi_trigger_t&);
	bool remove(infi_trigger_t&);
	void run(bool = true, void* = nullptr);
};

}

#endif//__INFI_EVENT_H__
