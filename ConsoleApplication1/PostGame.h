#pragma once
#include <iostream>
#include <string>

#include "SaveData.h"
#include "LevelSet.h"


class PostGame
{
private:
	LevelSet currentLevelSet;
	bool playerWon;
	SaveData* playerData;

public:
	PostGame(LevelSet currentLevelSetIn, bool playerWonIn, SaveData* playerDataIn);
	void WinState();
	void LoseState();
};

