/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Definitions of the FinalRoom class functions
***************************************************************************************************/

#include "FinalRoom.h"


/****************************************************************************************************
**							Creates final room object with type name
****************************************************************************************************/
FinalRoom::FinalRoom() : Space("Final Room")
{

}


/****************************************************************************************************
**							Menu function for the final room class
****************************************************************************************************/
int FinalRoom::menu(vector<string> *i)
{
	// If the trash item is in the player's inventory
	if (itemSearch(*i, "trash"))
	{
		trashBool = true;
	}

	// Evaluates if player is dead and exits the function
	if (firstTry == true)
	{
		firstTime();
		cout << "********************************************************************************" << endl;
		cout << "* As you enter the room, you notice a door on the other end and a set of folded" << endl;
		cout << "* towels laying in the corner of the room. In the center of the room is a pile" << endl;
		cout << "* of trash." << endl;
		cout << "********************************************************************************" << endl << endl;
	}

	/*************************************************
	* If the door is not open, then print the menu
	* with the option to open the door
	*************************************************/
	if (doorOpen() == false)
	{
		// If the player has not picked up the trash
		if (isTrash() == false)
		{
			cout << "********************************************************************************" << endl;
			cout << "* You're in the room with a door" << endl;
			cout << "*" << endl;

			cout << "* What will you do?" << endl;
			cout << "*" << endl;

			cout << "* 1: Open the door" << endl;
			cout << "* 2: Go back to the previous room" << endl;
			cout << "* 3: Pick up the trash" << endl;
			cout << "* 4: Clean off with the towels" << endl;
			cout << "* 5: Exit game" << endl;
			cout << "********************************************************************************" << endl;
			cout << endl;

			do
			{
				cout << "Choose an option: " << endl;
				choice = inputVal1.isPosInteger();
			} while (choice > 5 || choice < 1);

			if (choice == 1)
			{
				// Search for the finalKey and open the door
				if (itemSearch(*i, "finalKey"))
				{
					cout << "You opened the door!" << endl;
					openDoor = true;
					return 70;
				}
				else
				{
					cout << "The door is locked. You need a key" << endl;
				}
			}

			else if (choice == 2)
			{
				return 2;
			}

			// Adds trash to the inventory
			else if (choice == 3)
			{
				return 60;
			}

			else if (choice == 4)
			{
				cout << "You clean off the dirt and grime from your face and arms" << endl;
			}

			else
			{
				return 50;
			}
		}


		/*************************************************
		* If the trash has been picked up, print a menu
		* with the option to pick up trash, removed
		*************************************************/
		else if (isTrash() == true)
		{
			cout << "********************************************************************************" << endl;
			cout << "* You're in the room with a door" << endl;
			cout << "*" << endl;

			cout << "* What will you do?" << endl;
			cout << "*" << endl;

			cout << "* 1: Open the door" << endl;
			cout << "* 2: Go back to the previous room" << endl;
			cout << "* 3: Clean off with the towels" << endl;
			cout << "* 4: Exit game" << endl;
			cout << "********************************************************************************" << endl;
			cout << endl;

			do
			{
				cout << "Choose an option: " << endl;
				choice = inputVal1.isPosInteger();
			} while (choice > 4 || choice < 1);

			if (choice == 1)
			{
				if (itemSearch(*i, "finalKey"))
				{
					cout << "You opened the door!" << endl;
					openDoor = true;
					return 70;
				}
				else
				{
					cout << "The door is locked. You need a key" << endl;
				}
			}

			else if (choice == 2)
			{
				return 2;
			}

			else if (choice == 3)
			{
				cout << "You clean off the dirt and grime from your face and arms" << endl;
			}

			else
			{
				return 50;
			}
		}
	}

	/*************************************************
	* If the door is open, then print menu giving
	* the player an option to exit the dungeon
	*************************************************/
	else if (doorOpen() == true)
	{
		// If the trash has not been picked up yet
		if (isTrash() == false)
		{
			cout << "********************************************************************************" << endl;
			cout << "* You're in the room with a door" << endl;
			cout << "*" << endl;

			cout << "* What will you do?" << endl;
			cout << "*" << endl;

			cout << "* 1: Exit the dungeon" << endl;
			cout << "* 2: Go back to the previous room" << endl;
			cout << "* 3: Pick up the trash" << endl;
			cout << "* 4: Clean off with the towels" << endl;
			cout << "* 5: Exit game" << endl;
			cout << "********************************************************************************" << endl;
			cout << endl;

			do
			{
				cout << "Choose an option: " << endl;
				choice = inputVal1.isPosInteger();
			} while (choice > 5 || choice < 1);

			if (choice == 1)
			{
				if (doorOpen() == true)
				{
					// If the trash is picked up, then print message thanking player for cleaning up
					if (isTrash())
					{
						cout << "Thanks for cleaning up!" << endl;
						return 1;
					}
					return 1;
				}
			}

			else if (choice == 2)
			{
				return 2;
			}

			else if (choice == 3)
			{
				return 60;
			}

			else if (choice == 4)
			{
				cout << "You clean off the dirt and grime from your face and arms" << endl;
			}

			else
			{
				return 50;
			}
		}

		/*************************************************
		* If the player has picked up the trash
		*************************************************/
		else if (isTrash() == true)
		{
			cout << "********************************************************************************" << endl;
			cout << "* You're in the room with a door" << endl;
			cout << "*" << endl;

			cout << "* What will you do?" << endl;
			cout << "*" << endl;

			cout << "* 1: Exit the dungeon" << endl;
			cout << "* 2: Go back to the previous room" << endl;
			cout << "* 3: Clean off with the towels" << endl;
			cout << "* 4: Exit game" << endl;
			cout << "********************************************************************************" << endl;
			cout << endl;

			do
			{
				cout << "Choose an option: " << endl;
				choice = inputVal1.isPosInteger();
			} while (choice > 4 || choice < 1);

			if (choice == 1)
			{
				if (doorOpen() == true)
				{
					if (isTrash())
					{
						cout << "Thanks for cleaning up!" << endl;
						return 1;
					}
					return 1;
				}
			}

			else if (choice == 2)
			{
				return 2;
			}

			else if (choice == 3)
			{
				cout << "You clean off the dirt and grime from your face and arms" << endl;
			}

			else
			{
				return 50;
			}
		}
	}
}


/****************************************************************************************************
**					Sets and returns if it's the players first time in the room
****************************************************************************************************/
bool FinalRoom::firstTime()
{
	firstTry = false;
	return firstTry;
}


/****************************************************************************************************
**						Returns openDoor to determine if the door is open
****************************************************************************************************/
bool FinalRoom::doorOpen()
{
	return openDoor;
}


/****************************************************************************************************
**					Returns trashBool to determine if the trash has been picked up
****************************************************************************************************/
bool FinalRoom::isTrash()
{
	return trashBool;
}


/****************************************************************************************************
**							Searches passed inventory for passed item
****************************************************************************************************/
bool FinalRoom::itemSearch(vector<string> inv, string a)
{
	for (int i = 0; i < inv.size(); i++)
	{
		if (a == inv[i])
		{
			return true;
		}
	}
	return false;
}