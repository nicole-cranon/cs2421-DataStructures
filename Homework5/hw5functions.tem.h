/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - sets and set operations
	hw5functions.tem.h
	see hw5functions.h for all documentation for the homework 5 namespace
	hw5functions
*/


#include "set.h"
#include <string>
#include <cassert>
#include <fstream>

namespace hw5functions
{
	void greeting ()
	{
		std::string go_ahead;

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout << "This program will read in three sets of " \
		"integers. It will display the read in sets then perform "\
		"set operations and display the results to the screen.\n";

		std::cout << "\nPlease press ENTER to proceed-> ";
		getline ( std::cin, go_ahead );
	}

	void check_args ( unsigned command_args)
	{
    assert ( command_args > 1 );
	}

	template <typename val_t>
	void read_file ( char* file, set<val_t>& s1, set<val_t>& s2, \
	set<val_t>& s3 )
	{
		unsigned len1 = 0, len2 = 0, len3 = 0;
		val_t temp;
		std::ifstream inf;

		inf.open ( file );
		assert ( inf.good () );

/*
		reads through each line of the file to see how many numbers
		are on each line
*/
		while ( inf.good () && inf.peek () != '\n' )
		{
			inf >> temp;
			++len1;
		}

    inf.ignore ();

    while ( inf.good () && inf.peek () != '\n' )
    {
			inf >> temp;
      ++len2;
    }

    inf.ignore ();

    while ( inf.good () && inf.peek () != '\n' )
    {
			inf >> temp;
      ++len3;
    }

/*
		returns the file stream to the beginning of the file
*/
		inf.seekg ( 0 );

/*
		reads through the file storing the contents
*/

		for ( int i = 0; i < len1; ++i )
		{
			inf >> temp;
			s1.insert ( temp );
		}

    inf.ignore ();

    for ( int i = 0; i < len2; ++i )
    {
      inf >> temp;
      s2.insert ( temp );
    }

    inf.ignore ();

    for ( int i = 0; i < len3; ++i )
    {
      inf >> temp;
      s3.insert ( temp );
    }

    inf.close ();
	}

  void closing ()
  {
    std::cout << "\n\n*\n";
    std::cout << "nicole cranon <nicole.cranon@ucdenver.edu>" \
    "\ncsci 2421, fall 2013" \
    "\nhomework assignment 5\n*\n\n\n";
  }
}
