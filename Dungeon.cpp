/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Definitions of the Dungeon class functions
***************************************************************************************************/

#include "Dungeon.h"


/****************************************************************************************************
**							Creates dungeon object by creating linked list
****************************************************************************************************/
Dungeon::Dungeon()
{
	Space *temp = new BlankSpace();
	front = rear = temp;
	addBack('t');	// Add story room
	addBack('e');	// Add empty room
	addBack('d');	// Add dragon room
	addBack('e');	// Add empty room
	addBack('w');	// Add wise man room
	addBack('e');	// Add empty room
	addBack('f');	// Add final room
	rear = front;
}


/****************************************************************************************************
**								Destructs the list by traversing
****************************************************************************************************/
Dungeon::~Dungeon()
{
	// Temp pointer used for traversing the list
	Space *traverse = front;

	// Loops through the list while the temp pointer doesn't equal the rear pointer
	while (traverse->getForward() != NULL)
	{
		// Temp pointer used for deleting memory, set equal to wherever traverse pointer is
		Space *garbage = traverse;
		// Moves through the list by pointing to next and deletes the memory
		traverse = traverse->getForward();
		delete garbage;
	}
	// Deletes the final memory at rear
	delete traverse;
}


/****************************************************************************************************
**					Starts the game by printing text on screen and calls playGame
****************************************************************************************************/
void Dungeon::beginGame()
{
	cout << "Your students, angry with their grades, have banished you to Amul-Ghul, a dungeon rife with" << endl;
	cout << "an ancient dragon and other unknown creatures. In order to escape, you, Sir Edward Francis III" << endl;
	cout << "must find a way to the end of the dungeon and escape through the locked door. And, you must" << endl;
	cout << "do it in 16 steps or less." << endl << endl;
	cout << "Your only way is forward." << endl << endl;

	cout << "Will you enter into the dungeon?" << endl << endl;

	do
	{
		cout << "Enter y for Yes, or n for No" << endl;
		cin >> input;
	} while (input != 'y' && input != 'n');

	cout << endl;

	if (input == 'y')
	{
		int result = playGame();
	}
}


/****************************************************************************************************
**			Plays game by moving player through list until the last item is reached an passed
****************************************************************************************************/
int Dungeon::playGame()
{
	cin.get();
	
	// Do all of this while the players position is not pointing to a NULL value
	while (rear != NULL)
	{
		/*************************************
		** Prints room ahead and behind
		*************************************/
		if (rear->getBack() == NULL)
		{
			cout << "The " << rear->getForward()->getType() << " is in front of you" << endl << endl;
		}
		
		else if (rear->getForward() == NULL)
		{
			cout << "The " << rear->getBack()->getType() << " is behind you" << endl << endl;
		}

		else
		{
			cout << "The " << rear->getForward()->getType() << " is in front of you" << endl;
			cout << "The " << rear->getBack()->getType() << " is behind you" << endl << endl;
		}

		/*************************************
		** Prints menu for room
		*************************************/
		choice = rear->menu(&inventory);

		cout << endl;
		

		/*************************************
		** Edward dies during a monster battle
		*************************************/
		if (choice == 40)
		{
			cout << "****************************" << endl;
			cout << "You were killed!" << endl;
			cout << "****************************" << endl << endl;
			return 0;
		}

		/*************************************
		** User chooses to exit the game
		*************************************/
		if (choice == 50)
		{
			return 0;
		}
		
		else
		{
			// The chest in the Story Room is opened
			if (choice == 10)
			{
				addItem("finalKey");
			}

			// The chest in the Dragon Room is opened
			if (choice == 20)
			{
				addItem("aKey");
			}

			// The wise man give you the oldBoneKey
			if (choice == 30)
			{
				addItem("oldBoneKey");
			}

			// You pick up the trash in the final room
			if (choice == 60)
			{
				addItem("trash");
			}

			// Remove the finalKey when final door is opened
			if (choice == 70)
			{
				removeItem("finalKey");
			}

			// Move the character forward one space by calling moveForward function
			if (choice == 1)
			{
				moveForward();
				steps++;
			}

			// Move the character back one space by calling moveBack function
			else if (choice == 2)
			{
				moveBack();
				steps++;
			}
			/*************************************
			** Scenario for too many steps
			*************************************/
			if (steps > 16)
			{
				cout << "You took too long to make it through the dungeon. You died." << endl;
				cout << "Game over" << endl;
				return 0;
			}
		}
	}

	/*************************************
	** Win condition
	*************************************/
	cout << "Congratulations! You escaped the Dungeon!" << endl;
	cout << "Game Over" << endl;
	return 0;
}

/****************************************************************************************************
**				Adds a value to the back of the list. Same set up as QueueList
****************************************************************************************************/
void Dungeon::addBack(char a)
{
	
	if (a == 't')
	{
		Space *temp = new StoryRoom();
		rear->setForward(temp);
		temp->setBack(rear);
		rear = temp;
		rear->setForward(NULL);
		front->setBack(NULL);
	}

	else if (a == 'd')
	{
		Space *temp = new DragonRoom();
		rear->setForward(temp);
		temp->setBack(rear);
		rear = temp;
		rear->setForward(NULL);
		front->setBack(NULL);
	}

	else if (a == 'w')
	{
		Space *temp = new WiseManRoom();
		rear->setForward(temp);
		temp->setBack(rear);
		rear = temp;
		rear->setForward(NULL);
		front->setBack(NULL);
	}

	else if (a == 'e')
	{
		Space *temp = new BlankSpace();
		rear->setForward(temp);
		temp->setBack(rear);
		rear = temp;
		rear->setForward(NULL);
		front->setBack(NULL);
	}

	else if (a == 'f')
	{
		Space *temp = new FinalRoom();
		rear->setForward(temp);
		temp->setBack(rear);
		rear = temp;
		rear->setForward(NULL);
		front->setBack(NULL);
	}
}


/****************************************************************************************************
**				Moves the player forward by setting rear to point to next node
****************************************************************************************************/
Space *Dungeon::moveForward()
{
	rear = rear->getForward();
	return rear;
}


/****************************************************************************************************
**				Moves the player back by setting rear to point to previous node
****************************************************************************************************/
Space *Dungeon::moveBack()
{
	// If you are in the first room
	if (rear->getBack() == NULL)
	{
		cout << "You can't go back." << endl;
	}
	else
	{
		rear = rear->getBack();
		return rear;
	}
}

/****************************************************************************************************
**				Adds an item to the inventory, as long as it's less than 4 items
****************************************************************************************************/
void Dungeon::addItem(string i)
{
	if (inventory.size() > 2)
	{
		cout << "You do not have enough space in your inventory" << endl;
	}

	else
	{
		inventory.push_back(i);
	}
}


/****************************************************************************************************
**				Removes item in the inventory to make space for new item
****************************************************************************************************/
void Dungeon::removeItem(string a)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (a == inventory[i])
		{
			inventory.pop_back();
		}
	}
}


/****************************************************************************************************
**							Searches for item in the inventory
****************************************************************************************************/
bool Dungeon::itemSearch(string a)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (a == inventory[i])
		{
			return true;
		}
	}
	return false;
}