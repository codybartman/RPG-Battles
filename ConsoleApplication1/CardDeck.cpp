#include "stdafx.h"
#include "CardDeck.h"


CardDeck::CardDeck()
{
	drawCounter = 1;
}

Card* CardDeck::DrawCard()
{
	Card* returnCard;
	std::vector<AttackEnum> AttacksIn;
	switch (drawCounter)
	{
	case 1:
		AttacksIn = { DISEASE, FIRESTORM, TAILSLASH, TYPHOON };
		returnCard = CardBuilder(AttacksIn);
		break;
	case 2:
		AttacksIn = { DISEASE, FIRESTORM, TAILSLASH, TYPHOON };
		returnCard = CardBuilder(AttacksIn);
		break;
	default:
		AttacksIn = { TYPHOON, FIRESTORM, DISEASE, NULLATTACK };
		returnCard = CardBuilder(AttacksIn);
		drawCounter = 0;
		break;
	};
	++drawCounter;
	return returnCard;
}

Card* CardDeck::CardBuilder(std::vector<AttackEnum> attacksIn)
{

	Card* returnCard = new Card();
	returnCard->SetAttacks(attacksIn);
	return returnCard;
}