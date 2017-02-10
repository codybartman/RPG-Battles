#pragma once
#include "Player.h"

Player::Player()
{
	cardDeck = CardDeck();
	numberOfChars = 0;
}

void Player::SetCharacter(Character* charPtr)
{
	character1_ptr = charPtr;
	character1_ptr->SetMaster(this);
	++numberOfChars;
}

//Get any one of the Player's characters
Character* Player::GetCharacter(int charNumber)
{
	switch (charNumber)
	{
	case 1:
		return character1_ptr;
	default:
		return character1_ptr;
	}

}

int Player::GetNumOfChars()
{
	return numberOfChars;
}

void Player::LoseCharacter(Character* lostChar)
{
	delete character1_ptr;
	--numberOfChars;
}

CardDeck* Player::GetDeck()
{
	return &cardDeck;
}

Card* Player::DrawCard()
{
	return cardDeck.DrawCard();
}