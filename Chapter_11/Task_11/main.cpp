#include <iostream>

void print(char symbol, int integer, double dNum, float fNum)
{
    std::cout
        << "Char: " << symbol
        << "\nInteger: " << integer
        << "\nDouble: " << dNum
        << "\nFloat: " << fNum
        << std::endl;
}

int main()
{
    print('*', 451, 6.63, 3.14F);

    return 0;
}