#pragma once
#include <set>

#include "Common.h"
#include "CharSet.h"
#include "AttackSet.h"

class Player;

class Character 
{
protected:
	//set up variables
	CharacterEnum charEnum;
	std::string charName;
	int health;
	int basePower;
	Type charType;
	std::set<AttackEnum> moveSet;
	int numberOfMoves;
	int attackModifier = 1;
	std::string AttackName;
	AttackSet attacker = AttackSet();
	Player* master;


public:
	//Set up Public Functions
	Character();
	Character(CharacterEnum charIn);
	std::string GetName();
	void SetMaster(Player* playerMaster);
	Player* GetMaster();
	int GetHealth();
	bool CheckMove(AttackEnum moveToCheck);
	bool Attack(AttackEnum attackEnum, Character* attackTarget);
	void Defend(int attackStrength, Type attackType);
	void Die();

	//type multipliers
	double TypeMultiplier(Type attackType);
	double normalMultiplier(Type attackType);
	double fireMultiplier(Type attackType);
	double electricMultiplier(Type attackType);
	double waterMultiplier(Type attackType);
	double iceMultiplier(Type attackType);
	double silverMultiplier(Type attackType);
	double monsterMultiplier(Type attackType);
	double bloodMultiplier(Type attackType);
	double sacredMultiplier(Type attackType);

};