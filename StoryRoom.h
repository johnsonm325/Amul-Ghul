/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/16/2017
** Description: Header file for Story Room class
***************************************************************************************************/

#ifndef STORYROOM_H
#define STORYROOM_H

#include "BlankSpace.h"

class StoryRoom : public Space
{
private:
	int choice,
		attack;
	bool firstTry = true,
		 finalKey = false,
		 goneMuk = false,
		 goneEdward = false;

public:
	StoryRoom();
	int menu(vector<string>*);
	void readScroll();
	bool firstTime();
	void openChest(vector<string>);
	void setFinalKey();
	bool hasFinalKey();
	void fightMuk();
	bool mukGone();
	bool edwardGone();
	bool itemSearch(vector<string>, string);
};
#endif