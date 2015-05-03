/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 3 - polynomial
	hw3.cpp
	this file is a driver for a program that will read two polynomials from
	a file, it will add, multiply, and evaluate at a value x both 
	polynomials
*/

#include "hw3functions.h"

int main ( int argc, char* argv [] )
{
/*
	check there are enough arguments for the program to run, if not ends
	the program, requires executable name, input file name, and a value x to
	to evaluate the polynomials at.
*/
	hw3::check_args ( argc );

/*
	free store arrays to be used for polynomial coefficient arrays, variables
	to store their size once known
*/
	double* coef_arr1 = new double [ 0 ];
	double* coef_arr2 = new double [ 0 ];
	unsigned size1, size2;

/*
	display greeting
*/
	hw3::greeting ();

/*
	reads the file provided at the command line and populates the 
	polynomials with coefficients within the file
*/
	hw3::read_file ( argv [ 1 ], coef_arr1, coef_arr2, size1, size2 );

/*
	creates two polynomials
*/
	polynomial p1 ( coef_arr1, size1 ), p2 ( coef_arr2, size2 );

/*
	prints the polynomials
*/
	std::cout << "\nP1 = " << p1 << '\n';
	std::cout << "\nP2 = " << p2 << '\n';

/*
	p3 = p1 + p2, displays p3
*/
	hw3::add ( p1, p2 );

/*
	p3 = p1 * p2, displays p3
*/
	hw3::multiply ( p1, p2 );

/*
	evaluate polynomials p1 and p2 at value x, provided at the command line
	first it converts the value x to double
*/
	hw3::evaluate ( argv [ 2 ], p1, p2 );


/*
	displays closing comments
*/
	hw3::closing ();

	return 0;
}
