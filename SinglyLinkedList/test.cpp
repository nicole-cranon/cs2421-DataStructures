/*
	test
*/

#include "list.h"


using namespace std;

int main ()
{
	list<int> int_list;

	for ( int i = 0; i < 9; ++i )
	{
		int_list.front_insert ( i );
	}

	list<int> new_ints;
	new_ints = int_list;

	list<int>::iterator itr = new_ints.begin ();

	for ( int i = 0; i < new_ints.size () - 1; ++i )
		++itr;

	new_ints.remove ( itr );

	list<int> added_ints;
	added_ints = new_ints + int_list;

	cout << '\n' << new_ints << '\n';
}
