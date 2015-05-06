/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	list.tem.h
	see list.tem.h for all list class documentation
*/


/*
	constructors
*/
template <typename val_t>
list<val_t>::list () : length ( 0 ) /* head_ptr ( 0 ), tail_ptr ( 0 )*/
{
	head_ptr = 0;
	tail_ptr = 0;
}

template <typename val_t>
list<val_t>::list ( const val_t& data ) : length ( 1 )
{
	head_ptr = new node<val_t> ( data );
	tail_ptr = head_ptr;
}

template <typename val_t>
list<val_t>::list ( const list& l )
{
	head_ptr = new node<val_t> ( l.head_ptr );
	tail_ptr = new node<val_t> ( l.tail_ptr );
}

/*
	destructor
*/
template <typename val_t>
list<val_t>::~list ()
{
	this-> clear ();
}


/*
	constant member functions
*/
template <typename val_t>
unsigned list<val_t>::size () const
{
	return this-> length;
}

template <typename val_t>
typename list<val_t>::iterator list<val_t>::begin () const
{
	typename list<val_t>::iterator itr ( this-> head_ptr );
	return itr;
}

template <typename val_t>
typename list<val_t>::iterator list<val_t>::end () const
{
	typename list<val_t>::iterator itr;
	return itr;
}

template <typename val_t>
val_t list<val_t>::front () const
{
	return this-> head_ptr-> data ();
}

template <typename val_t>
val_t list<val_t>::back () const
{
	return this-> tail_ptr-> data ();
}


/*
	modification members
*/
template <typename val_t>
void list<val_t>::front_insert ( const val_t& data )
{
/*
  creates a new node with data_field = data and link_field = current head
*/
  node<val_t>* new_head = new node<val_t> ( data, this-> head_ptr );

/*
  is this the first insert?
*/
  if ( this-> head_ptr == 0 && this-> tail_ptr == 0 )
  {
    this-> tail_ptr = new_head;
  }

  this-> head_ptr = new_head;

	++this-> length;
}

template <typename val_t>
void list<val_t>::back_insert ( const val_t& data )
{
/*
  creates a new node with data_field = data and link_field = 0
*/
  node<val_t>* new_tail = new node<val_t> ( data );

/*
  is this the first insert?
*/
  if ( this-> tail_ptr == 0 && this-> head_ptr == 0 )
  {
    this-> head_ptr = new_tail;
		this-> tail_ptr = new_tail;
  }

/*
	not the first insert
*/
	else
	{
		this-> tail_ptr-> set_link ( new_tail );
    this-> tail_ptr = new_tail;
	}

	++this-> length;
}

template <typename val_t>
void list<val_t>::insert ( const typename list<val_t>::iterator& position, \
const val_t& data )
{
	typename list<val_t>::iterator tail ( this-> tail_ptr );

/*
	is an insert at the beginning?
*/
	if ( position == this-> begin () )
	{
		this-> front_insert ( data );
	}

/*
	is an insert at the tail?
*/
	else if ( position == tail )
	{
		this-> back_insert ( data );
	}

/*
	is an insert within the list not the beginning and not the tail
*/
	else
	{
		node<val_t>* precursor, *cursor;
		typename list<val_t>::iterator itr;

		itr = this-> begin ();
		++itr;

		precursor = this-> head_ptr;
		cursor = precursor-> link ();

/*
		when itr == position, cursor is at the insert location
*/
		for ( ; itr != position; ++ itr )
		{
			precursor = precursor-> link ();
			cursor = cursor-> link ();
		}

/*
		newly created node has data put into its data field, and cursor
		put into its link field
*/
		node<val_t>* new_node = new node<val_t> ( data, cursor );

/*
		maintain the structure of the list
*/
		precursor-> set_link ( new_node );
		++ this->length;
	}
}

template <typename val_t>
void list<val_t>::head_remove ()
{
  if ( this-> head_ptr != 0 )
  {
/*
		there is only one item in the list
*/
		if ( this-> head_ptr == this-> tail_ptr )
		{
/*
			we make the tail pointer null, and allow the code below
			that deletes the head node pointer to delete the
			node that both the tail and head pointers point at
*/
			this-> tail_ptr = 0;
		}

/*
		delete the head, and make a null pointer, or point at the next
		node
*/
    node<val_t>* frmr_head = this-> head_ptr;
    this-> head_ptr = frmr_head-> link ();
    delete frmr_head;

		-- this-> length;
  }
}

template <typename val_t>
void list<val_t>::remove ( const typename list<val_t>::iterator& position )
{
/*
	is a remove of the head?
*/
	if ( position == this-> begin () )
	{
		this-> head_remove ();
	}

/*
	is a removal at a position other than the head, potentially at the tail
*/
	else
	{
		node<val_t>* precursor, *cursor;
		typename list<val_t>::iterator itr;

		itr = this-> begin ();
		++itr;

		precursor = this-> head_ptr;
		cursor = precursor-> link ();

/*
		when itr == position, cursror is the node to be removed
*/
		for ( ; itr != position; ++itr )
		{
			precursor = precursor-> link ();
			cursor = cursor-> link();
		}

/*
		maintain the structure of the list
*/
		precursor-> set_link ( cursor-> link () );

/*
		is it the tail we are removing?
*/
		if ( cursor == this-> tail_ptr )
		{
			this-> tail_ptr = precursor;
		}

		delete cursor;

		-- this-> length;
	}
}

template <typename val_t>
void list<val_t>::clear ()
{
  while ( this-> head_ptr != 0 )
  {
    this-> head_remove ();
  }
}

template <typename val_t>
typename list<val_t>::iterator list<val_t>::begin ()
{
	typename list<val_t>::iterator itr ( this-> head_ptr );
	return itr;
}

template <typename val_t>
typename list<val_t>::iterator list<val_t>::end ()
{
  typename list<val_t>::iterator itr;
  return itr;
}


/*
	operator functions
*/
template <typename val_t>
list<val_t>& list<val_t>::operator = ( const list& l )
{
	if ( this != &l )
	{
		typename list<val_t>::iterator itr;

		for ( itr = l.begin (); itr != l.end (); ++itr )
		{
/*
			use a back_insert so that we can maintain the order of
			list l's contents
*/
			this-> back_insert ( *itr );
		}
	}

	return *this;
}

template <typename val_t>
list<val_t> list<val_t>::operator + ( const list<val_t>& l ) const
{
	list<val_t> new_list;
	typename list<val_t>::iterator itr;

	for ( itr = this-> begin (); itr != this-> end (); ++itr )
	{
		new_list.back_insert ( *itr );
	}

	for ( itr = l.begin (); itr != l.end (); ++itr )
	{
		new_list.back_insert ( *itr );
	}

	return new_list;
}

template <typename val_t>
std::ostream& operator << ( std::ostream& out, const list<val_t>& l )
{
	typename list<val_t>::iterator itr = l.begin ();

	for ( int i = 0; i < l.length; ++i )
	{
		out << *itr;
		++itr;

		if ( i != l.length - 1 )
			out << ", ";
	}

	return out;
}
