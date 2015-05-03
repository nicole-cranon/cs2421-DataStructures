/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 4 - linked list based bag
	node.cpp
	see node.h for the documentation of the node class and the linked list
	library or toolkit
*/


#include "node.h"

namespace linkedlist
{
/*
	node constructors
*/
	node::node () : data_field ( "" ), link_field ( 0 ) {}

	node::node ( const node::val_t& data ) : data_field ( data ), \
	link_field ( 0 ) {}

	node::node ( const node::val_t& data, node* link ) : \
	data_field ( data ), link_field ( link ) {}


/*
	node constant members
*/
	node::val_t node::data () const { return data_field; }

	const node* node::link () const { return link_field; }


/*
	node modification members
*/

	node* node::link () { return link_field; }

	void node::set_data ( const node::val_t& data ) { data_field = data; }

	void node::set_link ( node* link ) { link_field = link; }



/*
	non node class functions ( the link list library or toolkit )
*/

	node::size_t length ( const node* head )
	{
		node::size_t length = 0;
		const node* cursor = head;

		for (; cursor != 0; cursor = cursor-> link () )
		{
			++length;
		}

		return length;
	}

	void head_insert ( node*& head, const node::val_t& data )
	{
/*
		creates a new node with data_field = data and link_field = head
*/
		node* new_head = new node ( data, head );

		head = new_head;
	}

	void insert ( node* previous, const node::val_t& data )
	{
		if ( previous != 0 )
		{
/*
			create a new node with data_field = data and 
			link_field = previous-> link (). then sets the previous
			node's link_field = new_node pointer
*/
			node* new_node = new node ( data, previous->link () );

			previous->set_link ( new_node );
		}
	}

	node* search ( node* head, const node::val_t& target )
	{
		if ( head != 0 )
		{
			node* cursor = head;

			for ( ; cursor != 0; cursor = cursor-> link () )
			{
				if ( cursor-> data () == target )
				{
					return cursor;
				}
			}
		}

		return 0;
	}

        const node* search ( const node* head, const node::val_t& target )
        {
                if ( head != 0 )
                {
                        const node* cursor = head;

                        for ( ; cursor != 0; cursor = cursor-> link () )
                        {
                                if ( cursor-> data () == target )
                                {
                                        return cursor;
                                }
                        }
                }

                return 0;
        }

	node* locate ( node* head, node::size_t position )
	{
		if ( position > 0 && position <= length ( head ) )
		{
			unsigned itr = 1;
			node* cursor = head;

			if ( position == 1 )
			{
				return head;
			}

			else
			{
				for ( int i = 1; i < position; ++i )
				{
					cursor = cursor-> link ();
				}

				return cursor;
			}
		}

		return 0;
	}

        const node* locate ( const node* head, node::size_t position )
        {
                if ( position > 0 && position <= length ( head ) )
                {
                        unsigned itr = 1;
                        const node* cursor = head;

                        if ( position == 1 )
                        {
                                return head;
                        }

                        else
                        {
                                for ( int i = 1; i < position; ++i )
                                {
                                        cursor = cursor-> link ();
                                }

                                return cursor;
                        }
                }

                return 0;
        }

	void head_remove ( node*& head )
	{
		if ( head != 0 )
		{
			node* frmr_head = head;
			head = head-> link ();
			delete frmr_head;
		}
	}

	void remove ( node* previous )
	{
		if ( previous != 0 )
		{
/*
			create a node to hold the node to be deleted. create
			a temporary node to hold the deleted node's link.
			delete the node, and reset previous pointer's node to
			the deleted node's link to maintain structure of the
			list
*/
			node* deleted_node = previous-> link ();
			node* new_link = deleted_node-> link ();

			delete deleted_node;

			previous-> set_link ( new_link );
		}
	}

	void clear ( node*& head )
	{
		while ( head != 0 )
		{
			head_remove ( head );
		}
	}

	void copy ( const node* source, node*& head, node*& tail )
	{
		if ( source != 0 )
		{
			head = 0;

			head_insert ( head , source-> data () );
			tail = head;

			while ( source->link () != 0 )
			{
				source = source-> link ();
				insert ( tail, source-> data () );
				tail = tail-> link ();
			}
		}
	}
}
