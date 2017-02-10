#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Common.h"
#include "Defaults.h"
#include "StringEvaluator.h"
#include "LevelSet.h"


class SaveData
{
private:
	const std::string saveFileName = "SaveFile.txt";
	std::vector<CharacterEnum> avalibleChars;
	int playerGold;
	int currentDungeon;
	int furthestDungeonUnbeat;
	int currentLevel;
	StringEvaluator* inputHandler;
	
public:
	SaveData();
	void CreateSave();
	void LoadSave();
	void AddChar(CharacterEnum charToAdd);
	void AddGold(int goldToAdd);
	bool SpendGold(int goldToSubtract);
	void SetCurrentDungeon(int currentDungeonIn);
	void BeatDungeon(int dungeonBeat);
	void BeatLevel();
	std::vector<CharacterEnum> GetChars();
	int GetGold();
	int GetCurrentDungeon();
	int GetFurthestDungeon();
	int GetCurrentLevel();
private:
	void SaveSaveData();
};

