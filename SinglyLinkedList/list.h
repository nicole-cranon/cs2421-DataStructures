/*
	nicole cranon <nicole.cranon@ucdenver.edu
	csci 2421, fall 2013
	list.h
	the list is singly linked and consists of a sequence of nodes. the list
	supports forward iterators. contained in the list:
		-a default constructor, constructing an empty list with a null
		 head pointer
		-a copy constructor, constructing a copy of a list
		-an overloaded destructor
		-a function length, that returns the length of the list
    -a function front, that returns the data contained at the head
    -a function back, that returns the data contained at the tail
		-a function front insert, that performs an insert at the head
		 of the linked list
		-a function back insert, that performs an insert at the tail
		 of a linked list
		-a function insert, that performs an insert at a location
		 other than the head or tail
		-a function head remove, to remove the head of the linked list
		-a function remove, to remove a node of the linked list that is
		 not the head
		-a function clear, to clear all the items from the linked list
		-a function begin, that returns an iterator to the head of the
		 linked list
		-a function end, that returns an iterator to the end of the
		 linked list
		-overloaded operator =
		-overloaded operator +
		-overloaded operator <<
*/


#include "node_iterator.h"
#include <iostream>


#ifndef _LIST
#define _LIST


/*
	forward declarations
*/

template <typename val_t>
class list;

template <typename val_t>
std::ostream& operator << ( std::ostream&, const list<val_t>& );


template <typename val_t>
class list
{
public:
/*
	typedefs
*/
	typedef node_iterator<val_t> iterator;

/*
	constructors
*/

/*
	precondition:		none
	postcondition:	creates an empty list with a null node
*/
	list ();

/*
	precondition:		a single item of type val_t
	postcondition:	creates a linked list with with a single entry
*/
	list ( const val_t& );

/*
	precondition:		an existing linked list
	postcondition:	creates a copy of the existing linked list
*/
	list ( const list& );


/*
	destructor
*/

/*
	precondition:		none
	postcondition:	destroys a linked list
*/
	~list ();


/*
	constant member functions
*/

/*
  precondition:   none
  postcondition:  returns the length of the list
*/
  unsigned size () const;

/*
	precondition:		none
	postcondition:	returns an iterator at the head of the list
*/
	iterator begin () const;

/*
	precondition:		none
	postcondition:	returns an iterator at the end of the list
*/
	iterator end () const;

/*
	precondition:		none
	postcondition:	returns the data of the head pointer of the list
*/
	val_t front () const;

/*
	precondition:		none
	postcondition:	returns the data of the tail pointer of the linked list
*/
	val_t back () const;


/*
	modification member functions
*/

/*
  precondition:   a data entry of type val_t
  postcondition:  inserts a new node at the head of the linked list
*/
  void front_insert ( const val_t& );

/*
	precondition:	a data entry of type val_t
	postcondition:	inserts a new node at the tail of the linked list
*/
	void back_insert ( const val_t& );

/*
  precondition:   an iterator to a position, and an entry value
  postcondition:  inserts an entry at the position of the iterator,
									such that:
									( ... , new_entry, iterator, ... )
									*this is not an efficient insertion as it requires the
									walking of the list to the position to perform the
									insert
*/
  void insert ( const iterator&, const val_t& );

/*
	precondition:   none
	postcondition:  removes the current head node
*/
  void head_remove ();

/*
	precondition:   an iterator at the position of the entry to be removed
	postcondition:  removes the list entry. *this is not an efficient
									removal as it requires the walking of the list to the
									removal position
*/
  void remove ( const iterator& );

/*
  precondition:   none
  postcondition:  removes all the nodes of the linked list
*/
  void clear ();

/*
  precondition:   none
  postcondition:  returns an iterator at the head of the list
*/
  iterator begin ();

/*
  precondition:   none
  postcondition:  returns an iterator at the end of the list
*/
  iterator end ();


/*
	operator functions
*/

/*
	precondition:		an existing list
	postcondition:	assigns the values of the existing list to this list
*/
	list& operator = ( const list& );

/*
	precondition:		an existing list
	postcondition:	appends the existing list to this list
*/
	list operator + ( const list& ) const;


/*
	friends
*/

/*
	precondition:		an existing list
	postcondition:	prints the contents of the list to the screen
*/
	friend std::ostream& operator << <val_t> ( std::ostream&, const list& );

private:
	node<val_t>* head_ptr, *tail_ptr;
	unsigned length;
};


#include "list.tem.h"
#endif
