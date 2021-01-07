#include <iostream>

#define FLOOR(x, b) ((x) >= (b) ? 1 : 0)
//! #define FLOOR(x, b) x >= b ? 1 : 0

int main()
{
    int a = 8;

    /*
        When there are parentheses, the expression
        evaluates to if (((8 & 15) >= (7) ? 1 : 0)),
        which then evaluates to
        8 >= 7 ? 1 : 0, which is true


        Without parentheses, the expression
        evaluates to if (8 & 15 >= 7 ? 1 : 0)
        because the precedence of >= is higher, it evaluates to
        8 & 1 ? 1 : 0, which is false
    */

    if (FLOOR(a & 0x0f, 0x07))
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    return 0;
}