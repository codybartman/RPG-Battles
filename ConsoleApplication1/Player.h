#pragma once
#include "LevelSet.h"

class Player
{
	CardDeck cardDeck;
	int numberOfChars;
	Character* character1_ptr;

	
public:
	Player();
	void SetCharacter(Character* charPtr);
	CardDeck* GetDeck();
	Card* DrawCard();
	Character* GetCharacter(int charNumber);
	int GetNumOfChars();
	void LoseCharacter(Character* lostChar);
};

