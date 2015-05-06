/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - set and set operations
	node.h
	the node provides the basis of a linked list. it will contain both
	data and a link to the next node. also provided is a toolkit which
	can be used to manipulate the linked list. contained in this file:
		-node default constructor, creating an empty node with no link
		-node constructor taking only data, having no link
		-node constructor taking both data and a link to another node
		-node constructor to copy a node pointer
		-set and get functions for the data portion of the node
		-set and get functions for the link field of the node

		non class functions (the link list library or toolkit) :
		-a function to get the list's length that operates in O(n) time
		-a function to perform a head insert
		-a function to insert at a position other than the head
		-a function to serch the list
		-a function to locate a node by its position in the list,
		 the head is at position 1
		-a function to copy the linked list
		-a function to remove the head node of a list
		-a function to remove a node that is not the head
		-a function to clear the linked list
*/


#ifndef _NODE
#define _NODE


template <typename val_t>
class node
{
public:
/*
	typedefs
*/
	typedef unsigned size_t;

/*
	constructors
*/

/*
	precondition:	none
	postcondition:	creates an empty node with no link
*/
	node ();

/*
	precondition:	data of type val_t
	postcondition:	creates a node with the data provided and no
				link
*/
	node ( const val_t& );

/*
	precondition:	data of type val_t, and a link to another node
	postcondition:	creates a node with the data and node link
			provided
*/
	node ( const val_t&, node* );

/*
	precondition:	an existing node
	postcondition:	creates a copy of the existing node
*/
	node ( const node* );

/*
	constant members
*/

/*
	precondition:	none
	postcondition:	returns the data field
*/
	val_t data () const;

/*
	precondition:	none
	postcondition:	returns a pointer to the next node or null
*/
	const node* link () const;

/*
	modification members
*/

/*
	precondition:	none
	postcondition:	returns a pointer to the next node or null
*/
	node* link ();

/*
	precondition:	data of type val_t
	postcondition:	sets the data field of the node
*/
	void set_data ( const val_t& );

/*
	precondition:	a node pointer
	postcondition:	sets the link field of the node
*/
	void set_link ( node* );

public:
	val_t data_field;
	node* link_field;
};


#include "node.tem.h"
#endif
