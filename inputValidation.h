/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Class header for Input Validation class
***************************************************************************************************/

#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class InputValid
{
private:
	string input;		// Initializes variable to empty string
	int    counter,		// Creates variable to use for counting
		   negCounter,	// Creates variable to use for negative symbol counting
		   tries;		// Creates variable to hold number of tries

public:
	InputValid();
	string isString();
	int isPosInteger();
	int isInteger();
	double isFloat();
	char isChar();
};
#endif