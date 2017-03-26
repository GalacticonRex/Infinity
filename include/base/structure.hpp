#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__

#define LOCAL_STRUCT_NAME( _name, _parent ) \
		_parent::__local_struct_ ## _name ## __

#define LOCAL_STRUCTURE( _name, _parent, _internal ) \
		struct __local_struct_ ## _name ## __ { \
		private: \
			_parent* __parent__; \
			__local_struct_ ## _name ## __( _parent* A ) \
				: __parent__( A ){ ; } \
			__local_struct_ ## _name ## __( const __local_struct_ ## _name ## __& ) { ; } \
			~__local_struct_ ## _name ## __() { ; }  \
			void operator= ( const __local_struct_ ## _name ## __& ) { ; } \
		public: \
			_internal \
			friend struct _parent; \
		} _name; \
		friend struct __local_struct_ ## _name ## __;

class does_not_copy
{
protected:
	does_not_copy() = default;
	~does_not_copy() = default;

	does_not_copy(does_not_copy const &) = delete;
	void operator=(does_not_copy const &) = delete;
};

struct __print_on_creation__ {
	__print_on_creation__( const char* );
};
struct __print_on_destruction__ {
	const char* print;
	__print_on_destruction__( const char* );
	virtual ~__print_on_destruction__();
};
struct __print_on_both__ : public __print_on_creation__, public __print_on_destruction__ {
	__print_on_both__( const char* );
};

#endif//__STRUCTURE_H__
