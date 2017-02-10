#include "CardGame.h"


CardGame::CardGame()
{
	std::cout << "Starting Game\n";

	inputHandler = new StringEvaluator();
	playerData = new SaveData();
	std::cout << "Gold: " << playerData->GetGold() << "\n";

	//Select Dungeon
	bool stillPlaying = true;
	do
	{
		int levelNum = SelectDungeon();
		Dungeon currentLevel = Dungeon(levelNum, playerData);

		stillPlaying = ContinuePlaying();

	} while (stillPlaying);

	//Quit game
	delete playerData;
	std::cout << "\nLeaving Game\n";
	std::cin >> inputString;

}

int CardGame::SelectDungeon()
{
	int returnInt = 0;
	bool selectionValid = false;
	int furthestDungeonUnbeat = playerData->GetFurthestDungeon();
	do
	{
		std::cout << "What Dungeon would you like to play?\n"
			<< "You can choose between 0 & " << furthestDungeonUnbeat
			<< "\n";
		//player chooses Dungeon
		std::cin >> inputString;

		//try to return an int.
		try
		{
			returnInt = std::stoi(inputString);
		}
		//if a non int was entered it will be treated as an invalid Int (666)
		catch (std::invalid_argument)
		{
			returnInt = 666;
		}

		//check input validity
		if ((returnInt >= 0) && (returnInt <= furthestDungeonUnbeat))
		{
			selectionValid = true;
		}
		else
		{
			printf("Input invalid, try again\n");
		}
	} while (!selectionValid);

	return returnInt;
}

bool CardGame::ContinuePlaying()
{
	bool returnBool = false;
	std::cout << "Would you like to continue playing?\n";
	std::cin >> inputString;
	if (inputHandler->isYes(inputString))
	{
		returnBool = true;
	}
	return returnBool;
}