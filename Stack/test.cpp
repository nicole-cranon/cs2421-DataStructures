#include "stack.h"

int main ()
{
	stack<double> double_stack;
	double d = 13.79;

	for ( int i = 0; i < 15; ++i )
	{
		double_stack.push ( d );
		d += 1;
	}

	while ( !double_stack.empty () )
	{
		std::cout << double_stack.front () << ' ';
		double_stack.pop ();
	}

	std::cout << '\n';
}
