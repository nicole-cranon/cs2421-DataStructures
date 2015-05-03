/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 4 - linked list based bag
	hw4functions.cpp
	see hw4functions.h for all documentation
*/


#include "hw4functions.h"
#include <string>
#include <cassert>
#include <fstream>

namespace hw4functions
{
	void greeting ()
	{
                std::string go_ahead;

                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                std::cout << "This program will read in two lists, one " \
		"of nouns, and another of verbs, from a file provided at " \
		"the command line. It will then construct 5 sentences " \
		"from randomly chosen nouns and verbs along with " \
		"adjectives and adverbs.\n";

                std::cout << "\nPress ENTER to continue-> ";
                getline ( std::cin, go_ahead );
	}

        void check_args ( int command_args )
        {
                assert ( command_args > 1 );
        }

	void read_file ( char* file, bag& nouns, bag& verbs)
	{
		std::ifstream inf;
		std::string temp;
		const int ITMS_PER_LINE = 5;

		inf.open ( file );

		assert ( inf.good () );

		for ( int i = 0; i < ITMS_PER_LINE; ++i )
		{
			inf >> temp;
			nouns.insert ( temp );
		}

		for ( int i = 0; i < ITMS_PER_LINE; ++i )
		{
			inf >> temp;
			verbs.insert ( temp );
		}

		inf.close ();
	}

	void construct_sentences ( const bag& nouns, const bag& verbs )
	{
		bag adverbs, adjectives;
		std::string temp;
		const int ITEMS_IN_BAG = 5;

/*
		populate the bag of adverbs
*/
		adverbs.insert ( "occasionally" );
		adverbs.insert ( "steadily" );
		adverbs.insert ( "finally" );
		adverbs.insert ( "deliberately" );
		adverbs.insert ( "always" );

/*
		populate the bag of adjectives
*/
		adjectives.insert ( "Clumsy" );
		adjectives.insert ( "Modern" );
		adjectives.insert ( "Hungry" );
		adjectives.insert ( "Zealous" );
		adjectives.insert ( "Important" );

/*
		create random sentences and print each 
*/
		for ( int i = 0; i < ITEMS_IN_BAG; ++i )
		{
			for ( int j = 0; j < ITEMS_IN_BAG; ++j )
			{
				temp = adjectives.grab ();
				temp += ' ';
				temp += nouns.grab ();
				temp += ' ';
				temp += verbs.grab ();
				temp += ' ';
				temp += adverbs.grab ();
				temp += '.';
			}

			std::cout << '\n' << temp << '\n';
		}
	}

	void closing ()
	{
                std::cout << "\n\n*\n";
                std::cout << "nicole cranon <nicole.cranon@ucdenver.edu>" \
                "\ncsci 2421, fall 2013" \
                "\nhomework assignment 4\n*\n\n\n";
	}
}
