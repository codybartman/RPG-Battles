#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Dungeon.h"

class CardGame
{
private:
	//set up variables
	SaveData* playerData;
	StringEvaluator* inputHandler;

	std::string inputString;
	
	//set up functions
	bool ContinuePlaying();
	int SelectDungeon();

public:
	CardGame();

};

