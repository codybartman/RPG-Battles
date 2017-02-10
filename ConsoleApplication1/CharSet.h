#pragma once
#include <set>

#include "Common.h"


struct CharSet
{
	CharacterEnum charEnum;
	std::string charName;
	int health;
	int basePower;
	Type charType;
	std::set<AttackEnum> moveSet;
};

static CharSet CharTable[NULLCHAR + 1] =
{
	// CharEnum		CharacterName		Health	Attack	Type		AttackSet
	{ DRAUGR,		"Draugr",			200,	10,		BLOOD,		{DISEASE, TAILSLASH} },
	{ MANTICORE,	"Manticore",		100,	10,		FIRE,		{TAILSLASH, FIRESTORM} },
	{ NINGYO,		"Ningyo",			100,	10,		WATER,		{TYPHOON, TAILSLASH} },
	{ RUSALKA,		"Rusalka",			100,	10,		WATER,		{TAILSLASH, TYPHOON } },
	{ VAMPIRE,		"Vampire",			100,	10,		NORMAL,		{FIRESTORM, TYPHOON} },
	{ NULLCHAR,		"Null Character",	0,		0,		NULLTYPE }
};
