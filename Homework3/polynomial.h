/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, spring 2013
	homework 3 - polynomial
	polynomial.h
	polynomial class represents a polynomial number of the following form
	Ai * x^(i) + Ai-1 * x^(i-1) + ... + A0 * x^0. provided with this class:
		-a default constructor
		-a constructor that takes an array and the size of the
		 array
		-a copy constructor
		-a get coefficient function for x^i
		-a get function for the degree of the polynomial
		-a function to set and get individual coefficients, Ai
		-a function to set and get the coefficient array of the
		 polynomial
    -a function eval (x) to compute the value of the given
		 polynomial at x
		-overloaded operator =
		-overloaded operator +
		-overloaded operator *
		-overloaded operator [], allows access the coefficient of x^i
		-overloaded operator (), allows computation of p (x)
		-overloaded operator <<, which displays the polynomial in
		 n-tuple form, ie (Ai, Ai-1, ..., A0)
*/


#include <iostream>

#ifndef _poly
#define _poly


class polynomial
{
public:
/*
	constructors
*/

/*
	precondition:		none
	postcondition:	creates a polynomial ( 0 ), that is it will create
									a polynomial of degree 0, not actually a polynomial
*/
	polynomial ();

/*
	precondition:		an array with contents representing the coefficients of
									the polynomial to be constructed, and the size of thearray
	postcondition:	creates a polynomial of degree provided. all
									coefficients are zero except the coefficient on the
									highest degree
*/
	polynomial ( double*, unsigned );

/*
	precondition:		an existing polynomial
	postcondition:	creates a polynomial with the same degree and contents
									of the existing polynomial
*/
	polynomial ( const polynomial& );


/*
	destructor
*/
	~polynomial ();


/*
	constant member functions
*/

/*
	precondition:		none
	postcondition:	returns the degree of the current polynomial
*/
	unsigned get_deg () const;

/*
	precondition:		none
	postcondition:	returns the pointer to the coefficient array
*/
	const double* coef_arr () const;

/*
	precondition:		the degree of the coefficient you would like to know
	postcondition:	returns the coefficient if the degree position
									supplied exists, otherwise returns a zero
*/
	double get_coef ( unsigned ) const;

/*
	precondition:		a double value x
	postcondition:	calculates p(x) and returns its result
*/
	double eval ( double ) const;


/*
	modification member functions
*/

/*
  precondition:   the degree of the coefficient you would like to know
  postcondition:  returns the coefficient if the degree position
                  supplied exists, otherwise returns a zero
*/
  double get_coef ( unsigned );

/*
	precondition:		the degree of the coefficient, and the new coefficient
									value ex. set_coef (deg, new_a)
	postcondition:	sets the coefficient of the x with the provided degree
									if that degree position is higher than the existing
									degree of the current polynomial, no change is made
*/
	void set_coef ( unsigned, double );

/*
	precondition:		an array of coefficients, and the size of the array
	postcondition:	sets the coefficients and degree for the current
									polynomial
*/
	void set_coef ( double*, unsigned );


/*
	operator functions
*/

/*
	precondition:		an existing polynomial
	postcondition:	adds calling polynomial + passed polynomial
*/
	polynomial operator + ( const polynomial& ) const;

/*
	precondition:		an existing polynomial
	postcondition:	multiplies calling polynomial * passed poly
*/
	polynomial operator * ( const polynomial& ) const;

/*
	precondition:		an existing polynomial
	postcondition:	assigns the values of the existing polynomial to a new
									polynomial
*/
	polynomial& operator = ( const polynomial& );

/*
	precondition:		a double value
	postcondition:	evaulates p (x)
*/
	double operator () ( double ) const;

/*
	precondition:		degree of the coefficient you wish to access
	postcondition:	returns the coefficient of x^i
*/
	double operator [] ( unsigned ) const;

/*
  precondition:   degree of the coefficient you wish to access
  postcondition:  returns the coefficient of x^i
*/
  double operator [] ( unsigned );


/*
	friends
*/
	friend std::ostream& operator << ( std::ostream&, const polynomial& );

private:
	double* coefs;
	unsigned degree;
};


#endif
