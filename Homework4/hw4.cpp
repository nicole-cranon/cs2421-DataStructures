/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 4 - linked list based bag
	hw4.cpp
	this program will read two lines of lists. one of nouns and one of
	verbs. it will then proceed to creat random sentences from those
	nouns and verbs along with hardcoded adjectives and adverbs.
*/


#include "hw4functions.h"
#include <cstdlib>
#include <ctime>

int main ( int argc, char* argv[] )
{
/*
	check the number of command line arguments
*/
	hw4::check_args ( argc );

/*
  seed random for use with bag objects
*/
  srand ( time (0));

/*
	greeting
*/
	hw4::greeting ();

	bag nouns, verbs;

/*
	reads and saves the lists of nouns and verbs from the command line
	provided file into a bag of nouns and a bag of verbs, respectively
*/
	hw4::read_file ( argv[1], nouns, verbs );

/*
	prints the nouns and verbs found in the file
*/
	std::cout << "\nNouns-> " << nouns << '\n';
	std::cout << "\nVerbs-> " << verbs << '\n';

/*
	creates two additional bags, one of adjectives and one of adverbs to
	be used to construct random sentences with the verbs and nouns and
	prints the random sentences
*/
	hw4::construct_sentences ( nouns, verbs );

/*
	print closing comments
*/
	hw4::closing ();

	return 0;
}
