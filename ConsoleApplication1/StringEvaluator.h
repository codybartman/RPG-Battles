#pragma once
#include <iostream>
#include <string>
#include <vector>


struct StringEvaluator
{
private:
	std::vector<std::string> yesStrings;
public:
	StringEvaluator();
	bool isYes(std::string inputString);
	int getNum();
	int getNum(bool isHuman, int minValue, int maxValue);
};
