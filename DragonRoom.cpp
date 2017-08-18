/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Definitions of the menu class functions
***************************************************************************************************/

#include "DragonRoom.h"

/****************************************************************************************************
**							Creates dragon room object with type name
****************************************************************************************************/
DragonRoom::DragonRoom() : Space("Dragon Room")
{

}


/****************************************************************************************************
**							Menu function for the dragon room class
****************************************************************************************************/
int DragonRoom::menu(vector<string> *i)
{
	// Evaluates if player is dead and exits the function
	if (edwardGone())
	{
		return 40;
	}
	
	// Prints the first time the room is visited
	if (firstTry == true)
	{
		firstTime();
		cout << "********************************************************************************" << endl;
		cout << "* You enter a cavernous room, most of which is taken up by an enourmous dragon." << endl;
		cout << "* His head reaches the full height of the cavern as he stares down at you, smiling." << endl;
		cout << "* You suddenly realize where the stench is coming from. This dragon has been" << endl;
		cout << "* here as long as the cavern has, and clearly has never had a bath." << endl;
		cout << "********************************************************************************" << endl << endl;
	}
	

	/*************************************************
	* If the dragon is not gone, then you have menu
	* options to speak with the dragon or fight
	* the dragon.
	*************************************************/
	if (goneDragon == false)
	{
		cout << "********************************************************************************" << endl;
		cout << "* You're in the dragon room" << endl;
		cout << "*" << endl;

		cout << "* What will you do?" << endl;
		cout << "*" << endl;

		cout << "* 1: Go to the next room" << endl;
		cout << "* 2: Go back to the previous room" << endl;
		cout << "* 3: Speak with the dragon" << endl;
		cout << "* 4: Fight the dragon" << endl;
		cout << "* 5: Exit game" << endl;
		cout << "********************************************************************************" << endl;
		cout << endl;

		do
		{
			cout << "Choose an option: " << endl;
			choice = inputVal1.isPosInteger();
		} while (choice > 5 || choice < 1);

		// Cannot escape the room until you interact with the dragon
		if (choice == 1)
		{
			cout << "You can't escape" << endl;
		}

		else if (choice == 2)
		{
			cout << "You can't escape" << endl;
		}

		// Calls function to talk with the dragon
		else if (choice == 3)
		{
			dragonDialogue();
		}

		// Calls function to fight the dragon
		else if (choice == 4)
		{
			fightDragon();
		}

		else
		{
			return 50;
		}
	}


	/*************************************************
	* If the dragon is gone, then there will be an
	* object to inspect on the ground, and the 
	* dragon options will not be on the menu
	*************************************************/
	else
	{
		cout << "********************************************************************************" << endl;
		cout << "* What will you do?" << endl;
		cout << "*" << endl;

		cout << "* 1: Go to the next room" << endl;
		cout << "* 2: Go back to the previous room" << endl;
		cout << "* 3: Inspect the object on the ground" << endl;
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
			return 1;
		}

		else if (choice == 2)
		{
			return 2;
		}

		else if (choice == 3)
		{
			// If you have the key, then you are informed that you already have it
			if (hasAKey())
			{
				cout << "You've already inspected this area and grabbed the key" << endl;
			}

			// Otherwise you call the function and return 20
			else
			{
				pickUpKey();
				return 20;
			}
		}
		
		else
		{
			return 50;
		}
	}
}


/****************************************************************************************************
**					Sets and returns if it's the players first time in the room
****************************************************************************************************/
bool DragonRoom::firstTime()
{
	firstTry = false;
	return firstTry;
}


