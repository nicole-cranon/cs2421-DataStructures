/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 3 - polynomial
	hw3functions.cpp
	see hw3functions.h for functions documentation
*/


#include "hw3functions.h"
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>

namespace hw3functions
{
	void greeting ()
	{
		std::string go_ahead;

		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout << "This Program will read in information for two " \
		"polynomials from a file provided at the command line. It " \
		"will add the two polynomials, multiply them, and evaluate " \
		"each at the value x provided at the command line.\n";

		std::cout << "\nPress ENTER to continue-> ";
		getline ( std::cin, go_ahead);
	}

	void check_args ( int command_args )
	{
		assert ( command_args > 2 );
	}

	void read_file ( char* filename, double*& c1, double*& c2, unsigned& \
	count1, unsigned& count2 )
	{
		std::ifstream inf;
		count1 = 0;
		count2 = 0;
		double temp;
		char next_char;

		inf.open ( filename );

		assert ( inf.is_open () );

/*
		counts the numbers on line 1
*/		
		while (inf.peek () != '\n')
		{
			inf >> temp;
			++count1;
		}

/*
		ignores the '\n'
*/
		inf.ignore ();

/*
		counts the numbers on line 2
*/
		while (inf.peek () != '\n' && inf.peek () != EOF)
		{
			inf >> temp;
			++count2;
		}

		std::cout << "\nFile line 1 contains " << count1 << " numbers";
		std::cout << "\nFile line 2 contains " << count2 << " numbers" \
		"\n";

/*
		returns the file stream to the beginning of the file
*/
		inf.seekg ( 0 );
/*
		creates new arrays and fills with file contents
*/
		c1 = new double [ count1 ];
		c2 = new double [ count2 ];

		for ( int i = 0; i < count1; ++i )
		{
			inf >> c1 [ i ];
		}

		inf.ignore ();

		for ( int i = 0; i < count2; ++i )
		{
			inf >> c2 [ i ];
		}

		inf.close ();
	}

	void add ( const polynomial& ply1, const polynomial& ply2 )
	{
		polynomial ply3;
		ply3 = ply1 + ply2;

		std::cout << "\nP1 + P2 = " << ply3 << '\n';
	}

        void multiply ( const polynomial& ply1, const polynomial& ply2 )
        {
                polynomial ply3;
                ply3 = ply1 * ply2;

                std::cout << "\nP1 * P2 = " << ply3 << '\n';
        }


	void evaluate ( char* x, const polynomial& ply1, const polynomial& \
	ply2 )
	{
		double double_x, result1, result2;

		double_x = atof (x);

		result1 = ply1 (double_x);
		result2 = ply2 (double_x);

		std::cout << "\nP1 ( " << double_x << " ) = " << result1 << '\n';
		std::cout << "\nP2 ( " << double_x << " ) = " << result2 << '\n';
	}

	void closing ()
	{
                std::cout << "\n\n*\n";
                std::cout << "nicole cranon <nicole.cranon@ucdenver.edu>" \
                "\ncsci 2421, fall 2013" \
                "\nhomework assignment 3\n*\n\n\n";
	}
}
