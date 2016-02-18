#ifndef __INFI_RED_BLACK_TREE_H__
#define __INFI_RED_BLACK_TREE_H__

#include <type_traits>

#include "main/infi_types.h"
#include "main/infi_export.h"

namespace INFI {
namespace core {
	
	#define RB_TREE_COLOR_BLACK 1
	#define RB_TREE_COLOR_RED 0
	
	struct INFI_EXPORT rb_tree_node_t {
		virtual uint32 get_reference() const { return 0; }
		virtual void color( bool ) = 0;
		virtual bool black() const = 0;
		virtual bool red() const = 0;
	};
	
	template<typename T>
	struct INFI_EXPORT rb_tree_t {
		
		static_assert( std::is_base_of<rb_tree_node_t, T>::value,
					   "template must inherit from rb_tree_node_t" );
		
		struct node {
			T* data;
			node* parent;
			node* left;
			node* right;
			
			node() : data(NULL),
					 parent(NULL), 
					 left(NULL), 
					 right(NULL) { }
			
			node* grandparent() const {
				if ( parent != NULL )
					return parent->parent;
				else
					return NULL;
			}
			node* uncle( node* gr ) const {
				if ( gr != NULL ) {
					if ( parent == gr->left )
						return gr->right;
					else
						return gr->left;
				} else
					return NULL;
			}
		};
		
		node *root,
			 *current;
		
		void left_rotate( node* x ) {
			node* y = x->right;
			
			x->right = y->left;
			if ( y->left != NULL )
				y->left->parent = x;
			
			y->parent = x->parent;
			if ( x->parent == NULL ) {
				root = y;
			} else {
				if ( x == x->parent->left ) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
			}
			
			y->left = x;
			x->parent = y;
		}
		void right_rotate( node* x ) {
			node* y = x->left;
			
			x->left = y->right;
			if ( y->right != NULL )
				y->right->parent = x;
			
			y->parent = x->parent;
			if ( x->parent == NULL ) {
				root = y;
			} else {
				if ( x == x->parent->left ) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
			}
			
			y->right = x;
			x->parent = y;
		}

		node* insert( T* r ) {
			
			node* t = new node();
			t->data = r;
			
			if ( root == NULL ) {
				
				root = t;
				return root;
				
			} else {
				node* last = NULL;
				node* comp = root;
				while ( comp != NULL ) {
					last = comp;
					if ( r->compare( comp->data ) ) {
						std::cerr << "GO LEFT" << std::endl;
						comp = comp->left;
						if ( comp == NULL ) {
							last->left = t;
							t->parent = last;
							break;
						}
					} else {
						std::cerr << "GO RIGHT" << std::endl;
						comp = comp->right;
						if ( comp == NULL ) {
							last->right = t;
							t->parent = last;
							break;
						}
					}
				}
			}
			std::cerr << "INSERT DONE" << std::endl;
			return t;
			
		}

		void balance( node* x ) {
			
			x->data->color( RB_TREE_COLOR_RED );
			
			while ( x != root && x->parent->data->red() ) {
				node* grandma = x->grandparent();
				if ( x->parent == grandma->left ) {
					node* y = grandma->right;
					if ( y != NULL && y->data->red() ) {
						x->parent->data->color( RB_TREE_COLOR_BLACK );
						y->data->color( RB_TREE_COLOR_BLACK );
						grandma->data->color( RB_TREE_COLOR_BLACK );
						x = grandma;
					} else {
						if ( x == x->parent->right ) {
							x = x->parent;
							left_rotate( x );
						}
						grandma = x->grandparent();
						x->parent->data->color( RB_TREE_COLOR_BLACK );
						grandma->data->color( RB_TREE_COLOR_RED );
						right_rotate( grandma );
					}
				} else {
					node* y = grandma->left;
					if ( y != NULL && y->data->red() ) {
						x->parent->data->color( RB_TREE_COLOR_BLACK );
						y->data->color( RB_TREE_COLOR_BLACK );
						grandma->data->color( RB_TREE_COLOR_BLACK );
						x = grandma;
					} else {
						if ( x == x->parent->left ) {
							x = x->parent;
							right_rotate( x );
						}
						grandma = x->grandparent();
						x->parent->data->color( RB_TREE_COLOR_BLACK );
						grandma->data->color( RB_TREE_COLOR_RED );
						left_rotate( grandma );
					}
				}
			}
			root->data->color( RB_TREE_COLOR_BLACK );
		}

		rb_tree_t() : root(NULL), current(NULL) { }

		void print_item( node* n, uint32 x = 0 ) const {
			if ( n == NULL ) {
				for ( uint32 i=0;i<x;i++ ) std::cerr << "    ";
				std::cerr << "-- NIL" << std::endl;
				return;
			}
			for ( uint32 i=0;i<x;i++ ) std::cerr << "    ";
			std::cerr << "-- " << n->data->get_reference() << 
						 "(" << n->data->black() << ")" << std::endl;
			print_item( n->left, x + 1 );
			print_item( n->right, x + 1 );
		}
		void display() const {
			print_item( root );
		}

		T* add( T* r ) {
			balance( insert( r ) );
			return r;
		}
		void remove( T* ) { }

		T* start() {
			if ( root == NULL ) return NULL;
			
			for ( current = root; 
				  current->left != NULL; 
				  current = current->left );
			
			return current->data;
		}
		T* next() {
			if ( current != NULL ) {
				if ( current->right != NULL ) {
					for ( current = current->right;
						  current->left != NULL; 
						  current = current->left );
				} else {
					node* last = current;
					for ( current = current->parent;
						  current != NULL && current->right == last;
						  last = current, current = current->parent );
				}
			}
			if ( current == NULL )
				return NULL;
			else
				return current->data;
		}
	};
	
} }

#endif//__INFI_RED_BLACK_TREE_H__