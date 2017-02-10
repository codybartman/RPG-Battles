#include "stdafx.h"
#include "Card.h"


Card::Card()
{
	
}

void Card::SetAttacks(std::vector<AttackEnum> attacksIn)
{
	attackSet0 = attackTable[attacksIn[0]];
	attackSet1 = attackTable[attacksIn[1]];
	attackSet2 = attackTable[attacksIn[2]];
	attackSet3 = attackTable[attacksIn[3]];
}

AttackEnum Card::GetAttackSet(int attackNumber)
{
	switch (attackNumber)
	{
	case 0:
		return attackSet0.attackEnum;
	case 1:
		return attackSet1.attackEnum;
	case 2:
		return attackSet2.attackEnum;
	case 3:
		return attackSet3.attackEnum;
	default:
		return NULLATTACK;
	}
}

std::string Card::GetAttackName(int attackNumber)
{
	switch (attackNumber)
	{
	case 0:
		return attackSet0.attackName;
	case 1:
		return attackSet1.attackName;
	case 2:
		return attackSet2.attackName;
	case 3:
		return attackSet3.attackName;
	default:
		return "Null Attack";
	}
}
