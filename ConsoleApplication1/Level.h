#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Common.h"
#include "StringEvaluator.h"
#include "Player.h"

class Level
{
	//potentially change these
	const int attacksPerCard = 4;
	AttackEnum attacksOnCard[4];

	//set up variables
public:
	bool playerWon;

private:
	LevelSet currentLevelSet;
	CharacterEnum chosenChar;
	StringEvaluator inputHandler;
	Player humanPlayer;
	Player opponent;
	bool humanTurn;
	Character* attackingCharacter;
	Character* defendingCharacter;
	Card* currentCard;


	//set up functions
public:
	Level(LevelSet levelSetIn, CharacterEnum choosenChar);

private:
	void Battle(Player * attackingPlayer, Player * defendingPlayer);
	bool PlayLevel();
	void ChooseAttack();
};

