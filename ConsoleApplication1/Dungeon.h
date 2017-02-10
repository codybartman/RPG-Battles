#pragma once
#include "Common.h"
#include "LevelSet.h"
#include "Character.h"
#include "CardDeck.h"
#include "Level.h"
#include "PostGame.h"
#include "StringEvaluator.h"
#include "SaveData.h"



class Dungeon
{
private:
	CharacterEnum  bossMonster;
	CardDeck bossDeck;
	int levelsInDungeon;
	StringEvaluator inputHandler;
	SaveData* playerData;


public:
	Dungeon(int worldNumber, SaveData* playerDataIn);
	CharacterEnum SelectCharacters();
	bool ContinuePlaying();

};

