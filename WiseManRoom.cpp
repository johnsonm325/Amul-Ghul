/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Definitions of the WiseManRoom class functions
***************************************************************************************************/

#include "WiseManRoom.h"


/****************************************************************************************************
**							Creates Wise man room object with type name
****************************************************************************************************/
WiseManRoom::WiseManRoom() : Space("Wise Man Room")
{

}


/****************************************************************************************************
**							Menu function for the wise man room class
****************************************************************************************************/
int WiseManRoom::menu(vector<string> *i)
{
	// Evaluates if player is dead and exits the function
	if (firstTry == true)
	{
		firstTime();
		cout << "********************************************************************************" << endl;
		cout << "* You find yourself in a small room, lit by a single lantern. Next to the lantern," << endl;
		cout << "* you see an old, ragged man, slightly hunched over, just staring at you. He looks" << endl;
		cout << "* frail, and seems as if he has never moved in his life." << endl;
		cout << "*" << endl;
		
		cout << "* You stand for about 2 solid minutes waiting for the old man to do something, but" << endl;
		cout << "* he never does. His eyes stay fixed on you as he stands motionless." << endl << endl;
		cout << "********************************************************************************" << endl << endl;
	}

	cout << "********************************************************************************" << endl;
	cout << "* You're in the room with an old, wise man" << endl;
	cout << "*" << endl;

	cout << "* What will you do?" << endl;
	cout << "*" << endl;

	cout << "* 1: Go to the next room" << endl;
	cout << "* 2: Go back to the previous room" << endl;
	cout << "* 3: Speak with the old man" << endl;
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

	// Calls the diaglogue function based on items in inventory
	else if (choice == 3)
	{
		if (itemSearch(*i, "finalKey") == true && itemSearch(*i, "oldBoneKey") == false)
		{
			wiseManDialogue(0);
		}
		
		else if (itemSearch(*i, "finalKey") == true && itemSearch(*i, "oldBoneKey") == true)
		{
			wiseManDialogue(2);
		}

		else
		{
			if (hasBoneKey() == false)
			{
				wiseManDialogue(1);
				keyBone = true;
				return 30;
			}

			else
			{
				cout << "Come back after you've opened the chest" << endl;
			}
		}
	}

	else
	{
		return 50;
	}
}


/****************************************************************************************************
**					Sets and returns if it's the players first time in the room
****************************************************************************************************/
bool WiseManRoom::firstTime()
{
	firstTry = false;
	return firstTry;
}

/****************************************************************************************************
**					Sets up dialogue chain with wise man based on items in inventory
****************************************************************************************************/
void WiseManRoom::wiseManDialogue(int a)
{
	// If the player has the finalKey and the oldBoneKey
	if (a == 2)
	{
		cout << "Well, since that god-forsaken dragon let you by, I guess you either said all the right" << endl;
		cout << "things, or you did an awful lot of sweet talking. I'm guessing he tried to convince you" << endl;
		cout << "to change Michael's 85 to a 100? Don't listen to him! Let's be honest, Michael deserved that" << endl;
		cout << "grade." << endl << endl;

		cout << "I'm sorry you got thrown into this mess. I'm just glad you were the first to make it out alive." << endl;
		cout << "Anyway, go through the rooms right behind me. You can find your way out there." << endl << endl;

		cout << "Have a great day!" << endl << endl;
	}
	
	// If the player already has the finalKey but didn't get the oldBoneKey from the wise 
	else if (a == 0)
	{
		cout << "Ahh hello there, I see you've already unlocked the chest in the story room." << endl;
		cout << "If you had only come and talked to me first, I could have given you this old bone key" << endl;
		cout << "and you could have avoided that blasted Muk altogether." << endl << endl;

		cout << "Well, since that god-forsaken dragon let you by, I guess you either said all the right" << endl;
		cout << "things, or you did an awful lot of sweet talking. I'm guessing he tried to convince you" << endl;
		cout << "to change Michael's 85 to a 100? Don't listen to him! Let's be honest, Michael deserved that" << endl;
		cout << "grade." << endl << endl;

		cout << "I'm sorry you got thrown into this mess. I'm just glad you were the first to make it out alive." << endl;
		cout << "Anyway, go through the rooms right behind me. You can find your way out there." << endl << endl;

		cout << "Have a great day!" << endl << endl;
	}

	// If the player does not have the finalKey or the oldBoneKey
	else if (a == 1)
	{
		cout << "Hi there! I see you haven't found the key to the door behind me yet. The chest is back in the" << endl;
		cout << "story room. But here, use this old bone key to open the chest and avoid waking up Muk." << endl;
		cout << "If you thought the dragon was a bother, you'll hate Muk." << endl << endl;
	}


}


/****************************************************************************************************
**										Returns keyBone
****************************************************************************************************/
bool WiseManRoom::hasBoneKey()
{
	return keyBone;
}


/****************************************************************************************************
**							Searches passed inventory for passed item
****************************************************************************************************/
bool WiseManRoom::itemSearch(vector<string> inv, string a)
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