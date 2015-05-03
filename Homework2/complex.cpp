/*
	nicole cranon <nicole.cranon@ucdencer.edu>
	csci 2421, fall 2013
	homework 2 - rlc circuits and complex numbers class
	complex.cpp
	please refer to complex.h for complex class documentation
*/


#include <cmath>
#include "complex.h"

//	constructors

complex::complex () : real (1), imaginary (0)
{}

complex::complex (double r, double i) : real (r), imaginary (i)
{}


//	constant member functions

double complex::get_real () const
{
	return real;
}

double complex::get_imag () const
{
	return imaginary;
}

double complex::mag () const
{
	//	magnitude of a complex number
	return sqrt ( real * real + imaginary * imaginary );
}

double complex::arg () const
{
/*
	if ( real == 0 )
		return;
*/
	return atan ( imaginary / real );
}


//	 modification member functions

void complex::set_real ( double r )
{
	real = r;
}

void complex::set_imag ( double i )
{
	imaginary = i;
}


//	operator functions

complex complex::operator + ( const complex& c ) const
{
	complex new_c;

	new_c.real = real + c.real;
	new_c.imaginary = imaginary + c.imaginary;

	return new_c;
}

complex complex::operator - ( const complex& c ) const
{
	complex new_c;

	new_c.real = real - c.real;
	new_c.imaginary = imaginary - c.imaginary;

	return new_c;
}

complex complex::operator * ( const complex& c ) const
{
	complex new_c;

	/*
	result of ...
	complex	=	complex1 * complex2
		=	( real1 + imag1 ) * ( real2 + imag2 )
	*/
	new_c.real = real * c.real - imaginary * c.imaginary;
	new_c.imaginary = real * c.imaginary + c.real * imaginary;

	return new_c;
}

complex complex::operator / ( const complex& c ) const
{
	complex new_c;
	
	/*
	result of ...
	complex	=	complex1 / complex2
		=	( real1 + imag1 ) / ( real2 + real2 )
	*/
	new_c.real = ( real * c.real + imaginary * c.imaginary ) / ( \
	c.mag () * c.mag () );
	new_c.imaginary = ( c.real * imaginary - real * c.imaginary ) / ( \
	c.mag () * c.mag () );

	return new_c;
}

complex& complex::operator += ( const complex& c )
{
	*this = *this + c;
	return *this;
}

complex& complex::operator -= ( const complex& c )
{
	*this = *this - c;
	return *this;
}


//	friends

std::ostream& operator << ( std::ostream& out, const complex& c )
{
	out << "( " << c.real << ", " << c.imaginary << " )";
	return out;
}
