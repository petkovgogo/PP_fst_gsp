#include <iostream>

extern void printBinary(const unsigned char val);

unsigned char rol(unsigned char val)
{
    int highbit;
    if (val & 0x80)
    {
        highbit = 1;
    }
    else
    {
        highbit = 0;
    }

    std::cout << std::endl;
    std::cout << "Took the high bit: " << highbit << std::endl;

    val <<= 1;
    std::cout << "Shifted the number to the left: ";
    printBinary(val);
    std::cout << std::endl;

    val |= highbit;
    std::cout << "Inserted the high bit into the back of the number: ";
    return val;
}

unsigned char ror(unsigned char val)
{
    int lowbit;
    if (val & 1) // Check the low bit
    {
        lowbit = 1;
    }
    else
    {
        lowbit = 0;
    }

    std::cout << std::endl;
    std::cout << "Took the low bit: " << lowbit << std::endl;

    val >>= 1;
    std::cout << "Shifted the number to the left: ";
    printBinary(val);
    std::cout << std::endl;

    val |= (lowbit << 7);
    std::cout << "Inserted low bit into the front of the number: ";
    return val;
}