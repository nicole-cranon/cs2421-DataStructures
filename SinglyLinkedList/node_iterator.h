/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - sets and set operations
	node_iterator.h
	this file contains an iterator for the nodes that compose a linked
	list. if used with an isolated node there is no guarantee of the
	behavior of the node iterator. the node iterator is derived from the
	forward iterator of the standard library contained in the
	node_iterator class:
		-default constructor
		-a constructor that takes a node*
		-overloaded operator *, allowing access to the data at the
		 current iterator position
		-overloaded operator ++ allowing forward advancement in the
		 linked list (pre, ie ++itr)
		-overloaded operator ++ allowing forward advancement in the
		 linked list (post, ie itr++)
		-overloaded operator == allowing comparison of two iterators
		-overloaded operator != allowing comparison of two iterators
*/


#include <iterator>
#include "node.h"


#ifndef _NODE_ITR
#define _NODE_ITR


template <typename val_t>
class node_iterator : public std::iterator <std::forward_iterator_tag,\
const val_t>
{
public:
/*
	constructors
*/

/*
	precondition:		none
	postcondition:	creates a node iterater with a null pointer
*/
	node_iterator ();

/*
	precondition:		a pointer to the head node of a linked list
	postcondition:	creates an iterator pointing to the head of the
									linked list
*/
	node_iterator ( node<val_t>* );

/*
	precondition:		an existing node
	postcondition:	assigns the current node of the passed iterator to
									this iterator
*/
	node_iterator ( const node_iterator<val_t>& );

/*
	destructor
*/

/*
	precondition:		none
	postcondition:	removes the access of the iterator to the current node
									it does not delete the node as it may still be in use
*/
	~node_iterator ();


/*
  operator functions
*/

/*
	precondition:		none
	postcondition:	returns the data held at the iterator's current
									position
*/
	val_t operator * () const;

/*
	precondition: 	none
	postcondition:	uses pre iteration to advance forward through the
									linked list
*/
	node_iterator& operator ++ ();

/*
	precondition:		none
	postcondition:	uses post iteration to advance forward through the
									linked list
*/
	node_iterator operator ++ ( int );

/*
	precondition:		an existing node
	postcondition:	assigns the values of the right operand to the left
*/
	node_iterator& operator = ( const node_iterator<val_t>& );

/*
	precondition:		a node_iterator
	postcondition:	returns true if the two iterators are equal, false
									otherwise
*/
	bool operator == ( const node_iterator& ) const;

/*
  precondition:   a node_iterator
  postcondition:  returns false if the two iterators are equal, true
                  otherwise
*/
  bool operator != ( const node_iterator& ) const;


private:
	node<val_t>* current;
};


#include "node_iterator.tem.h"


#endif
