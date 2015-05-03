/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 4 - linked list based bag
	bag.cpp
	see bag.h for all bag documentation
*/


#include "bag.h"
#include <cstdlib>

/*
	constructors
*/

bag::bag () : head_ptr ( 0 ), size ( 0 ) {}

bag::bag ( const bag& b )
{
	list::node* tail_ptr;
	list::copy ( b.head_ptr, head_ptr, tail_ptr );

	size = b.size;
}


/*
	destructor
*/

bag::~bag ()
{
	list::clear ( this-> head_ptr );

	this-> size = 0;
}


/*
	constant member functions
*/

unsigned bag::count ( const bag::val_t& target ) const 
{
	unsigned found = 0;
	const list::node* cursor = this-> head_ptr;

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

bag::val_t bag::grab () const
{
	unsigned location;
	list::node* grabbed_item;

/*
	randomly select a location from within the bag
*/
	location = rand () % this->size + 1;

	grabbed_item = list::locate ( this-> head_ptr, location );

/*
	return the item that resides at the random location
*/

	return grabbed_item-> data ();
}


/*
	modification member functions
*/

bool bag::erase_one ( const bag::val_t& target )
{
	list::node* found, * precursor;

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

unsigned bag::erase ( const bag::val_t& target )
{
	unsigned erased = 0;

	while ( this-> erase_one ( target ) != false )
	{
		++erased;
	}

	return erased;
}

void bag::insert ( const bag::val_t& data )
{
 	list::head_insert ( this-> head_ptr, data );
	++this-> size;
}


/*
	operator functions
*/

bag& bag::operator = ( const bag& b )
{
	list::node* tail_ptr;
	list::copy ( b.head_ptr, this-> head_ptr, tail_ptr );

	this-> size = b.size;

	return *this;
}

bag bag::operator + ( const bag& b ) const
{
	bag new_bag;
	list::node *tail_ptr1, *tail_ptr2, *temp;

	list::copy ( this-> head_ptr, new_bag.head_ptr, tail_ptr1 );
	list::copy ( b.head_ptr, temp, tail_ptr2 );

	tail_ptr1-> set_link ( temp );

	new_bag.size = this-> size + b.size;

	return new_bag;
}

bag& bag::operator += ( const bag& b )
{
	*this = *this + b;
	return *this;
}


/*
	friends of bag class
*/

std::ostream& operator << ( std::ostream& out, const bag& b )
{
	const list::node* cursor = b.head_ptr;

	while ( cursor != 0 )
	{
		out << cursor-> data_field << ' ';
		cursor = cursor-> link ();
	}

	return out;
}
