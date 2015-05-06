/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 4 - linked list based bag
	bag.h
	the bag provides a non-linear storage container. it does support
	direct access. the bag is dynamic and only uses the space required for
	its contents. contained in the bag class:
		-a default constructor
		-a copy constructor
		-overloaded destructor
		-a function to count the contents of the bag
		-a function to erase the first object matching the target value
		-a function to erase all objects matching the target value
		-a function to randomly grab an item from within the bag
		-a function to insert an item into the bag
		-overloaded operator +, allowing bags to be combined
		-overloaded operator +=
		-overloaded operator =
*/


#include "node.h"
#include <iostream>

#ifndef _BAG
#define _BAG


class bag
{
public:
/*
	typedefs
*/
	typedef std::string val_t;

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
									the driver file
	postcondition:	returns a randomly chosen item from the bag
*/
	val_t grab () const;


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
	precondition: 	an entry of type bag::val_t
	postcondition:	inserts the entry into the bag
*/
	void insert ( const val_t& );


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
	precondition:		an existing bag item
	postcondition: 	outputs the bag's contents, space delimited, to the
									standard output screen
*/
	friend std::ostream& operator << ( std::ostream&, const bag& );

private:
	list::node* head_ptr;
	unsigned size;
};


#endif
