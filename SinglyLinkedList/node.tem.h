/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	node.tem.h
	see node.tem.h for the documentation of the node class 
*/


/*
	node constructors
*/
template <typename val_t>
node<val_t>::node () : data_field ( 0 ), link_field ( 0 ) {}

template <typename val_t>
node<val_t>::node ( const val_t& data ) : data_field ( data ), \
link_field ( 0 ) {}

template <typename val_t>
node<val_t>::node ( const val_t& data, node<val_t>* link )\
: data_field ( data ), link_field ( link ) {}


/*
	node constant members
*/
template <typename val_t>
val_t node<val_t>::data () const 
{ 
	return data_field; 
}

template <typename val_t>
const node<val_t>* node<val_t>::link () const 
{ 
	return link_field; 
}


/*
	node modification members
*/
template <typename val_t>
node<val_t>* node<val_t>::link () 
{ 
	return link_field; 
}

template <typename val_t>
void node<val_t>::set_data ( const val_t& data ) 
{ 
	data_field = data; 
}

template <typename val_t>
void node<val_t>::set_link ( node<val_t>* link ) 
{ 
	link_field = link; 
}
