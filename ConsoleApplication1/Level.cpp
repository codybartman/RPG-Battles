#include "stdafx.h"
#include "Level.h"


Level::Level(LevelSet levelSetIn, CharacterEnum chosenCharIn)
{
	currentLevelSet = levelSetIn;
	chosenChar = chosenCharIn;
	inputHandler = StringEvaluator();
	playerWon = PlayLevel();
}

bool Level::PlayLevel()
{

	//Set up first player
	Character* charPtr = new Character(chosenChar);
	humanPlayer = Player();
	humanPlayer.SetCharacter(charPtr);

	//Set up second player
	charPtr = new Character(currentLevelSet.levelChar);
	opponent = Player();
	opponent.SetCharacter(charPtr);

	std::cout << "Your Characters:";
	std::cout << humanPlayer.GetCharacter(1)->GetName();
	std::cout << "\n\n";

	std::cout << "Enemy Characters:";
	std::cout << opponent.GetCharacter(1)->GetName();
	std::cout << "\n\n";

	//Take turns until a winner is decided
	humanTurn = true;
	do
	{
		if (humanTurn == true)
		{
			std::cout << "\n~~~~~~~~~~~~~~~~~~~~~\nYour Turn\n\n";
			Battle(&humanPlayer, &opponent);
			if (opponent.GetNumOfChars() < 1)
			{
				return true;
			}
			humanTurn = false;
		}
		else
		{
			std::cout << "\n~~~~~~~~~~~~~~~~~~~~~\nEnemy Turn\n\n";
			Battle(&opponent, &humanPlayer);
			if (humanPlayer.GetNumOfChars() < 1)
			{
				return false;
			}
			humanTurn = true;
		}
	} while (true);
}


void Level::Battle(Player* attackingPlayer, Player* defendingPlayer)
{
	attackingCharacter = attackingPlayer->GetCharacter(1);
	defendingCharacter = defendingPlayer->GetCharacter(1);

	//draw Card
	currentCard = attackingPlayer->DrawCard();

	//Get Attacks
	for (int i = 0; i < attacksPerCard; ++i)
	{
		attacksOnCard[i] = currentCard->GetAttackSet(i);
	}

	//attacks are chosen by human or AI
	int attackChoiceInt;
	bool isAttackValid;

	//Humans choose attack
	if (humanTurn == true)
	{
		ChooseAttack();
	}

}

void Level::ChooseAttack()
{
	std::cout << "Availble Attacks are:\t";

	//set up variables
	std::vector<int> validMoves;
	bool notNull;
	int cardIterator = 0;
	int attackChoice = 0;

	//while the card still has moves left
	while (currentCard->GetAttackSet(cardIterator) != NULLATTACK)
	{
		//check if the move is usable by the character
		if (attackingCharacter->CheckMove(attacksOnCard[cardIterator]))
		{
			//print valid moves and add to array
			std::cout << cardIterator + 1 << "." << currentCard->GetAttackName(cardIterator) << "\t";
			validMoves.push_back(cardIterator);
		}
		cardIterator++;
	}

	//cardSize for clarity
	int cardSize = cardIterator;

	//humans choose an attack
	if (humanTurn)
	{
		std::cout << "\nEnter the number of the attack you would like to use.\n";
		//keep asking until the input is valid
		bool isValid;
		do
		{
			attackChoice = inputHandler.getNum(humanTurn, 1, cardSize);
			//check validity
			isValid = false;
			for (int i = 0; i < validMoves.size(); i++)
			{
				int test = validMoves[i];
				if (validMoves[i] == (attackChoice - 1))
				{
					isValid = true;
					break;
				}
			}
			if (!isValid)
			{
				std::cout << "Input invalid, please try again.\n";
			}
		} while (!isValid);

		std::cout << "You Chose:";
		std::cout << currentCard->GetAttackName(attackChoice - 1) << ".\n";
	}

	//AI chooses attack
	else
	{
		int aiChoice = inputHandler.getNum(humanTurn, 1, validMoves.size());
		int atackChoice = validMoves[aiChoice];
	}

	//perform attack
	attackingCharacter->Attack(attacksOnCard[attackChoice - 1], defendingCharacter);


}
