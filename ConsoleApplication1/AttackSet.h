#pragma once
#include "Common.h"
#include <vector>
#include <string>



struct AttackSet
{
	std::string attackName;
	AttackEnum attackEnum;
	int attackPower;
	Type attackType;
};

static AttackSet attackTable[NULLATTACK + 1] = 
{
	//Attack Name	AttackEnum	
	{ "Disease",		DISEASE,		3,		BLOOD },
	{ "Fire Storm",		FIRESTORM,		30,		FIRE },
	{ "Misfortune",		MISFORTURE,		3,		BLOOD},
	{ "Tail Slash",		TAILSLASH,		1,		NORMAL },
	{ "Typhoon",		TYPHOON,		6,		WATER },
	{ "Null Attack",	NULLATTACK,		0,		NULLTYPE}
};
