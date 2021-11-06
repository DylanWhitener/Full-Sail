#include <iostream>
#include "Helper.h"
#include <time.h>

int main()
{
	while (true)
	{


		Helper::ProgramHeaders("Testing Helper.h");
		int num = Helper::GetValidatedInt("Please enter a number: ", INT_MIN, INT_MAX);
		std::cout << "Your number is: " << num << std::endl;
		Helper::ClearConsole();

		char* feedback = nullptr;
		Helper::ProgramHeaders("Testing Prompt for Text");
		Helper::PromptForText("Provide some feedback for your classes so far: ", feedback);
		std::cout << "Feedback: " << feedback;
		delete[] feedback;
		Helper::ClearConsole();

		Helper::ProgramHeaders("Testing Random Number Generation while using multiple Helper Functions");
		srand(time(NULL));
		std::cout << "If Min > Max numbers will be reversed...\n";
		int min = Helper::GetValidatedInt("Enter a minimum value: ", INT_MIN, INT_MAX);
		int max = Helper::GetValidatedInt("Enter a maximum value: ", INT_MIN, INT_MAX);
		for (size_t i = 0; i < 100; i++)
		{
			if (i < 9)
			{
				std::cout << " " << i + 1 << ". " << Helper::RandomNumberGen(min, max) << std::endl;
			}
			else
			{
				std::cout << i + 1 << ". " << Helper::RandomNumberGen(min, max) << std::endl;
			}
		}
		Helper::ClearConsole();
	}

	system("pause");
}