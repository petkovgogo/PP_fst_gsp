#include <iostream>

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
}

#define PR(STR, EXPR)\
    std::cout << STR;\
    printBinary(EXPR);\
    std::cout << std::endl;

int main()
{
    unsigned int getval;
    unsigned char a, b;
    std::cout << "Enter a number between 0 and 255: ";
    std::cin >> getval;
    a = getval;
    PR("a in binary: ", a);
    std::cout << "Enter a number between 0 and 255: ";
    std::cin >> getval;
    b = getval;
    PR("b in binary: ", b);
    PR("a bitor b = ", a bitor b);
    PR("a bitand b = ", a bitand b);
    PR("a xor b = ", a xor b);
    PR("compl a = ", compl a);
    PR("compl b = ", compl b);
    
    // An interesting bit pattern:
    unsigned char c = 0x5A;
    PR("c in binary: ", c);
    a or_eq c;
    PR("a or_eq c; a = ", a);
    b and_eq c;
    PR("b and_eq c; b = ", b);
    b xor_eq a;
    PR("b xor_eq a; b = ", b);
}