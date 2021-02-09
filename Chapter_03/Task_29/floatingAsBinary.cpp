#include <cstdlib>
#include <iostream>

typedef unsigned char byte;

void printBinary(const byte val, int startBit, int endBit)
{
    for (int i = startBit; i >= endBit; i--)
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
}

void displayExponent(byte *byteArr)
{
    std::cout << "Exponent: ";

    const int EXPONENT_START = 7; // whole byte, except the last bit (the sign bit)
    const int EXPONENT_END = 6;   // half a byte (without the fraction part)
    const int LAST_BIT = 7;       // counting from 0
    const int SEVENTH_BIT = 6;    // counting from 0
    const int FIFTH_BIT = 4;      // counting from 0
    const int FIRST_BIT = 0;      // counting from 0

    printBinary(byteArr[EXPONENT_START], SEVENTH_BIT, FIRST_BIT); // print without the sign bit
    printBinary(byteArr[EXPONENT_END], LAST_BIT, FIFTH_BIT);      // print without the fraction part

    std::cout << std::endl;
}

void displayFraction(byte *byteArr)
{
    std::cout << "Fraction: ";

    const int FRACTION_START = 6; // whole byte, except the last bit (the sign bit)
    const int FRACTION_END = 0;   // half a byte (without the fraction part)
    const int LAST_BIT = 7;       // counting from 0
    const int FORTH_BIT = 3;      // counting from 0
    const int FIRST_BIT = 0;      // counting from 0

    printBinary(byteArr[FRACTION_START], FORTH_BIT, FIRST_BIT); // print without the exponent part

    for (int i = FRACTION_START - 1; i >= FRACTION_END; i--)
    {
        printBinary(byteArr[i], LAST_BIT, FIRST_BIT); // print whole byte
    }

    std::cout << std::endl;
}

int main()
{
    double num = -3.14;
    byte *byteArr = reinterpret_cast<byte *>(&num);

    const int SIGN_BIT = 7; // last bit in the 8th byte (7th, when counting from 0)

    std::cout << "Sign: " << (byteArr[SIGN_BIT] & (1 << SIGN_BIT) ? 1 : 0) << std::endl;

    displayExponent(byteArr);
    displayFraction(byteArr);

    return 0;
}