/****************************************************************************************************
**								Sets up dialogue chain with Dragon
****************************************************************************************************/
void DragonRoom::dragonDialogue()
{
	/*************************************************
	* Question 1
	*************************************************/
	
	cout << "Hi, my name is Dragon! You must be Sir Edward Francis III, that TA that the boss" << endl;
	cout << "Michael Johnson has told me so much about. Is that right?" << endl;
	
	cout << "1: Yes" << endl;
	cout << "2: No" << endl;
	cout << endl;

	do
	{
		cout << "Choose an option: " << endl;
		choice = inputVal1.isPosInteger();
	} while (choice > 2 || choice < 1);

	if (choice == 1)
	{
		questOne = true;
	}


	/*************************************************
	* Question 2
	*************************************************/
	
	// Response if the character says they are Edward
	if (questOne)
	{
		cout << "Excellent! I tried to tell him that you were a nice guy." << endl;
		cout << "Heck! You helped him get his doubly-linked circular queue list working." << endl;
		cout << "Whatever that is." << endl << endl;

		cout << "He's a little upset that you gave him an 85 on one of his labs." << endl;
		cout << "Any chance you could recalculate that grade?" << endl << endl;

		cout << "1: Yes" << endl;
		cout << "2: No" << endl;
		cout << endl;

		do
		{
			cout << "Choose an option: " << endl;
			choice = inputVal1.isPosInteger();
		} while (choice > 2 || choice < 1);

		if (choice == 1)
		{
			questTwo = true;
		}
	}

	// Response if the character says they are not Edward
	else
	{
		cout << "You're not? Then why does your nametag say that you are?" << endl;
		cout << "Are you here to talk to the old wise man?" << endl;

		cout << "1: Yes" << endl;
		cout << "2: No" << endl;
		cout << endl;

		do
		{
			cout << "Choose an option: " << endl;
			choice = inputVal1.isPosInteger();
		} while (choice > 2 || choice < 1);

		if (choice == 1)
		{
			questTwo = true;
		}
	}


	/*************************************************
	* Question 3
	*************************************************/
	
	// If the first two answers are yes, then this question is asked
	if (questOne && questTwo)
	{
		cout << "That's great! Just move on past and talk to the wise old man, he'll help you" << endl;
		cout << "straighten everything out. Sound like plan?" << endl << endl;

		cout << "1: Yes" << endl;
		cout << "2: No" << endl;
		cout << endl;

		do
		{
			cout << "Choose an option: " << endl;
			choice = inputVal1.isPosInteger();
		} while (choice > 2 || choice < 1);

		if (choice == 1)
		{
			questThree = true;
		}
	}

	// If both answers are false, then this question is asked
	else if (questOne && questTwo == false)
	{
		cout << "Well, that's not nice. I guess I'm going to have to kill you now." << endl;
		cout << "Are you sure you don't want to reconsider?" << endl;

		cout << "1: Yes" << endl;
		cout << "2: No" << endl;
		cout << endl;

		do
		{
			cout << "Choose an option: " << endl;
			choice = inputVal1.isPosInteger();
		} while (choice > 2 || choice < 1);

		if (choice == 1)
		{
			questThree = true;
		}
	}

	// If one is yes and one is no, then this question is asked
	else
	{
		cout << "I guess I'm going to have to kill you now." << endl;
		cout << "Are you sure you don't want to reconsider?" << endl;

		cout << "1: Yes" << endl;
		cout << "2: No" << endl;
		cout << endl;

		do
		{
			cout << "Choose an option: " << endl;
			choice = inputVal1.isPosInteger();
		} while (choice > 2 || choice < 1);

		if (choice == 1)
		{
			questThree = true;
		}
	}


	// If all three answers are yes, then the dragon evaporates and is set to gone
	if (questOne == true && questTwo == true && questThree == true)
	{
		cout << "Wait what's happening!? It looks like my destiny is fulfilled" << endl;
		cout << "It appears the dragon evaporated into thin air!" << endl;
		goneDragon = true;
	}

	// Or else the dragon will fight you
	else
	{
		cout << "Oh well, I'm going to kill you anyway." << endl;
		fightDragon();
	}
}


