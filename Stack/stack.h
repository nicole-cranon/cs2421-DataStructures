/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	stack.h
	the stack is a filo data structure. contained in the stack class:
		-default constructor
		-copy constructor
		-overloaded destructor
		-empty, returns true if the stack is empty, false otherwise
		-front, which returns the data at the top of the stack without
		 removing it from the stack
		-size, which returns the number of contents inside the list
		-push, inserts an entry onto the top of the stack
		-pop, removes an entry from the top of the stack
*/


#include "list.h"


#ifndef _STACK
#define _STACK


template <typename val_t>
class stack
{
public:
/*
	constructors
*/

/*
	precondition:	none
	postcondition:	creates an empty stack
*/
	stack ();

/*
	precondition:	an existing stack
	postcondition:	creates a copy stack
*/
	stack ( const stack& );

/*
	destructor
*/
	~stack ();

/*
	constant members
*/

/*
	precondition:	none
	postcondition:	returns true if the stack is empty, false otherwise
*/
	bool empty () const;

/*
	precondition:	none
	postcondition:	returns the item at the top of the list without
			removing it from the stack
*/
	val_t front () const;

/*
	precondition:	none
	postcondition:	returns the number of items on the stack
*/
	unsigned size () const;

/*
	modification members
*/

/*
	precondition:	none
	postcondition:	removes the top item from the stack
*/
	void pop ();

/*
	precondition:	an entry item
	postcondition:	inserts the entry onto the stack
*/
	void push ( const val_t& );

private:
	list<val_t> data;
};


#include "stack.tem.h"
#endif
