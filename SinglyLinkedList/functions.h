/*
  nicole cranon <nicole.cranon@ucdenver.edu
  csci 2421, fall 2013
*/

/*
	modification functions on list
*/
template <typename val_t>
node<val_t>* list<val_t>::search ( const val_t& target )
{
  if ( this-> head_ptr != 0 )
  {
    node<val_t>* cursor = this-> head_ptr;

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
node<val_t>* list<val_t>::locate ( unsigned position )
{
  if ( position > 0 && position <= this-> length )
  {
    node<val_t>* cursor = this-> head_ptr;

    if ( position == 1 )
    {
      return this-> head_ptr;
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


/*
	constant functions on the list
*/

template <typename val_t>
const node<val_t>* list<val_t>::search ( const val_t& target ) const
{
  if ( this-> head_ptr != 0 )
  {
    node<val_t>* cursor = this-> head_ptr;

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
const node<val_t>* list<val_t>::locate ( unsigned position ) const
{
  if ( position > 0 && position <= this-> length )
  {
    const node<val_t>* cursor = this-> head_ptr;

    if ( position == 1 )
    {
      return this-> head_ptr;
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
