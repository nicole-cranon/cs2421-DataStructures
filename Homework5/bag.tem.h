/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - sets and set operations
	bag.tem
	see bag.h for all bag documentation
*/


#include <cstdlib>
#include <iostream>

/*
	constructors
*/
template <typename val_t>
bag<val_t>::bag () : head_ptr ( 0 ), size ( 0 ) {}

template <typename val_t>
bag<val_t>::bag ( const bag<val_t>& b )
{
	list::node<val_t>* tail_ptr;
	list::copy ( b.head_ptr, head_ptr, tail_ptr );

	size = b.size;
}


/*
	destructor
*/
template <typename val_t>
bag<val_t>::~bag ()
{
	list::clear ( this-> head_ptr );

	this-> size = 0;
}


/*
	constant member functions
*/
template <typename val_t>
unsigned bag<val_t>::count ( const val_t& target ) const
{
	unsigned found = 0;
	const list::node<val_t>* cursor = this-> head_ptr;

	while ( cursor != 0 )
	{
		cursor = list::search ( cursor, target );
		if ( cursor != 0 )
		{
			++found;
      cursor = cursor-> link ();
		}
	}

	return found;
}

template <typename val_t>
val_t bag<val_t>::grab () const
{
	unsigned location;
	list::node<val_t>* grabbed_item;

/*
	randomly select a location from within the bag
*/
	location = rand () % this-> size + 1;

	grabbed_item = list::locate ( this-> head_ptr, location );

/*
	return the item that resides at the random location
*/

	return grabbed_item-> data ();
}

template <typename val_t>
const typename bag<val_t>::iterator bag<val_t>::begin () const
{
	return iterator ( this-> head_ptr );
}

template <typename val_t>
const typename bag<val_t>::iterator bag<val_t>::end () const
{
	return iterator ();
}


/*
	modification member functions
*/
template <typename val_t>
bool bag<val_t>::erase_one ( const val_t& target )
{
	list::node<val_t>* found, * precursor;

	found = list::search ( this-> head_ptr, target );

	if ( found != 0 )
	{

		if ( found == this-> head_ptr )
		{
			list::head_remove ( this-> head_ptr );
		}

		else
		{
			precursor = this-> head_ptr;

			while ( precursor-> link () != found )
			{
				precursor = precursor-> link ();
			}

			list::remove ( precursor );
		}

		return true;
	}

	return false;
}

template <typename val_t>
unsigned bag<val_t>::erase ( const val_t& target )
{
	unsigned erased = 0;

	while ( this-> erase_one ( target ) != false )
	{
		++erased;
	}

	return erased;
}

template <typename val_t>
void bag<val_t>::insert ( const val_t& data )
{
 	list::head_insert ( this-> head_ptr, data );
	++this-> size;
}

template <typename val_t>
void bag<val_t>::clear ()
{
	list::clear ( this-> head_ptr );
}

template <typename val_t>
typename bag<val_t>::iterator bag<val_t>::begin ()
{
  return iterator ( this-> head_ptr );
}

template <typename val_t>
typename bag<val_t>::iterator bag<val_t>::end ()
{
  return iterator ();
}


/*
	operator functions
*/
template <typename val_t>
bag<val_t>& bag<val_t>::operator = ( const bag<val_t>& b )
{
	list::node<val_t>* tail_ptr;
	list::copy ( b.head_ptr, this-> head_ptr, tail_ptr );

	this-> size = b.size;

	return *this;
}

template <typename val_t>
bag<val_t> bag<val_t>::operator + ( const bag<val_t>& b ) const
{
	bag<val_t> new_bag;
	list::node<val_t> *tail_ptr1, *tail_ptr2, *temp;

	list::copy ( this-> head_ptr, new_bag.head_ptr, tail_ptr1 );
	list::copy ( b.head_ptr, temp, tail_ptr2 );

	tail_ptr1-> set_link ( temp );

	new_bag.size = this-> size + b.size;

	return new_bag;
}

template <typename val_t>
bag<val_t>& bag<val_t>::operator += ( const bag<val_t>& b )
{
	*this = *this + b;
	return *this;
}

template <typename val_t>
std::ostream& operator << ( std::ostream& out, const bag<val_t>& b )
{
	typename bag<val_t>::iterator itr;

	if ( b.head_ptr != 0 )
	{
		for ( itr = b.begin (); itr != b.end (); ++itr )
		{
			out << *itr << ' ';
		}
	}

/*	const list::node<val_t>* cursor = b.head_ptr;

	while ( cursor != 0 )
	{
		out << cursor-> data_field << ' ';
		cursor = cursor-> link ();
	}
*/

	return out;
}
