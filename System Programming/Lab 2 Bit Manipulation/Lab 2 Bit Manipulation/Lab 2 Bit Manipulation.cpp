#include <iostream>

#pragma region Declarations
unsigned int bitField();
void printBinaryNumber(unsigned int number, int size);
void printOptions();
void TurnOn(int bit);
void TurnOff(int bit);
void MainProgram();
void printData();
void Toggle(int bit);
void Negate();
void LeftShift();
void RightShift();
unsigned int bitF;
unsigned int data;
#pragma endregion

int main()
{	
	bitF = data = 0;
	std::cout << "bitField: " << bitF << std::endl;
	std::cout << "Data:     ";
	printBinaryNumber(data, 32);
	MainProgram();
}

#pragma region Program Functions
unsigned int bitField()
{    
	unsigned int number;
	while (true)
	{
		std::cin >> number;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(UINT_MAX, '\n');
			std::cout << "Enter a valid number: ";
			continue;;
		}
		std::cin.ignore(UINT_MAX, '\n');
		break;
	}
	return number;
}
void printBinaryNumber(unsigned int number, int size)
{
	char* text = new char[size+ 1];	
	text[size] = '\0';
	for (int i = size - 1; i >= 0; i--)
	{
		if (number % 2 == 0)
		{
			text[i] = '0';
		}
		else
		{
			text[i] = '1';
		}
		number /= 2;
	}
	for (int i = 0; i < 32; i++)
	{
		if (i % 4 == 0)
		{
			std::cout <<  " ";
		}
		std::cout << text[i];
	}
	std::cout << std::endl;
	delete[] text;
}
void printOptions()
{
	std::cout << std::endl;
	std::cout << "1. TurnOn" << std::endl;
	std::cout << "2. TurnOff" << std::endl;
	std::cout << "3. Toggle" << std::endl;
	std::cout << "4. Negate" << std::endl;
	std::cout << "5. Left Shift" << std::endl;
	std::cout << "6. Right Shift" << std::endl;
	std::cout << "7. Exit" << std::endl;
	
}
void printData() 
{
	std::cout << "Data:     ";
	printBinaryNumber(data, 32);
}
void TurnOn(int bit)
{	
	printData();
	data = data | bit;
	bitF = data;
	std::cout << "New Data: ";
	printBinaryNumber(data, 32);
	std::cout << "bitField: " << bitF << std::endl;
	
}
void TurnOff(int bit)
{
	printData();
	data = data & ~bit;
	bitF = data;
	std::cout << "New Data: ";
	printBinaryNumber(data, 32);
	std::cout << "bitField: " << bitF << std::endl;
}
void Toggle(int bit)
{
	printData();
	data = data ^ bit;
	bitF = data;
	std::cout << "New Data: ";
	printBinaryNumber(data, 32);
	std::cout << "bitField: " << bitF << std::endl;
}
void Negate()
{	
	printData();
	data = ~ data;
	bitF = data;
	std::cout << "New Data: ";
	printBinaryNumber(data, 32);
	std::cout << "bitField: " << bitF << std::endl;
}
void LeftShift()
{
	printData();
	data = data << 1;
	bitF = data;
	std::cout << "New Data: ";
	printBinaryNumber(data, 32);
	std::cout << "bitField: " << bitF << std::endl;
}
void RightShift()
{
	printData();
	data = data >> 1;
	bitF = data;
	std::cout << "New Data: ";
	printBinaryNumber(data, 32);
	std::cout << "bitField: " << bitF << std::endl;
}
void MainProgram()
{
	bool isRunning = true;
	while (isRunning)
	{
		//system("cls");		
		std::cout << std::endl << std::endl;
		std::cout << "Which function would you like to perform? ";
		printOptions();
		std::cout << "Select an Option: " ;
		int option = bitField();
		system("cls");
		std::cout << "bitField: " << bitF << std::endl;
		switch (option)
		{
		case 1:
			printData();
			std::cout << std::endl;
			std::cout << "Turn on a bit use index (1-32)\n\n";
			std::cout << "Bit selection: ";
			TurnOn(1 << bitField() -1);
			break;
		case 2:
			printData();
			std::cout << std::endl;
			std::cout << "Turn off a bit use index (1-32)\n\n";
			std::cout << "Bit selection: ";
			TurnOff(1 << bitField() - 1);
			break;
		case 3:
			printData();
			std::cout << std::endl;
			std::cout << "Toggle on/off a bit use index (1-32)\n\n";
			std::cout << "Bit selection: ";
			Toggle(1 << bitField() - 1);
			break;
		case 4:
			Negate();
			break;
		case 5:
			LeftShift();
			break;
		case 6:
			RightShift();
			break;
		case 7:
			isRunning = false;
			break;		
		}
	}
}
#pragma endregion