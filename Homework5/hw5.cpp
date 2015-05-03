/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - sets and set operations
	hw5.cpp
	this program will read in three sets of integers. it will display the
	read in sets then perform set operations and display the results 
	to the screen.
*/

#include "hw5functions.h"

int main ( int argc, char* argv [] )
{
/*
        checks that enough arguments were provided at the command line to run
        the program
*/
        hw5::check_args ( argc );

/*
	greets the user with a brief description of the homework 5 program
*/
	hw5::greeting ();

	set <int> A, B, C;

/*
	reads the contents of the command line provided file and stores them 
	into sets
*/
	hw5::read_file ( argv[1], A, B, C );

/*
	prints the contents of sets A, B, and C
*/
	std::cout << "\nA = " << A << "\nB = " << B << "\nC = " << C << '\n';


/*
	perform set operations
*/

	set <int> solution_set;

/*
	solution_set = A [intersect] ( B [union] C )
*/
	solution_set = A & ( B + C );
	std::cout << "\nA & ( B + C ) = " << solution_set << '\n';

/*
	solution_set = ( A [union] B ) [difference] C
*/
	solution_set = ( A + B ) - C;
	std::cout << "\n( A + B ) - C = " << solution_set << '\n';

/*
	solution_set = ( A [intersect] B ) [union] ( B [intersect] C )
*/
	solution_set = ( A & B ) + ( B & C );
	std::cout << "\n( A & B ) + ( B & C ) = " << solution_set << '\n';

/*
	solution_set = ( A [difference] B ) [union] ( C [difference] A )
*/
	solution_set = ( A - B ) + ( C - A );
	std::cout << "\n( A - B ) + ( C - A ) = " << solution_set << '\n';

/*
	is true? [ ( A [intersect] B ) == ( B [difference] C ) ]
*/
	bool equ = ( A & B ) == ( B - C ); 
	std::cout << "\n( A & B ) == ( B - C ) \n= " << ( A & B ) << " == " \
	<< ( B - C ) << " = " << std::boolalpha << equ << '\n';


/*
	closing comments
*/
	hw5::closing ();
}
