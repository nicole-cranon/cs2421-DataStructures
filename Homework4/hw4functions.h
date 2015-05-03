/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 4 - linked list based bag
	hw4functions.h
	this file contains the global namespace hw4functions used in the driver
	hw4.cpp. contained in the hw4functions namespace:
		-greeting function that presents a descripton of the program
		-check args function checks that enough arguments were 
		 provided at the command line
		-read file function to read and store the contents of the 
		 file
		-a function construct sentences with the stored file input
		-a function to display closing comments
*/


#include "bag.h"

#ifndef _HW4
#define _HW4

namespace hw4functions
{
/*
	precondition:	none
	postcondition:	displays a brief description of the program
*/
	void greeting ();

/*
	precondition:	the number of arguments provided at the command line
	postcondition:	halts the program if enough command line arguments
			were not provided
*/
	void check_args ( int );

/*
	precondition:	the name of the file provided at the command line, 
			and two bags
	postcondition:	creates two lists from the nouns and verbs within the
			file
*/
	void read_file ( char*, bag&, bag& );

/*
	precondition:	bag of nouns and bag of verbs
	postcondition:	prints 5 sentences randomly constructed
*/
	void construct_sentences ( const bag&, const bag& );

/*
	precondition:	none
	postcondition:	displays closing comments
*/
	void closing ();
}

namespace hw4 = hw4functions;


#endif
