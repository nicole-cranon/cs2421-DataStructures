/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - sets and set operations
	bag.h
	the bag provides a non-linear storage container. it does support
	direct access. the bag is dynamic and only uses the space required for
	its contents. contained in the bag class:
		-a default constructor
		-a copy constructor
		-overloaded destructor
		-a function begin () that returns an iterator to the beginning
		 of the bag's contents
		-a funciton end () that returns an iterator to the end of the
		 bag's contents
		-a function to count a target value inside the bag
		-a function to erase the first object matching the target value
		-a function to erase all objects matching the target value
		-a function to randomly grab an item from within the bag
		-a function to insert an item into the bag
		-a function clear to remove all the contents of the bag
		-overloaded operator +, allowing bags to be combined
		-overloaded operator +=
		-overloaded operator =
*/


#include "node_iterator.h"
#include <iostream>

#ifndef _BAG
#define _BAG


/*
	foreward declarations
*/
template <typename val_t>
class bag;

template <typename val_t>
std::ostream& operator << ( std::ostream&, const bag<val_t>& );



template <typename val_t>
class bag
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
	postcondition:	creates an empty bag
*/
	bag ();

/*
	precondition:		an existing bag
	postcondition:	creates a bag with the same contents as the
									existing bag
*/
	bag ( const bag& );


/*
	destructor
*/

/*
	precondition:		none
	postcondition:	properly deletes bag contents
*/
	~bag ();


/*
	constant member functions
*/

/*
	precondition: 	a target value to count
	postcondition:	returns the number of items matching the target value
									in the bag
*/
	unsigned count ( const val_t& ) const;

/*
	precondition:		srand must be used to seed the random generator inside
									the driver file if this function will be used
	postcondition:	returns a randomly chosen item from the bag
*/
	val_t grab () const;

/*
	precondition:		none
	postcondition:	returns an iterator to the beginning of the bag's
									contents
*/
	const iterator begin () const;

/*
	precondition:		none
	postcondition:	returns an iterator to the end of the bag's content's
*/
	const iterator end () const;


/*
	modification member functions
*/

/*
	precondition:		a target object
	postcondition:	if found, removes the first object match the target
									value, returns true if an object was erased
*/
	bool erase_one ( const val_t& );

/*
	precondition:		a target value
	postcondition:	if found, removes all objects matching the target
									value, returns the number of items removed
*/
	unsigned erase ( const val_t& );

/*
	precondition: 	an entry of type val_t
	postcondition:	inserts the entry into the bag
*/
	void insert ( const val_t& );

/*
	precondition:		none
	postcondition:	clears the bag of all contents
*/
	void clear ();

/*
  precondition:   none
  postcondition:  returns an iterator to the beginning of the bag's
                  contents
*/
        iterator begin ();

/*
  precondition:   none
  postcondition:  returns an iterator to the end of the bag's content's
*/
        iterator end ();



/*
	operator functions
*/

/*
  precondition:   an existing bag
  postcondition:  assigns the contents of the passed bag to this bag
*/
        bag& operator = ( const bag& );

/*
	precondition:		an existing bag
	postcondition:	adds the contents of the passed bag to this bag
									producing a third bag
*/
	bag operator + ( const bag& ) const;

/*
	precondition:		an existing bag
	postcondition:	adds the contents of the passed bag to this bag and
									assigns that value to this bag
*/
	bag& operator += ( const bag& );


/*
	friend functions
*/

/*
	precondition:		an existing bag
	postcondition:	prints the bag contents to the standard output display
									screen
*/
	friend std::ostream& operator <<  <val_t>( std::ostream&, const bag& );

private:
	list::node<val_t>* head_ptr;
	unsigned size;
};

#include "bag.tem.h"
#endif
