/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 2 - rlc circuits and complex numbers class
	complex.h
	complex class represents a complex number of the form x + jy, where x is
	the real part and y is the imaginary part. provided with this class:
		-set and get functions for the real part x
		-set and get functions for the imaginary part y
		-overloaded stream insertion operator <<, which displays the
		 complex number in tuple form (x, y)
		-a function named mag that returns the magnitude of the complex
		 number
		-a function named arg which returns the polar angle of the
		 complex number
		-overloaded operators +, -, *, and /
*/


#include <iostream>

#ifndef _comp
#define _comp


class complex
{
public:
	//	constructors

	/*
		precondition:		none
		postcondition:	creates a complex object with default values
										complex ( 1, 0 )
	*/
	complex ();

	/*
		precondition:		two double numbers
		postcondition:	creates a complex number such that
										complex ( real, imaginary )
	*/
	complex ( double, double );


	// 	constant member functions

	/*
		precondition:		none
		postcondition:	returns the real part of the complex number
	*/
	double get_real () const;

	/*
		precondition:		none
		postcondition:	returns the imaginary part of the complex number
	*/
	double get_imag () const;

	/*
		precondition:		none
		postcondition:	returns the magnitude of the complex number
	*/
	double mag () const;

	/*
		precondition:		a complex number whose real part is not equal to zero
		postcondition:	returns the polar angle of the complex number

		PLEASE NOTE : IF THE REAL PART OF THE PASSED COMPLEX
		NUMBER IS ZERO PROPER FUNCTIONALITY IS NOT GUARANTEED
	*/
	double arg () const;


	// 	modification member functions

	/*
		precondition:		a double number
		postcondition:	sets the real part of the complex number
	*/
	void set_real ( double );

	/*
		precondition:		a double number
		postcondition:	sets the imaginary part of the complex number
	*/
	void set_imag ( double );


	// 	operator functions

	/*
		precondition:		a complex number
		postcondition:	adds the calling complex number to the passed complex
										number
	*/
	complex operator + ( const complex& ) const;

	/*
		precondition:		a complex number
		postcondition:	subtracts the passed complex number from the calling
										complex number
	*/
	complex operator - ( const complex& ) const;

	/*
		precondition:		a complex number
		postcondition:	multiples the calling complex number by the passed in
										complex number
	*/
	complex operator * ( const complex& ) const;

	/*
		precondition:		a complex number whose magnitude is not zero
		postcondition:	divides the calling complex number by the passed in
										complex number

		PLEASE NOTE : IF THE MAGNITUDE OF THE COMPLEX NUMBER IS
		EQUAL TO ZERO, FUNCTIONALITY IS NOT GUARANTEED
	*/
	complex operator / ( const complex& ) const;

	/*
		precondition:		a complex number
		postcondition:	adds the passed in complex number to the calling complex
										number and sets the calling complex number's values to
										the result
	*/
	complex& operator += ( const complex& );

	/*
		precondition:		a complex number
		postcondition:	subtracts the passed in complex number from the calling
										complex number and sets the calling complex number's
										value to the result
	*/
	complex& operator -= ( const complex& );


	// 	friends

	/*
		precondition:		none
		postcondition:	prints a complex number in tuple form (real, imaginary)
	*/
	friend std::ostream& operator << ( std::ostream&, const complex& );


private:
	double real, imaginary;
};


#endif
