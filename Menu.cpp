/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Definitions of the menu class functions
***************************************************************************************************/

#include "Menu.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/****************************************************************************************************
**                                         displayMenu
**                       Displays the menu of game options on the screen.
**                        I pulled this function idea from the textbook.
****************************************************************************************************/
void Menu::displayMenu()
{
	cout << "\tAmul Ghul" << endl;
	cout << "1: Play game" << endl;
	cout << "2: Exit" << endl;
	cout << endl;
}


/****************************************************************************************************
**                                          setChoice
**                              Sets the menu choice from the user
****************************************************************************************************/
void Menu::setChoice()
{
	do
	{
		cout << "Choose an option: " << endl;
		choice = inputVal1.isPosInteger();
	} while (choice > 2 || choice < 1);
}


/****************************************************************************************************
**                                          getChoice
**                       Gets the menu choice from the user and returns it
****************************************************************************************************/
int Menu::getChoice()
{
	return choice;
}