/****************************************************************************************************
**						Fight Dragon. Used battle system from project three
****************************************************************************************************/
void DragonRoom::fightDragon()
{
	Dragon dragon;
	
	int playerTurn = rand() % 2 + 1;
	int roundNumber = 1;

	if (playerTurn == 1)
	{
		cout << "Sir Edward Francis III goes first" << endl << endl;
		// Starts do/while loop that ends when one player's strength points goes below 1
		do
		{
			cout << "**********************************************" << endl;
			cout << "Round number: " << roundNumber << endl;
			cout << "**********************************************" << endl << endl;
			cout << "Sir Edward Francis III: " << endl;
			cout << character.getType() << " ";
			// Player 1 attacks and stores in variable
			attack = character.attack();
			cout << dragon.getType() << " ";
			// Player 2 defends against attack
			dragon.defend(attack);
			// Prints remaining strength points of player 2
			if (dragon.getHitPoints() < 0)
			{
				cout << dragon.getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << dragon.getType() << " has " << dragon.getHitPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			// Breaks to the end of the loop if strength is below 1
			if (dragon.getHitPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Sir Edward Francis III won" << endl;
				cout << "Sir Edward Francis III drinks a potion and regains his full health" << endl << endl;
				goneDragon = true;
				break;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			cout << "Dragon: " << endl;
			cout << dragon.getType() << " ";
			// Player 2 attacks and stores in variable
			attack = dragon.attack();
			cout << character.getType() << " ";
			// Player 1 defends against attack
			character.defend(attack);
			// Prints remaining strength points of player 1
			if (character.getHitPoints() < 0)
			{
				cout << character.getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << character.getType() << " has " << character.getHitPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			// Breaks to the end of the loop if strength is below 1
			if (character.getHitPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Dragon won" << endl << endl;
				goneEdward = true;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			// Increments round number
			roundNumber++;
		} while (character.getHitPoints() > 0 && dragon.getHitPoints() > 0);
	}

	// Same as do/while loop above, but in reverse, allowing player 2 to go first
	if (playerTurn == 2)
	{
		cout << "Dragon goes first" << endl << endl;
		do
		{
			cout << "**********************************************" << endl;
			cout << "Round number: " << roundNumber << endl;
			cout << "**********************************************" << endl << endl;
			cout << "Dragon: " << endl;
			cout << dragon.getType() << " ";
			attack = dragon.attack();
			cout << character.getType() << " ";
			character.defend(attack);
			if (character.getHitPoints() < 0)
			{
				cout << character.getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << character.getType() << " has " << character.getHitPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			if (character.getHitPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Dragon won" << endl << endl;
				goneEdward = true;
				break;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			cout << "Sir Edward Francis III: " << endl;
			cout << character.getType() << " ";
			attack = character.attack();
			cout << dragon.getType() << " ";
			dragon.defend(attack);
			if (dragon.getHitPoints() < 0)
			{
				cout << dragon.getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << dragon.getType() << " has " << dragon.getHitPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			if (dragon.getHitPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Sir Edward Francis III won" << endl;
				cout << "Sir Edward Francis III drinks a potion and regains his full health" << endl << endl;
				goneDragon = true;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			roundNumber++;
		} while (character.getHitPoints() > 0 && dragon.getHitPoints() > 0);
	}
}


/****************************************************************************************************
**										Returns Dragon status
****************************************************************************************************/
bool DragonRoom::dragonGone()
{
	return goneDragon;
}


/****************************************************************************************************
**										Returns Edward status
****************************************************************************************************/
bool DragonRoom::edwardGone()
{
	return goneEdward;
}


/****************************************************************************************************
**										Sets aKey to true
****************************************************************************************************/
void DragonRoom::pickUpKey()
{
	cout << "As you get closer, you notice that the glinting item is a key." << endl;
	cout << "It seems the dragon left it behind." << endl;
	cout << endl;
	cout << "You added the key to your inventory!" << endl;

	aKey = true;
}


/****************************************************************************************************
**										Returns aKey
****************************************************************************************************/
bool DragonRoom::hasAKey()
{
	return aKey;
}