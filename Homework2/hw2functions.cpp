/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homeowrk 2 - rlc circuits and complex numbers class
	hw2functions.cpp
	see hw2functions.h for all documentation
*/


#include "hw2functions.h"

namespace hw2functions
{
	void greeting ()
	{
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout << "This program will calculate the complex " \
		"series and parallel impedance for user defined " \
		"resistance (r), inducatance (l), capacitance (c), and " \
		"sinusoidal steady-state frequency (w).\n";

		std::cout << "\nPress ENTER to continue-> ";
	}

	void set_rlcw ( double& r, double& l, double& c, double& w )
	{
		//	used to collect bad input
		std::string bad_in;

		do
		{
                        //      reset bad and fail bit flags
                        std::cin.clear ();

                        //      collect anything after the bad input
                        getline ( std::cin, bad_in );

			std::cout << "\nPlease enter a numeric value for " \
			"resistance (r)-> ";
			std::cin >> r;
		} while ( !( std::cin.good() ) );

                do
                {
                        //      reset bad and fail bit flags
                        std::cin.clear ();

                        //      collect anything after the bad input
                        getline ( std::cin, bad_in );

                        std::cout << "\nPlease enter a numeric value for " \
                        "inductance (l)-> ";
                        std::cin >> l;
                } while ( !( std::cin.good() ) );

                do
                {
                        //      reset bad and fail bit flags
                        std::cin.clear ();

                        //      collect anything after the bad input
                        getline ( std::cin, bad_in );

                        std::cout << "\nPlease enter a numeric value for " \
                        "capacitance (c)-> ";
                        std::cin >> c;
                } while ( !( std::cin.good() ) );

                do
                {
                        //      reset bad and fail bit flags
                        std::cin.clear ();

                        //      collect anything after the bad input
                        getline ( std::cin, bad_in );

                        std::cout << "\nPlease enter a numeric value for " \
                        "the sinusoidal steady-state frequecy (w)-> ";
                        std::cin >> w;
                } while ( !( std::cin.good() ) );

		std::cout << "\nResistance (r) = " << r << \
		" ohms\nInductance (l) = " << l << \
		" henries\nCapacitance (c) = " << c <<\
		" farads\nSinusoidal steady-state frequency (w) = "\
		<< w << " radians/second\n";
	}

	complex s_impedance ( double r, double l, double c, double w )
	{
		/*
		impedance (Z) due to restance, inductance, and capacitance
		*/
		complex Zr, Zl, Zc;

		// 	set the values for impedance due to resistance
		Zr.set_real ( r );
		Zr.set_imag ( 0 );

		//	set the values for impedance due to indctance
		Zl.set_real ( 0 );
		Zl.set_imag ( w * l );

		//	set the values for impedance due to capacitance
		Zc.set_real ( 0 );
		Zc.set_imag ( -1 / ( w * c ) );

		//	total impedance Z = Zr + Zl + Zc
		return Zr + Zl + Zc;
	}

	complex p_impedance ( double r, double l, double c, double w )
	{
		/*
		impedance (Z) due to restance, inductance, capacitance and
		sinusoidal steady-state frequency
		*/
		complex Zr, Zl, Zc;

		//	set the values for impedance due to resistance
		Zr.set_real ( 0 );
		Zr.set_imag ( r );

		//	set the values for impedance due to inductance
		Zl.set_real ( 0 );
		Zl.set_imag ( w * l );

		//	ser the values for impedance due to capacitance
		Zc.set_real ( 0 );
		Zc.set_imag ( -1 / ( w * c ) );

		/*
		total impedance Z = ( Zr * Zl * Zc ) / ( Zc * Zl + Zr * Zc +
		Zr * Zl )
		*/
		return ( Zr * Zl * Zc ) / ( Zc * Zl + Zr * Zc + Zr * Zl );
	}

	void closing ()
	{
		std::cout << "\n\n\n\n*\n";
		std::cout << "nicole cranon <nicole.cranon@ucdenver.edu>" \
		"\ncsci 2421, fall 2013" \
		"\nhomework assignment 2\n*\n\n\n\n\n";
	}
}
