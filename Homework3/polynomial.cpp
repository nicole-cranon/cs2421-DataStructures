/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, spring 2013
	homework 3 - polynomial
	polynomial.cpp
	see polynomial.h for all documentation of the polynomial class
*/


#include "polynomial.h"
#include <cmath>

/*
	constructors
*/

polynomial::polynomial () : degree ( 0 ) 
{ 
	coefs = new double  [ 1 ];
	coefs [ degree ] = 0;
}

polynomial::polynomial ( double* coef_arr, unsigned size )
{
        coefs = new double [ size ];
	unsigned new_degree;

        for ( int i = 0; i < size; ++i )
        {
                coefs [ i ] = coef_arr [ i ];

                if ( coef_arr [ i ] > 0 )
                        new_degree = i;
        }

	degree = new_degree;
}

polynomial::polynomial ( const polynomial& ply ) 
{
        coefs = new double [ ply.degree + 1 ];

        for ( int i = 0; i < ply.degree + 1; ++i )
        {
                coefs [ i ] = ply.coefs [ i ];
        }

	degree = ply.degree;
}


/*
	destructor
*/
polynomial::~polynomial ()
{
	delete [] coefs;
	coefs = 0;
	degree = 0;
}


/*
	constant member functions
*/

unsigned polynomial::get_deg () const { return this-> degree; }

const double* polynomial::coef_arr () const { return this-> coefs; }

double polynomial::get_coef ( unsigned deg ) const
{
/*
	if the provided x degree position is less than or equal to the 
	highest degree of the current polynomial, return its coefficient
	else return 0
*/
	if ( deg <= this-> degree )
		return this-> coefs [ deg ];

	return 0;
}

double polynomial::eval ( double x ) const
{
/*
	is a polynomial?
*/
	if ( this-> degree > 0 )
	{
		double poly_sum = 0;

		for ( int i = 0; i < this-> degree + 1; ++i )
		{
			poly_sum += this-> coefs [ i ] * pow ( x, i );
		}

		return poly_sum;
	}

/*
	if not a polynomial returns the value of A0
*/
	return this-> coefs [ 0 ];
}


/*
	modification member functions
*/

double polynomial::get_coef ( unsigned deg ) 
{
/*
        if the provided x degree position is less than or equal to the 
        highest degree of the current polynomial, return its coefficient
        else return 0
*/
        if ( deg <= this-> degree )
                return this-> coefs [ deg ];

        return 0;
}

void polynomial::set_coef ( unsigned deg, double coef )
{
	if ( deg <= this-> degree )
	{
		this-> coefs [ deg ] = coef;

/*
		if the x degree is the current highest and the coefficient is 
		to be changed to zero, decrement the degree
*/
		if ( coef == 0 && deg == this-> degree )
		{
			--degree;
		}
	}
}

void polynomial::set_coef ( double* coef_arr, unsigned size )
{
	double* new_coefs = new double [ size ];
	this-> degree = 0;

	for ( int i = 0; i < size; ++i )
	{
		new_coefs [ i ] = coef_arr [ i ];

		if ( coef_arr [ i ] > 0 )
			this-> degree = i;
	}

	this-> coefs = new_coefs;
}


/*
	operator functions
*/

polynomial polynomial::operator + ( const polynomial& ply ) const
{
	unsigned ARR_SIZE;

	if ( ply.degree > this-> degree )
		ARR_SIZE = ply.degree + 1;
	else
		ARR_SIZE = this-> degree + 1;

	double* new_coefs = new double [ ARR_SIZE ];

	for ( int i = 0; i < ARR_SIZE; ++i )
	{
		new_coefs [ i ] = 0;
	}

	for ( int i = 0; i < ARR_SIZE; ++i )
	{
/*
		sums the coefficients of each polynomial 
*/
		if ( i <= this-> degree )
			new_coefs [ i ] += this-> coefs [ i ];
		if ( i <= ply.degree )
			new_coefs [ i ] += ply.coefs [ i ];
	}

	polynomial new_ply ( new_coefs, ARR_SIZE );

	return new_ply;
}

polynomial polynomial::operator * ( const polynomial& ply ) const
{
	const unsigned ARR_SIZE = ply.degree + this-> degree + 1;
	double *new_coefs = new double [ ARR_SIZE ];

/*
	multiply each term of both polynomials and combine like terms
*/

	for ( int i = 0; i < ARR_SIZE; ++i )
	{
		new_coefs [ i ] = 0;
	} 

	for ( int i = 0; i < this-> degree + 1; ++i )
	{
		for ( int j = 0; j < ply.degree + 1; ++j )
		{
			new_coefs [ i + j ] += this-> coefs [ i ] * \
			ply.coefs [ j ];
		}
	}

	polynomial new_ply ( new_coefs, ARR_SIZE );

	return new_ply;
}

polynomial& polynomial::operator = ( const polynomial& ply )
{
	if ( this != & ply )
	{
		double* new_coefs = new double [ ply.degree + 1 ];
		this-> coefs = new_coefs;

		for ( int i = 0; i < ply.degree + 1; ++i)
		{
			coefs [ i ] = ply.coefs [ i ];
		}

		this-> degree = ply.degree;
	}

	return *this;
}

double polynomial::operator () ( double x ) const
{
	return this-> eval ( x );
}

double polynomial::operator [] ( unsigned deg ) const
{
	return this-> get_coef ( deg );
}

double polynomial::operator [] ( unsigned deg )
{
	return this-> get_coef ( deg );
}


/*
	friend functions
*/

std::ostream& operator << ( std::ostream& out, const polynomial& ply )
{
	out << "( ";

	for ( int i = ply.degree; i > -1; --i )
	{
		out << ply.coefs [ i ];
		if ( i != 0 )
			out << ", ";
	}

	out << " )";

	return out;
}
