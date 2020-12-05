#include <iostream>

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

union IntegerBytes
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
    Weekdays weekday = Wednesday;
    IntegerBytes integerBytes;
    integerBytes.number = 42;

    std::cout << weekday << std::endl;
    printBinary(integerBytes.bytes[0]);
    
    return 0;
}
