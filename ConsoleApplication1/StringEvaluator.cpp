#include "StringEvaluator.h"


StringEvaluator::StringEvaluator()
{
	yesStrings = { "yes", "Yes", "YES", "y", "Y", "1" };
}

bool StringEvaluator::isYes(std::string inputString)
{
	for (int i = 0; i < yesStrings.size(); i++)
	{
		if (inputString.compare(yesStrings[i]) == 0)
		{
			return true;
		}
	}
	return false;
}

int StringEvaluator::getNum()
{
	std::string inputString;
	int returnValue;

	std::cin >> inputString;

	//try to return an int.
	try
	{
		returnValue = std::stoi(inputString);
	}
	//if a non int was entered it will be treated as an invalid Int (666)
	catch (std::invalid_argument)
	{
		returnValue = 666;
	}
	return returnValue;
}

int StringEvaluator::getNum(bool isHuman, int minValue, int maxValue)
{
	if (isHuman)
	{
		return getNum();
	}
	else
	{
		return rand() % (maxValue - minValue + 1) + minValue;
	}
}



