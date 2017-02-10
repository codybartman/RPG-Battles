#pragma once
#include "Card.h"
class CardDeck
{
private:
	int drawCounter;
public:
	CardDeck();
	Card* DrawCard();
	Card* CardBuilder(std::vector<AttackEnum> attacksIn);
};

