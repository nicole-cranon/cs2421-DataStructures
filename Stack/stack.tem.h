/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	stach.tem.h
	see stack.h for documentation for the stack class
*/

#include "list.h"


/*
	constructors
*/
template <typename val_t>
stack<val_t>::stack () : data () {}

template <typename val_t>
stack<val_t>::stack ( const stack& s )
{
	typename list<val_t>::iterator itr;

	for ( itr = s.data.begin (); itr != s.data.end (); ++itr )
	{
		data.back_insert ( *itr );
	}
}

template <typename val_t>
stack<val_t>::~stack ()
{
	data.clear ();
}


/*
	constant members
*/
template <typename val_t>
bool stack<val_t>::empty () const
{
	return this->size () == 0;
}
template <typename val_t>
val_t stack<val_t>::front () const
{
	return this-> data.front ();
}

template <typename val_t>
unsigned stack<val_t>::size () const
{
	return this-> data.size ();
}


/*
	modification members
*/
template <typename val_t>
void stack<val_t>::pop ()
{
	this-> data.head_remove ();
}

template <typename val_t>
void stack<val_t>::push ( const val_t& entry )
{
	this-> data.front_insert ( entry );
}
