/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 4 - linked list based bag
	node.tem.h
	see node.tem.h for the documentation of the node class and the linked
	list library or toolkit
*/


namespace linkedlist
{
/*
	node constructors
*/
	template <typename val_t>
	node<val_t>::node () : data_field ( "" ), link_field ( 0 ) {}

	template <typename val_t>
	node<val_t>::node ( const val_t& data ) :\
	data_field ( data ), link_field ( 0 ) {}

	template <typename val_t>
	node<val_t>::node ( const val_t& data, node<val_t>* link )\
	: data_field ( data ), link_field ( link ) {}


	template <typename val_t>
	node<val_t>::node ( node<val_t>* n )
	{
		if ( n != 0 )
		{
			data_field = n-> data_field;
			link_field = n-> link_field;
		}

		else
		{
			*this = 0;
		}
	}


/*
	node constant members
*/
	template <typename val_t>
	val_t node<val_t>::data () const { return data_field; }

	template <typename val_t>
	const node<val_t>* node<val_t>::link () const { return link_field; }


/*
	node modification members
*/
	template <typename val_t>
	node<val_t>* node<val_t>::link () { return link_field; }

	template <typename val_t>
	void node<val_t>::set_data ( const val_t& data )\
	{ data_field = data; }

	template <typename val_t>
	void node<val_t>::set_link ( node<val_t>* link ) { link_field = link; }


/*
	non node class functions ( the linked list library or toolkit )
*/

	template <typename val_t>
	typename node<val_t>::size_t length ( const node<val_t>* head )
	{
		typename node<val_t>::size_t length = 0;
		const node<val_t>* cursor = head;

		for (; cursor != 0; cursor = cursor-> link () )
		{
			++length;
		}

		return length;
	}

	template <typename val_t>
	void head_insert ( node<val_t>*& head, const val_t& data )
	{
/*
		creates a new node with data_field = data and link_field = head
*/
		node<val_t>* new_head = new node<val_t> ( data, head );

		head = new_head;
	}

	template <typename val_t>
	void insert ( node<val_t>* previous, const val_t& data )
	{
		if ( previous != 0 )
		{
/*
			create a new node with data_field = data and
			link_field = previous-> link (). then sets the previous
			node's link_field = new_node pointer
*/
			node<val_t>* new_node = new node<val_t>\
			( data, previous->link () );

			previous->set_link ( new_node );
		}
	}

	template <typename val_t>
	node<val_t>* search ( node<val_t>* head, const val_t& target )
	{
		if ( head != 0 )
		{
			node<val_t>* cursor = head;

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

	template <typename val_t>
  const node<val_t>* search ( const node<val_t>* head, const val_t& \
	target )
  {
    if ( head != 0 )
    {
      const node<val_t>* cursor = head;

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

	template <typename val_t>
	node<val_t>* locate ( node<val_t>* head, typename node<val_t>::size_t\
	position )
	{
		if ( position > 0 && position <= length ( head ) )
		{
			unsigned itr = 1;
			node<val_t>* cursor = head;

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

	template <typename val_t>
  const node<val_t>* locate ( const node<val_t>* head, typename \
	node<val_t>::size_t position )
  {
    if ( position > 0 && position <= length ( head ) )
    {
      unsigned itr = 1;
      const node<val_t>* cursor = head;

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

	template <typename val_t>
	void head_remove ( node<val_t>*& head )
	{
		if ( head != 0 )
		{
			node<val_t>* frmr_head = head;
			head = head-> link ();
			delete frmr_head;
		}
	}

	template <typename val_t>
	void remove ( node<val_t>* previous )
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
			node<val_t>* deleted_node = previous-> link ();
			node<val_t>* new_link = deleted_node-> link ();

			delete deleted_node;

			previous-> set_link ( new_link );
		}
	}

	template <typename val_t>
	void clear ( node<val_t>*& head )
	{
		while ( head != 0 )
		{
			head_remove ( head );
		}
	}

	template <typename val_t>
	void copy ( const node<val_t>* source, node<val_t>*& head,\
	node<val_t>*& tail )
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
