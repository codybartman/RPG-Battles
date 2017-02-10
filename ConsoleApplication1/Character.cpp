#pragma once
#include "Character.h"
#include "Player.h"

Character::Character()
{
	charEnum = NULLCHAR;
	charName = "Null Character";
	health = 0;
	basePower = 0;
	attackModifier = 1;
	charType = NULLTYPE;
}

Character::Character(CharacterEnum charIn)
{
	CharSet CharSetIn = CharTable[charIn];
	charEnum = charIn;
	charName = CharSetIn.charName;
	health = CharSetIn.health;
	basePower = CharSetIn.basePower;
	charType = CharSetIn.charType;
	moveSet = CharSetIn.moveSet;

}

std::string Character::GetName()
{
	return charName;
}

void Character::SetMaster(Player* playerMaster)
{
	master = playerMaster;
}

Player* Character::GetMaster()
{
	return master;
}

int Character::GetHealth()
{
	return health;
}

bool Character::CheckMove(AttackEnum moveToCheck)
{
	bool returnValue = false;
	if (moveSet.count(moveToCheck))
	{
		returnValue = true;
	}
	return returnValue;
}

bool Character::Attack(AttackEnum attackEnum, Character* attackTarget)
{
	attacker = attackTable[attackEnum];

	if (attacker.attackEnum == NULLATTACK)
	{
		return false;
	}
	int attackStrength = attacker.attackPower * basePower * attackModifier;
	Type attackType = attacker.attackType;
	attackTarget->Defend(attackStrength, attackType);
	return true;
}

void Character::Defend(int attackStrength, Type attackType)
{
	double typeEffectiveness = TypeMultiplier(attackType);
	if (typeEffectiveness > 1)
	{
		std::cout << "Attack type does bounus damage\n";
	}
	else if (typeEffectiveness < 1)
	{
		std::cout << "Defense type resists damage\n";
	}
	int attackPower = (int) (attackStrength * TypeMultiplier(attackType));
	health = health - attackPower;
	if (health <= 0)
	{
		Die();
	}
	else
	{
		std::cout << charName << " health: " << health << "\n";
	}
}


void Character::Die()
{
	std::cout << charName << " died in battle\n";
	master->LoseCharacter(this);
}

double Character::TypeMultiplier(Type attackType)
{
	if (charType == NORMAL)
	{
		return normalMultiplier(attackType);
	}
	if (charType == FIRE)
	{
		return fireMultiplier(attackType);
	}
	if (charType == ELECTRIC)
	{
		return electricMultiplier(attackType);
	}
	if (charType == WATER)
	{
		return waterMultiplier(attackType);
	}
	if (charType == ICE)
	{
		return iceMultiplier(attackType);
	}
	if (charType == SILVER)
	{
		return silverMultiplier(attackType);
	}
	if (charType == MONSTER)
	{
		return monsterMultiplier(attackType);
	}
	if (charType == BLOOD)
	{
		return bloodMultiplier(attackType);
	}
	if (charType == SACRED)
	{
		return sacredMultiplier(attackType);
	}
	else
	{
		return 0;
	}
}

double Character::normalMultiplier(Type attackType)
{
	if (attackType == MONSTER)
	{
		return 2;
	}
	else if (attackType == BLOOD)
	{
		return 2;
	}
	else if (SACRED)
	{
		return .5;
	}
	else
	{
		return 1;
	}
}

double Character::fireMultiplier(Type attackType)
{
	if (attackType == FIRE)
	{
		return .5;
	}
	if (attackType == WATER)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}
double Character::electricMultiplier(Type attackType)
{
	if (attackType == ELECTRIC)
	{
		return .5;
	}
	if (attackType == MONSTER)
	{
		return 2;
	}
	if (attackType == MONSTER)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

double Character::waterMultiplier(Type attackType)
{
	if (attackType == FIRE)
	{
		return .5;
	}
	else if (attackType == ELECTRIC)
	{
		return 2;
	}
	else if (attackType == WATER)
	{
		return .5;
	}
	else if (attackType == ICE)
	{
		return 2;
	}
	else if (attackType == BLOOD)
	{
		return .5;
	}
	else if (attackType == SACRED)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

double Character::iceMultiplier(Type attackType)
{
	if (attackType == FIRE)
	{
		return 2;
	}
	if (attackType == ICE)
	{
		return .5;
	}
	if (attackType == MONSTER)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

double Character::silverMultiplier(Type attackType)
{
	if (attackType == FIRE)
	{
		return 2;
	}
	if (attackType == ELECTRIC)
	{
		return 2;
	}
	if (attackType == SILVER)
	{
		return .5;
	}
	if (attackType == MONSTER)
	{
		return .5;
	}
	else
	{
		return 1;
	}
}

double Character::monsterMultiplier(Type attackType)
{
	if (attackType == NORMAL)
	{
		return .5;
	}
	if (attackType == ICE)
	{
		return 2;
	}
	if (attackType == SILVER)
	{
		return 2;
	}
	if (attackType == SACRED)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

double Character::bloodMultiplier(Type attackType)
{
	if (attackType == SILVER)
	{
		return 2;
	}
	if (attackType == MONSTER)
	{
		return .5;
	}
	if (attackType == SACRED)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

double Character::sacredMultiplier(Type attackType)
{
	if (attackType == NORMAL)
	{
		return 2;
	}
	if (attackType == MONSTER)
	{
		return 2;
	}
	if (attackType == BLOOD)
	{
		return 2;
	}
	if (attackType == SACRED)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
