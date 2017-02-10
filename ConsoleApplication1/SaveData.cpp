#include "SaveData.h"

SaveData::SaveData()
{
	inputHandler = new StringEvaluator();
	if (std::ifstream(saveFileName))
	{
		LoadSave();
	}
	else
	{
		CreateSave();
	}
}

void SaveData::CreateSave()
{
	avalibleChars.push_back(defaultChars);
	playerGold = defaultGold;
	currentDungeon = -1;
	furthestDungeonUnbeat = 0;
	currentLevel = -1;

	std::cout << "No saved data found, would you like to create a new save?\n";
	std::string playerInput;
	std::cin >> playerInput;
	if (inputHandler->isYes(playerInput))
	{
		//create saveFile
		std::ofstream saveFile (saveFileName);
		//if it's open build file, else close program
		if (saveFile.is_open())
		{
			SaveSaveData();
			saveFile.close();
		}
		else
		{
			std::cout << "Unable to open save file";
			std::cin >> playerInput;
			std::exit(0);
		}
	}
	else
	{
		std::exit(0);
	}
}

void SaveData::LoadSave()
{
	std::ifstream saveFile (saveFileName);
	if (saveFile.is_open())
	{
		//Get each property
		int propertiesNum = 3;
		int i = 0;
		std::string currentLine;
		while( std::getline(saveFile, currentLine))
		{
			switch (i)
			{
			case 0:
			{
				//create a stringstream from currentLine
				std::stringstream ss;
				ss.str(currentLine);
				//create a cell to hold elements as they come
				std::string cell;
				while (std::getline(ss, cell, ','))
				{
					//convert input string to a characterEnum
					CharacterEnum currentChar = (CharacterEnum) std::stoi(cell); 
					avalibleChars.push_back(currentChar);
				}
				break;
			}
			case 1:
				playerGold = std::stoi(currentLine);
				break;
			case 2:
				currentDungeon = std::stoi(currentLine);
				break;
			case 3:
				furthestDungeonUnbeat = std::stoi(currentLine);
				break;
			case 4:
				currentLevel = std::stoi(currentLine);
				break;
			default:
				break;
			}
			i++;
		}
		std::cout << "Save found and loaded\n";
	}
	else
	{
		std::cout << "Save is currupted";
	}
}

void SaveData::AddChar(CharacterEnum charToAdd)
{
	avalibleChars.push_back(charToAdd);
	SaveSaveData();
}

void SaveData::AddGold(int goldToAdd)
{
	playerGold += goldToAdd;
	SaveSaveData();
}

bool SaveData::SpendGold(int goldToSubtract)
{
	if (playerGold > goldToSubtract)
	{
		playerGold -= goldToSubtract;
		SaveSaveData();
		return true;
	}
	else
	{
		return false;
	}
}

void SaveData::SetCurrentDungeon(int currentDungeonIn)
{
	currentDungeon = currentDungeonIn;
	currentLevel = 0;
	SaveSaveData();
}

void SaveData::BeatDungeon(int dungeonBeat)
{
	currentDungeon = -1;
	if (dungeonBeat == furthestDungeonUnbeat)
	{
		if (dungeonBeat < (dungeonTableSize - 1))
		{
			furthestDungeonUnbeat++;
			SaveSaveData();

		}
	}
}

void SaveData::BeatLevel()
{
	currentLevel++;
	SaveSaveData();
}

std::vector<CharacterEnum> SaveData::GetChars()
{
	return avalibleChars;
}

int SaveData::GetGold()
{
	return playerGold;
}

int SaveData::GetCurrentDungeon()
{
	return currentDungeon;
}

int SaveData::GetFurthestDungeon()
{
	return furthestDungeonUnbeat;
}

int SaveData::GetCurrentLevel()
{
	return currentLevel;
}

void SaveData::SaveSaveData()
{
	//create saveFile
	std::ofstream saveFile(saveFileName);
	//if it's open build file, else close program
	if (saveFile.is_open())
	{
		//Save Characters
		for (unsigned int i = 0; i < avalibleChars.size(); i++)
		{
			if (i >= 1)
			{
				saveFile << ",";
			}
			saveFile << avalibleChars[i];
		}
		saveFile << "\n";
		//Save Gold
		saveFile << playerGold << "\n";
		//Save currentDungeon
		saveFile << currentDungeon << "\n";
		//Save furthestDungeon
		saveFile << furthestDungeonUnbeat << "\n";
		//Save currentLevel
		saveFile << currentLevel << "\n";


		std::cout << "Game Saved\n";
		saveFile.close();
	}
	else
	{
		std::cout << "Save Failed\n";
	}
}
