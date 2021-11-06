#include "Helper.h"
#include <iostream>

//Will prompt a string and give you a number range to enter from and take user input
int Helper::GetValidatedInt(const char* strMessage, int nMinimumRange , int nMaximumRange)
{
	std::cout << strMessage;
	int number;
	while (true)
	{
		std::cin >> number;
		if (std::cin.fail() || number < nMinimumRange || number > nMaximumRange)
		{
			ClearBuffer();
			std::cout << "Invalid input please try again: ";
			continue;
		}
		std::cin.ignore(INT_MAX, '\n');
		break;
	}
	return number;
}

//Clears the std::cin buffer to prevent issues with the buffer over writing
void Helper::ClearBuffer()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

//Keeps the console clean when moving to different parts of the program
void Helper::ClearConsole()
{
	std::cout << std::endl;
	system("pause");
	system("cls");
}

//Places a clean header on each of the programs to prevent from having to keep manually entering a bunch of dashes
void Helper::ProgramHeaders(const char* programTitle)
{
	std::cout << "-----------------------" << programTitle << "-----------------------\n\n";
}

//Will prompt the user for text instead of a number.
void Helper::PromptForText(const char* prompt, char*& text)
{
	char buffer[5000];
	std::cout << prompt << std::endl;
	std::cin.getline(buffer, 5000);

	int length = strlen(buffer) + 1;

	delete[] text;
	text = new char[length];
	strcpy_s(text, length, buffer);
}

//Creates a random number between a range of int min and max
int Helper::RandomNumberGen(int min, int max)
{
	int randNum = 0;
	if (min > max)
	{
		int temp = max;
		max = min;
		min = temp;
	}
	
	max -= min;
	randNum = rand() % (max + 1) + min;

	return randNum;
}
