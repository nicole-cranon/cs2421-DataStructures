/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 2 - rlc circuits and complex numbers class
	hw2.cpp
	this file is the driver for a program that will compute the complex
	series and parallel impedance from user defined resistance (r), 
	inductance (l), capacitance (c), and sinusoidal steady-state 
	frequency (w)
*/


#include "hw2functions.h"

int main ()
{
	// 	greet the user with a breif description of the program
	hw2::greeting ();

	/*
	variables for resistance, inductance, capacitance, and sinusoidal
	steady-state frequency
	*/
	double r, l, c, w;

	//	get user to define r, l, c, w
	hw2::set_rlcw ( r, l, c, w );

	//	calculate series impedance due to the r, l, c, w values
	complex Zs = hw2::s_impedance ( r, l, c, w );
	
	//	print complex series impedance
	std::cout << "\nComplex series impedance:\nZs = " << Zs << '\n';

	//	calculate parallel impedance due to the r, l, c, w, values
	complex Zp = hw2::p_impedance ( r, l, c, w );

	// 	print compex parallel impedance
	std::cout << "\nComplex parallel impedance:\nZp = " << Zp << '\n';

	//	closing comments
	hw2::closing ();

	return (0);
}
