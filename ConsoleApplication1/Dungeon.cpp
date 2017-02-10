#include "stdafx.h"
#include "Dungeon.h"


Dungeon::Dungeon(int dungeonNumber, SaveData* playerDataIn)
{
	inputHandler = StringEvaluator(); 
	playerData = playerDataIn;

	//Set current dungeon
	playerData->SetCurrentDungeon(dungeonNumber);

	//Set up the Boss Monster
	 DungeonSet currentDungeon = dungeonTable[dungeonNumber];
	 bossMonster = currentDungeon.bossChar;
	 levelsInDungeon = currentDungeon.levelTable.size();

	 //Play each level in the world
	 int levelNum = 0;
	 bool stillPlaying;
	 do
	 {
		 levelNum = playerData->GetCurrentLevel();
		 CharacterEnum chosenChar = SelectCharacters();
		 //create level
		 LevelSet currentLevelSet = currentDungeon.levelTable[levelNum];
		 Level currentLevel = Level(currentLevelSet, chosenChar);
		 //create post game
		 PostGame postGameState = PostGame(currentLevelSet, currentLevel.playerWon, playerData);

		 stillPlaying = ContinuePlaying();

	 } while (stillPlaying && levelNum < levelsInDungeon);


}


CharacterEnum Dungeon::SelectCharacters()
{
	//print avalible characters
	std::cout << "You currently have access to the following characters: ";
	std::vector<CharacterEnum> avalibleChars = playerData->GetChars();
	for (unsigned int i = 0; i < avalibleChars.size(); i++)
	{
		//set Get Character name from table
		CharSet currentCharSet = CharTable[avalibleChars[i]];
		std::string currentName = currentCharSet.charName;
		std::cout << i + 1 << "." << currentName << ", ";
	}

	//player chooses character
	std::cout << "\nPress the number of the character you would like to use for this level.\n";
	int charChoice;
	bool invalidChoice;
	do
	{
		charChoice = inputHandler.getNum();
		int size = avalibleChars.size();
		if (charChoice > size || charChoice <= 0)
		{
			std::cout << "Invalid input, please try again\n";
			invalidChoice = true;
		}
		else
		{
			invalidChoice = false;
		}

	} while (invalidChoice);

	CharacterEnum chosenChar = avalibleChars[charChoice - 1];
	return chosenChar;
}

bool Dungeon::ContinuePlaying()
{
	bool returnBool = false;
	std::string inputString;
	std::cout << "Play next level?\n";
	std::cin >> inputString;
	if (inputHandler.isYes(inputString))
	{
		returnBool = true;
	}
	return returnBool;
}