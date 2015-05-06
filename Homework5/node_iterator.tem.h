/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - sets and set operations
	node_iterator.tem.h
	see node.h for all documentation
*/


#include "node.h"


/*
	constructors
*/
template <typename val_t>
node_iterator<val_t>::node_iterator ()
{
	current = 0;
}

template <typename val_t>
node_iterator<val_t>::node_iterator ( list::node<val_t>* head_ptr )
{
	current = new list::node<val_t> ( head_ptr );
}


/*
	constant member functions
*/
template <typename val_t>
val_t node_iterator<val_t>::operator * () const
{
	if ( this != 0 )
	{
		return this-> current-> data ();
	}
}


/*
	operator functions
*/
template <typename val_t>
node_iterator<val_t>& node_iterator<val_t>::operator ++ ()
{
	current = current-> link ();
	return *this;;
}

template <typename val_t>
node_iterator<val_t> node_iterator<val_t>::operator ++ ( int )
{
	list::node<val_t>* temp ( current );

	current = current-> link ();

	return temp;
}

template <typename val_t>
bool node_iterator<val_t>::operator == ( const node_iterator& n_itr ) const
{
	return this-> current == n_itr.current;
}

template <typename val_t>
bool node_iterator<val_t>::operator!= ( const node_iterator& n_itr ) const
{
	return this-> current != n_itr.current;
}
