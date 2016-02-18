#ifndef __INFI_TRANSFORM_STACK_H__
#define __INFI_TRANSFORM_STACK_H__

#include "core/infi_matrix.h"
#include "core/infi_stack.h"

namespace INFI {
namespace core {

template<uint32 SZ>
struct transform_stack_t
{
	typedef matrix<SZ,SZ> mat_type;
	typedef stack_t<mat_type> mat_stack;
	
	transform_stack_t() { __primary.push( matrix<SZ,SZ>::identity() ); }
	
	void mult( const mat_type& m ) { __primary[0] = __primary[0] * m; }
	
	void reset() {
		__primary.clear();
		__primary.push( matrix<SZ,SZ>::identity() );
	}
	
	void defer() { __primary.push( matrix<SZ,SZ>::identity() ); }
	void push() {
		mat_type tmp = __primary[0];
		__primary.push( tmp ); 
	}
	void push_new() {
		__primary.push( matrix<SZ,SZ>::identity() );
	}
	void pop() { __primary.pop(); }
	
	const mat_type& get() const { return __primary[0]; }
	const mat_type& operator() () const { return __primary[0]; }
	
	private:
		
		mat_stack __primary;
};

typedef transform_stack_t<2> transform2;
typedef transform_stack_t<3> transform3;
typedef transform_stack_t<4> transform4;

} }

#endif//__INFI_TRANSFORM_STACK_H__
