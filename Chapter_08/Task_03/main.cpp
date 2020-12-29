#include <iostream>

#define PRINT(VAR) \
    std::cout << #VAR " = " << VAR << std::endl;

int main()
{
    const char c = 'a';
    const unsigned char uC = 10;
    const short sI = 3;
    const int i = 7;
    const long lI = 2L;
    const float f = 6.63F;
    const double d = 3.14;
    const long double lD = 2.72;

    const char charSum = c + uC;
    const long intSum = sI + i + lI;
    const long double floatingPointSum = f + d + lD;

    PRINT(charSum);
    PRINT(intSum);
    PRINT(floatingPointSum);

    return 0;
}