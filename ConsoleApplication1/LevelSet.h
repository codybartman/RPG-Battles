#pragma once
#include "Common.h"
#include "Character.h"
#include "CardDeck.h"

struct LevelSet
{
	CharacterEnum levelChar;
	int charChance;
	int cardChance;
	std::vector<AttackEnum> CardtoWin;
};

struct DungeonSet
{
	CharacterEnum bossChar;
	int bChance;
	int bCardChance;
	std::vector<AttackEnum> bCardtoWin;
	std::vector<LevelSet> levelTable;
};

static DungeonSet dungeonTable[] = 
{
	//Boss		Char%	Card%	Dungeon Card
	{VAMPIRE,	10,		50,		{MISFORTURE,	FIRESTORM},
	{
		//MMon			Char%	Card%	Level Card
		{ MANTICORE,	10,		50,		{ TAILSLASH,		FIRESTORM } },
		{ NINGYO,		10,		50,		{ TYPHOON,			MISFORTURE } },
		{ RUSALKA,		90,		10,		{ TAILSLASH,		FIRESTORM } },
		{ VAMPIRE,		10,		50,		{ TAILSLASH,		FIRESTORM } },
		{ MANTICORE,	10,		50,		{ TAILSLASH,		FIRESTORM } }
	}}
	
};

static int dungeonTableSize = (sizeof(dungeonTable) / sizeof(dungeonTable[0]));