/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - sets and set operations
	set.h
	the set provides a non-linear storage container, it does not support
	direct access. the set is dynamic and only uses the space required for
	its contents. the set supports forward iterators. contained in the
	set class:
		-a default constructor
		-a copy constructor
		-a constructor that takes one entry
		-overloaded destructor
		-a function size that counts the contents of the set
		-a function to check if the set is empty
		-a function begin that returns an iterator to the beginning of
		 of the set
		-a function end that returns an iterator to the end of the set
		-a function to search the set, it returns an iterator to the
		 location of the target value if it exists in the set, else it
		 returns an iterator to the end of the set
		-a function to insert an item into the set, duplicates are NOT
		 allowed and will be rejected
		-a function to remove a value from the set
		-a function to clear the set of all contents
		-overloaded operator =
		-overloaded operator +, representing the union of two sets
		-overloaded operator &, representing the intersection of
		 two sets
		-overloaded operator -, representing the difference of the
		 two sets
		-overloaded operator ==
		-overloaded operator !=
		-overloaded stream insertion operator <<
*/


#include "bag.h"

#ifndef SET
#define SET


/*
	foreward declarations
*/
template <typename val_t>
class set;

template <typename val_t>
std::ostream& operator << ( std::ostream&, const set<val_t>& );



template <typename val_t>
class set
{
public:
/*
	typedefs
*/
	typedef unsigned size_t;
	typedef typename bag<val_t>::iterator iterator;

/*
	constructors
*/

/*
	precondition:		none
	postcondition:	creates an empty set of size 0
*/
	set ();

/*
	precondition:		an existing set
	postcondition:	creates a copy of the set
*/
	set ( const set& );

/*
	precondition:		an existing bag
	postcondition:	creates a set from the contents of the provided bag
			sans duplicates
*/
	set ( const bag<val_t>& );

/*
	precondition:		a single entry
	postcondition:	creates a set with a single entry
*/
	set ( const val_t& );


/*
	destructor
*/

/*
	precondition:		none
	postcondition:	called when a set is to be destroyed
*/
	~set ();


/*
	constant member functions
*/

/*
	precondition:		none
	postcondition:	returns the size of the set
*/
	size_t size () const;

/*
	precondition:		none
	postcondition:	returns true if the set is empty, false if not
*/
	bool empty () const;

/*
	precondition:		none
	postcondition:	returns an iterator to the beginning of the set
*/
	const iterator begin () const;

/*
	precondition:		none
	postcondition:	returns an iterator to the end of the set
*/
	const iterator end () const;

/*
	precondition:		a target value to search the set for
	postcondition:	returns true if it was found in the set
*/
	iterator search ( const val_t& entry ) const;


/*
	modification member functions
*/

/*
	precondition:		an entry value
	postcondition:	inserts the value if it is not contained in the set.
									the insert will operate in O(n) time
*/
	void insert ( const val_t& );

/*
	precondition:		an value to remove from the set
	postcondition:	removes the value if it is within the set and returns
									true, if the value was not found and thus not removed
									it returns false. the remove will operate in O(n) time
*/
	bool remove ( const val_t& );

/*
	precondition:	none
	postcondition:	clears all set contents
*/
	void clear ( );

/*
  precondition:   none
  postcondition:  returns an iterator to the beginning of the set
*/
  iterator begin ();

/*
  precondition:   none
  postcondition:  returns an iterator to the end of the set
*/
  iterator end ();


/*
	operator functions
*/

/*
	precondition:		an existing set
	postcondition:	assigns the values of the right operand to the left
									operand
*/
	set& operator = ( const set& );

/*
	precondition:		an existing set
	postcondition:	produces a third set which is the union of the two sets
*/
	set operator + ( const set& ) const;

/*
	precondition:		an existing set
	postcondition:	produces a third set which is the intersection of the
									two sets
*/
	set operator & ( const set& ) const;

/*
	precondition:		an existing set
	postcondition:	produces a third set which is the left operand less the
									contents of the right operand
*/
	set operator - ( const set& ) const;

/*
	precondition:		an existing set
	postcondition:	returns true if the two sets are equal (they contain
									the same contents) false if they are un equal
*/
	bool operator == ( const set& ) const;

/*
	precondition:		an existing set
	postcondition:	returns true if the two sets are unequal, false if
									the two are equal
*/
	bool operator != ( const set& ) const;


/*
	friends
*/

/*
	precondition:		an existing set
	postcondition:	uses the stream insertion operator to print the
									contents of the set
*/
	friend std::ostream& operator << <val_t> ( std::ostream&, const set& );


private:
	bag <val_t> data;
	size_t length;
};


#include "set.tem.h"


#endif
