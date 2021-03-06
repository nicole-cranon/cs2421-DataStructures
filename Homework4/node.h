/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 4 - linked list based bag
	node.h
	the node provides the basis of a linked list. it will contain both
	data and a link to the next node. also provided is a toolkit which
	can be used to manipulate the linked list. contained in this file:
		-node default constructor, creating an empty node with no link
		-node constructor taking only data, having no link
		-node constructor taking both data and a link to another node
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


#include <string>

#ifndef _list
#define _list

namespace linkedlist
{
	class node
	{
	public:
/*
		typedefs
*/
		typedef unsigned size_t;
		typedef std::string val_t;


/*
		constructors
*/

/*
		precondition:		none
		postcondition:	creates an empty node with no link
*/
		node ();

/*
		precondition:		data of type val_t
		postcondition:	creates a node with the data provided and no
										link
*/
		node ( const val_t& );

/*
		precondition:		data of type val_t, and a link to another node
		postcondition:	creates a node with the data and node link
										provided
*/
		node ( const val_t&, node* );


/*
		constant members
*/

/*
		precondition:		none
		postcondition:	returns the data field
*/
		val_t data () const;

/*
		precondition:		none
		postcondition:	returns a pointer to the next node or null
*/
		const node* link () const;


/*
		modification members
*/

/*
		precondition:		none
		postcondition:	returns a pointer to the next node or null
*/
		node* link ();

/*
		precondition:		data of type val_t
		postcondition:	sets the data field of the node
*/
		void set_data ( const val_t& );

/*
		precondition:		a node pointer
		postcondition:	sets the link field of the node
*/
		void set_link ( node* );

	public:
		val_t data_field;
		node* link_field;
	};



/*
	non node class functions ( the link list library or toolkit )
*/

/*
	precondition:		a pointer to the head node of a linked list
	postcondition:	returns the length of the list
*/
	node::size_t length ( const node* );

/*
	precondition:		a pointer to the head node of a linked list, and a data
									entry of type node::val_t
	postcondition:	inserts a new node at the head of the linked list, and
									changes the head pointer to the new node
*/
	void head_insert ( node*&, const node::val_t& );

/*
	precondition:		a pointer to the node previous of the insert point, and
									a data value of type node::val_t
	postcondition:	inserts a new node at the point indicated, note: if
									the node pointer to the previous node is null no
									insert is made
*/
	void insert ( node*, const node::val_t& );

/*
	precondition:		a pointer to the head of a linked list, and target data
									of type node::val_t
	postcondition:	returns a pointer to the node containing the target
									data if it is within the list, if it does not it
									returns null
*/
	node* search ( node*, const node::val_t& );

/*
	precondition:		a pointer to the head of a linked list, and target data
									of type node::val_t
	postcondition:	returns a pointer to the node containing the target
									data if it is within the list, if it does not it
									returns null
*/
	const node* search ( const node*, const node::val_t& );

/*
	precondition:		a pointer to the head of a linked list, and a position
									within the linked list, note: the head of the linked
									list is at position 1
	postcondition:	returns a pointer to the node at the position
									indicated if it is within the list, else it
									returns null
*/
	node* locate ( node*, node::size_t );

/*
  precondition:   a pointer to the head of a linked list, and a position
                  within the linked list, note: the head of the linked
                  list is at position 1
  postcondition:  returns a pointer to the node at the position
                  indicated if it is within the list, else it
                  returns null
*/
        const node* locate ( const node*, node::size_t );

/*
	precondition:		a pointer to the head of a linked list
	postcondition:	removes the current head node
*/
	void head_remove ( node*& );

/*
	precondition:		a pointer to the node previous the one to be removed
	postcondition:	removes the node following the previous node
*/
	void remove ( node* );

/*
	precondition:		a pointer to the head of a linked list
	postcondition:	removes all the nodes of the linked list
*/
	void clear ( node*& );

/*
	precondition:		a pointer to the head of a source link list, a pointer
									to the head and tail of a linked list to hold the copy
	postcondition:	copies the source link list
*/
	void copy ( const node*, node*&, node*& );
}

namespace list = linkedlist;


#endif
