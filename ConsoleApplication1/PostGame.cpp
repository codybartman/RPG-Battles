#include "stdafx.h"
#include "PostGame.h"


PostGame::PostGame(LevelSet currentLevelSetIn, bool playerWonIn, SaveData* playerDataIn)
{
	playerData = playerDataIn;
	currentLevelSet = currentLevelSetIn;
	playerWon = playerWonIn;
	if (playerWon)
	{
		WinState();
	}
	else
	{
		LoseState();
	}
}

void PostGame::WinState()
{
	std::cout << "You WIN!\n";
	int randomNumber = rand() % 100 + 1;
	if (randomNumber < currentLevelSet.charChance)
	{
		CharacterEnum charWon = currentLevelSet.levelChar;
		CharSet CharSetWon = CharTable[charWon];
		playerData->AddChar(charWon);
		std::cout << "You caught a " << CharSetWon.charName << "!\n";
	}
	else if (randomNumber < currentLevelSet.cardChance)
	{
		std::cout << "You learned a new strategy!\n"
			<< "Card earned\n";

	}
	else
	{
		playerData->AddGold(randomNumber);
		std::cout << "You earned " << randomNumber << " gold!\n";
	}
	playerData->BeatLevel();
}

void PostGame::LoseState()
{
	std::cout << "You LOSE\n";
}
