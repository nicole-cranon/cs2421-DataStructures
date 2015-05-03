/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 3 - polynomial
	hw3functions.h
	hw3function namespace contains the functions used in the driver for the
	homework 3 program assignment. contained in the homework 3 namespace:
		-a greeting detailing the program
		-a function to check that enough arguments were passed at the
		 command line
		-a function to read in the polynomials of the provided files
		-a function to add the polynomials and display the 
		 resulting polynomial
		-a function to multiply the polynomials and display the 
		 resulting polynomial
		-a function to evaluate the two polynomials at the x value
		 provided at the command line and dispay their results
		-a closing function
*/


#include "polynomial.h"

#ifndef _HW3
#define _HW3


namespace hw3functions
{
/*
	precondition: 	none
	postcondition:	provides a short description of the program
*/
	void greeting ();

/*
	precondition:	the numer of arguments provided at the command line
	postcondition:	checks if there are enough arguments to proceed with
			the program, if there are the program continues,
			else it quits
*/
	void check_args ( int );

/*
	precondition:	two double pointers, and two unsigned variables to
			hold the size of those arrays
	postcondition:	creates two coefficient arrays
*/
	void read_file ( char*, double*&, double*&, unsigned&, unsigned& );

/*
	precondition:	two polynomials, p1 and p2
	postcondition:	adds p3 = p1 + p2 and displays p3
*/
	void add ( const polynomial&, const polynomial& );

/*
	precondition:	two polynomials, p1 and p2
	postcondition:	multiplies p3 = p1 * p2 and displays p3
*/
	void multiply ( const polynomial&, const polynomial& );

/*
	precondition:	the x value and the two polynomials
	postcondition:	evaluates each polynomial at x and displays their
			results
*/
	void evaluate ( char*, const polynomial&, const polynomial& );

/*
	precondition:	none
	postcondition:	presents a closing to the program
*/
	void closing ();
}

namespace hw3 = hw3functions;


#endif
