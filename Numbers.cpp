#include "Numbers.h"

bool Numbers::sqrt_2(ld num)
{
	if (num == 1.414213562)
		return true;
	return false;
}

void Numbers::addNumTranslation(ld num)
{
	string userInput;
	cout << "\nyou are translating the number\n" << num
		<< " to your desired string enter symbolic link now\n>";
	cin >> userInput;
	realNumTranslation.emplace(num, userInput);
}

void Numbers::checkForNumTranslation(const ld num) const
{
	cout << realNumTranslation.at(num);
}
