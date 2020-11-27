#include <iostream>

/*  g++ -D DEBUG stringizingExpressions.cpp for debug mode
    g++ stringizingExpressions.cpp for normal mode  */

#ifdef DEBUG
#define P(A) std::cout << #A << ": " << (A) << std::endl;
#endif

int main()
{
    #ifdef DEBUG
    int a = 1, b = 2, c = 3;
    P(a);
    P(b);
    P(c);
    P(a + b);
    P((c - a) / b);
    #endif

    #ifndef DEBUG
    std::cout << "This is not debug mode" << std::endl;
    #endif

    return 0;
}