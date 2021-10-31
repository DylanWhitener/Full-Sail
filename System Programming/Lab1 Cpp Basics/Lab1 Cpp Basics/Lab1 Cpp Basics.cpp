#include <iostream>

#pragma region Program Declarations
void Program1();
void Program2();
void Program3();
void Program4();
void Program5();
void Program6();
void Program7();
void Program8();
void Program9();
void Program10();
#pragma endregion

int main()
{
    Program1();
    Program2();
    Program3();
    Program4();
    Program5();
    Program6();
    Program7();
    Program8();
    Program9();
    Program10();
}

#pragma region Clear Buffer and Validation Methods
void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}
int IntValidaiton(int x)
{
    while (true)
    {
        if (std::cin >> x)
        {   
            ClearInputBuffer();
            return x;            
        }
        ClearInputBuffer();
        std::cout << "Please enter a valid number: ";
    }
}
#pragma endregion


#pragma region Start of the Programs needed for lab1
void Program1()
{
    std::cout << "--------------------- PROGRAM 1-1 -----------------------------\n";
    char initials[5]; // 3 initials is typically the standard but just to be on the safe side using 5 for the odd cases.
    int age = 0;

    std::cout << "Please enter your initials (No Whitespace!): ";
    std::cin >> initials;
    std::cout << "Please enter your age: ";    
    age = IntValidaiton(age); // validating if input is a valid input.    
    age *= 365; // age in years converted to days 
    std::cout << initials << ", did you know that you are at least " << age << " days old? \n";
    ClearInputBuffer();
    std::cout << "\n";
}
void Program2()
{
    std::cout << "--------------------- PROGRAM 1-2 -----------------------------\n";
    int nums[5];
    int size = sizeof(nums) / sizeof(nums[0]);

    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Please enter a number: ";        
        nums[i] = IntValidaiton(nums[i]);       
    }
    std::cout << "You entered: ";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << nums[i];
    }    
    ClearInputBuffer();
    std::cout << "\n";
}
void Program3()
{
    std::cout << "--------------------- PROGRAM 1-3 -----------------------------\n";

    int a = 0;
    int b = 0;
    int c = 0;
    int result = 0;
    std::cout << "Please enter 3 numbers.\n";
    std::cout << "Enter value for a: ";
    a = IntValidaiton(a);
    std::cout << "Enter value for b: ";
    b = IntValidaiton(b);
    std::cout << "Enter value for c: ";
    c = IntValidaiton(c);

    result = a + 1 * b + 2 - c;
    std::cout << "a + 1 * b + 2 - c = " << result << "\n";
    result = (a + 1) * (b + 2) - c;
    std::cout << "(a + 1) * (b + 2) - c = " << result;
    ClearInputBuffer();
    std::cout << "\n";
}
void Program4()
{
    std::cout << "--------------------- PROGRAM 1-4 -----------------------------\n";
    std::cout << "Type" << "\t\tRange" << "\n";
    std::cout << "====================================================\n";
    std::cout << "ushort" << "\t\t" << "0 - " << USHRT_MAX;
    std::cout << "\n";
    std::cout << "uint" << "\t\t" << "0 - " << UINT_MAX;
    std::cout << "\n";
    std::cout << "ulonglong" << "\t" << "0 - " << ULLONG_MAX; 
    std::cout << "\n";
    std::cout << "short" << "\t\t" << SHRT_MIN << " - " << USHRT_MAX;
    std::cout << "\n";
    std::cout << "int" << "\t\t" << INT_MIN << " - " << INT_MAX;
    std::cout << "\n";
    std::cout << "longlong" << "\t" << LLONG_MIN << " - " << LLONG_MAX; 
    std::cout << "\n";
    std::cout << "\n";
}
void Program5()
{
    std::cout << "--------------------- PROGRAM 1-5 -----------------------------\n";

    char fullName[32];
    std::cout << "Please enter your full name: ";
    std::cin.getline(fullName,32);

    std::cout << "Hello, " << fullName << ", did you know Most elephants weigh less than the tongue of a blue whale.";
    std::cout << "\n";
}
void Program6()
{
    std::cout << "--------------------- PROGRAM 1-6 -----------------------------\n";

    int age = 0;
    std::cout << "How old are your friend? "; 
    age = IntValidaiton(age);    

    if (age <= 16)
    {
        std::cout << "I\'m sorry, but you\'re too young to play this game. Bye";
    }
    else if (age >= 17 && age < 50)
    {
        std::cout << "You are a decent age dont be scared. Congradulations!";
    }
    else
    {
        std::cout << "You are so old!!! Don\'t you know the cool kids stop aging at 21!";
    }
    std::cout << "\n";
}
void Program7()
{
    std::cout << "--------------------- PROGRAM 1-7 -----------------------------\n";
    int num = 0;
    std::cout << "Please enter an even number: ";
    num = IntValidaiton(num); 

    if (num % 2 == 0)
    {
        std::cout << "Nice job your number is an even number.";
    }
    else
    {
        std::cout << "You failed to provide an even number...";
    }
    std::cout << "\n";
}
void Program8()
{
    std::cout << "--------------------- PROGRAM 1-8 -----------------------------\n";
    int div = 0;
    std::cout << "Please enter a divisor: ";
    srand((unsigned)time(NULL));
    div = IntValidaiton(div);   
    for (size_t i = 0; i < 3; i++)
    {
        int randNumber = rand();
        if (randNumber % div == 0)
        {
            std::cout << randNumber << " is divisible by " << div << "\n";
        }
        else
        {
            std::cout << randNumber << " is NOT divisible by " << div << "\n";
        }
    }

}
void Program9()
{
    std::cout << "--------------------- PROGRAM 1-9 -----------------------------\n";
    enum PopsicleColor
    {
        Red = 1,
        Green,
        Blue,
        Orange = 13
    };
         
    std::cout << "Which color popsicle would you like?\n";
    std::cout << "1) Red\n";
    std::cout << "2) Green\n";
    std::cout << "3) Blue\n";
    std::cout << "13) Orange\n";
    std::cout << ">";
    int select = 0;
    std::cin >> select;
   
    switch (select)
    {
    case Red:
        std::cout << "Red Cherry, good choice.";
        break;
    case Green:
        std::cout << "Green Apple, hope you like sour stuff";
        break;
    case Blue:
        std::cout << "Blue Coconut, you can choose better then that...";
        break;
    case Orange:
        std::cout << "hmmm... how long has that been there...";
        break;
    default:
        break;
    }
    std::cout << "\n";
}
void Program10()
{
    std::cout << "--------------------- PROGRAM 1-10 -----------------------------\n";
    enum LevelDifficulty
    {
        Easy = 1,
        Medium,
        Hard
    };
    std::cout << "What difficulty would you like to try?\n";
    std::cout << "1) Easy\n";
    std::cout << "2) Medium\n";
    std::cout << "3) Hard\n";
    std::cout << "What'll it be? ";
    
    int select = 0;
    std::cin >> select;

    srand((unsigned)time(NULL));
    int randNumber = rand();

    switch (select)
    {
    case Easy:
        randNumber = rand() % 10 + 1;
        std::cout << "You\'ll have to fight " << randNumber << " enemies!";
        break;
    case Medium:
        randNumber = rand() % 10 + 10;
        std::cout << "You\'ll have to fight " << randNumber << " enemies!";
        break;
    case Hard:
        randNumber = rand() % 10 + 20;
        std::cout << "You\'ll have to fight " << randNumber << " enemies!";
        break;
    default:
        break;
    }
    std::cout << "\n";
}
#pragma endregion