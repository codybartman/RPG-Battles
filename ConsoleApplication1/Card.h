#pragma once
#include "AttackSet.h"
#include <vector>
#include <string>

class Card
{
public:
	AttackSet attackSet0 = AttackSet();
	AttackSet attackSet1 = AttackSet();
	AttackSet attackSet2 = AttackSet();
	AttackSet attackSet3 = AttackSet();

	int attackNumber;

public:
	Card();

	void SetAttacks(std::vector<AttackEnum> attacksIn);
	AttackEnum GetAttackSet(int attackNumber);
	std::string GetAttackName(int attackNumber);
};

