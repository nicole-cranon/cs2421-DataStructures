/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 2 - rlc circuits and complex numbers class
	hw2functions.h
	contains global namespace functions for the homework 2 program
	assignment. provided in this namespace:
		-a greeting
		-a function to set the resistance, inductance, capacitance,
		 and sinusoidal steady-state frequency, (ie r, l, c, w)
		-a function to compute the complex series impedance, Zs
		-a function to compute the complex parallel impedance, Zp
*/


#include "complex.h"

#ifndef _HW2
#define _HW2

namespace hw2functions
{
	/*
	precondition:		none
	postcondition:	provides a short description of the program
	*/
	void greeting ();

	/*
		precondition:		variables for resistance, inductance, capacitance, and
										sinusoidal steady-state frequency
		postcondition:	prompts the user for each of these values and then
										assigns them to their corresponding variable
	*/
	void set_rlcw ( double&, double&, double&, double& );

	/*
		precondition:		resistance, inductance, capactiance, and sinusoidal
										steady-state frequency
		postcondition:	returns the complex series impedance
	*/
	complex s_impedance ( double, double, double, double );

	/*
		precondition:		resistance, inductance, capacitance, and sinusoidal
										steady-state frequency
		postcondition:	returns the complex parallel impedance
	*/
	complex p_impedance ( double, double, double, double );

	/*
		precondition:		none
		postcondition:	closing comments
	*/
	void closing ();
}

namespace hw2 = hw2functions;


#endif
