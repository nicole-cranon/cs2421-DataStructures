/*
	nicole cranon <nicole.cranon@ucdenver.edu>
	csci 2421, fall 2013
	homework 5 - sets and set operations
	hw5functions.h
	the homework 5 namespace ( hw5functions ) contains the functions used 
	in the driver hw5. contained in the hw5functions namespace:
		-greeting, displays a brief description of the hw5 program
		-check args function, checks that there have been enough
		 arguments provided at the command line to proceed with the
		 program
		-read file, reads the contents of the file and saves them
		-closing, which displays closing comments
*/


#include "set.h"


#ifndef _HW5
#define _HW5


namespace hw5functions
{
/*
	precondition:	none
	postcondition:	displays a brief description of the program
*/
	void greeting ();

/*
        precondition:   the number of arguments provided at the command line
	postcondition:	halts the program if the filename was not provided at
			the command line
*/
	void check_args ( unsigned );

/*
	precondition:	the name of the file and three sets
	postcondition:	populates the three sets with the contents of the file
			provided at the command line
*/
	template <typename val_t>
	void read_file ( char *, set<val_t>&, set<val_t>&, set<val_t>& );

/*
	precondition:	none
	postcondition:	displays closing comments 
*/
	void closing ();
}

namespace hw5 = hw5functions;

#include "hw5functions.tem.h"


#endif
