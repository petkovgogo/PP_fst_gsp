#include <cstdlib>
#include <iostream>

#define SIGN_BIT 1
#define EXPONENT_RANGE 2 // 1 byte and a half

void printBinary(const unsigned char val, int startBit, int endBit)
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

int main(int argc, char *argv[])
{
    // if (argc != 2)
    // {
    //     std::cout << "Must provide a number" << std::endl;
    //     exit(1);
    // }

    double d = 3.14; //atof(argv[1]);
    unsigned char *cp =
        reinterpret_cast<unsigned char *>(&d);

        std::cout << "Fraction: ";
    for (int i = sizeof(double); i > 0; i--)
    {
        if (i == EXPONENT_RANGE) // print half byte of fraction and half a byte of exponent
        {
            printBinary(cp[i], 7, 4);
            std::cout << std::endl;

            std::cout << "Exponent: ";
            printBinary(cp[i], 3, 0);
        }
        else if (i == EXPONENT_RANGE - 1) // print exponent without sign bit
        {
            printBinary(cp[i], 6, 0);
            std::cout << std::endl;
        }
        else // print normal byte
        {
            printBinary(cp[i], 7, 0);
        }
    }

    std::cout << "Sign: " << (cp[0] & (1 << 7)) << std::endl;

    return 0;
}