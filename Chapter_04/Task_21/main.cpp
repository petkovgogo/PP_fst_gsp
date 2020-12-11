#include <iostream>

typedef enum
{
    Green,
    Red,
    Blue,
    Cyan,
    Magenta,
    Yellow,
    Black
} Colors;

enum Weekdays
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

typedef union
{
    char bytes[sizeof(int)];
    int number;
} IntegerBytes2;

union IntegerBytes1
{
    char bytes[sizeof(int)];
    int number;
};

void printBinary(const unsigned char val)
{
    for (int i = 7; i >= 0; i--)
    {
        if (val & (1 << i))
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }

    std::cout << std::endl;
}

int main()
{
    Colors colour = Blue;
    Weekdays weekday = Wednesday;
    
    IntegerBytes1 integerBytes1;
    integerBytes1.number = 42;

    IntegerBytes2 integerBytes2;
    integerBytes2.number = 42;

    std::cout << "Colour: " << colour << std::endl;
    std::cout << "Weekday: " << weekday << std::endl;

    std::cout << "Int bytes 1: " << std::endl;
    printBinary(integerBytes1.bytes[0]);
    
    std::cout << "Int bytes 2: " << std::endl;
    printBinary(integerBytes2.bytes[0]);

    return 0;
}
