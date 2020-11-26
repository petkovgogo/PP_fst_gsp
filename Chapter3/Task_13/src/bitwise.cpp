#include <iostream>

extern unsigned char rol(unsigned char val);
extern unsigned char ror(unsigned char val);

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

#define PR(STR, EXPR)  \
    std::cout << STR;  \
    printBinary(EXPR); \
    std::cout << std::endl << std::endl;

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
    PR("a | b = ", a | b);
    PR("a & b = ", a & b);
    PR("a ^ b = ", a ^ b);
    PR("~a = ", ~a);
    PR("~b = ", ~b);
    // An interesting bit pattern:
    unsigned char c = 0x5A;
    PR("c in binary: ", c);
    a |= c;
    PR("a |= c; a = ", a);
    b &= c;
    PR("b &= c; b = ", b);
    b ^= a;
    PR("b ^= a; b = ", b);

    PR("a rotated left -> ", rol(a));
    PR("a rotated right -> ", ror(a));
    PR("b rotated left -> ", rol(b));
    PR("b rotated right -> ", ror(b));
}