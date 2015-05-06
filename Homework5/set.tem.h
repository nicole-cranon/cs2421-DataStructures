/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - sets and set operations
	set.cpp
	see set.h for all documentation
*/


#include "bag.h"


/*
	constructors
*/
template <typename val_t>
set<val_t>::set () : data (), length ( 0 ) {}

template <typename val_t>
set<val_t>::set ( const set<val_t>& s )
{
	data = s.data;
	length = s.length;
}

template <typename val_t>
set<val_t>::set ( const val_t& entry )
{
	insert ( entry );
}


/*
	destructor
*/
template <typename val_t>
set<val_t>::~set ()
{
	clear ();
	length = 0;
}


/*
	constant member functions
*/
template <typename val_t>
typename set<val_t>::size_t set<val_t>::size () const
{
	return this-> length;
}

template <typename val_t>
bool set<val_t>::empty () const
{
	return this-> length == 0;
}

template <typename val_t>
const typename set<val_t>::iterator set<val_t>::begin () const
{
	return this-> data.begin ();
}

template <typename val_t>
const typename set<val_t>::iterator set<val_t>::end () const
{
	return this-> data.end ();
}

template <typename val_t>
typename set<val_t>::iterator set<val_t>::search ( const val_t& entry ) const
{
	set<val_t>::iterator itr;

	for ( itr = this-> begin (); itr != this-> end (); ++itr )
	{
		if ( *itr == entry )
			return itr;
	}

	return itr;
}


/*
	modification member functions
*/
template <typename val_t>
void set<val_t>::insert ( const val_t& entry )
{
	set<val_t>::iterator itr;

/*
	checks if the entry exists in the set
*/
	itr = this-> search ( entry );

/*
	if the entry does not exist in the set, insert
*/
	if ( itr == this-> end () )
	{
		this-> data.insert ( entry );
		++this-> length;
	}
}

template <typename val_t>
bool set<val_t>::remove ( const val_t& target )
{

	if ( this-> data.erase_one ( target ) )
	{
		--this->length;
		return true;
	}

	return false;
}

template <typename val_t>
void set<val_t>::clear ()
{
	this-> data.clear ();
	this-> length = 0;
}

template <typename val_t>
typename set<val_t>::iterator set<val_t>::begin ()
{
  return this-> data.begin ();
}

template <typename val_t>
typename set<val_t>::iterator set<val_t>::end ()
{
  return this-> data.end ();
}


/*
	operator functions
*/
template <typename val_t>
set<val_t>& set<val_t>::operator = ( const set<val_t>& s )
{
	this-> data = s.data;
	this-> length = s.length;

	return *this;
}

template <typename val_t>
set<val_t> set<val_t>::operator + ( const set<val_t>& s ) const
{
	set<val_t> union_set;
	set<val_t>::iterator itr;

/*
	the union_set contains objects in either this set or the s set
*/

/*
	put the contents of this set into our temporary set
*/
	for ( itr = this-> begin (); itr != this-> end (); ++itr )
	{
		union_set.insert ( *itr );
	}

/*
	put the contents of the s set into the temporary set, the insert
	will throw out duplicates
*/
	for ( itr = s.begin (); itr != this-> end (); ++itr)
	{
		union_set.insert ( *itr );
	}

	return union_set;
}

template <typename val_t>
set<val_t> set<val_t>::operator & ( const set<val_t>& s ) const
{
	set<val_t> intersect_set;
	set<val_t>::iterator this_itr, s_itr;

/*
	inserts a data entry to the intersect set if and only if it is in
	this set and the s set
*/
	for ( this_itr = this-> begin (); this_itr != this-> end ();\
	++this_itr )
	{
		for ( s_itr = s.begin (); s_itr != s.end (); ++s_itr )
		{
			if ( *this_itr == *s_itr )
				intersect_set.insert ( *s_itr );
		}
	}

	return intersect_set;
}

template <typename val_t>
set<val_t> set<val_t>::operator - ( const set<val_t>& s ) const
{
	set<val_t> difference_set;
	set<val_t>::iterator itr;

/*
	if a data entry of this set belongs to this set and only this set
	insert into the difference set
*/

	for ( itr = this-> begin (); itr != this-> end (); ++itr )
	{
		if ( s.search ( *itr ) == s.end () )
			difference_set.insert ( *itr );
	}

	return difference_set;
}

template <typename val_t>
bool set<val_t>::operator == ( const set<val_t>& s ) const
{
	set<val_t>::iterator itr1, itr2;

	if ( this->length == s.length )
	{
		for ( itr1 = this-> begin (); itr1 != this-> end (); ++itr1 )
		{
	                itr2 = s.search ( *itr1 );

			if ( itr2 == s.end () )
				return false;
		}

		return true;
	}

	return false;
}

template <typename val_t>
bool set<val_t>::operator != ( const set<val_t>& s ) const
{
	return ! ( *this == s );
}


/*
	friend functions
*/
template <typename val_t>
std::ostream& operator << ( std::ostream& out, const set<val_t>& s )
{
	typename set<val_t>::iterator itr;
	itr = s.begin ();

	out << "{ ";

	for ( int i = 0; i < s.length; ++i )
	{
		out << *itr;

		if ( ( i < s.length - 1 ) )
			out << ", ";

		++itr;
	}

	out << " }";

	return out;
}
