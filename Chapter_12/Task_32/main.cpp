#include <iostream>

#define EVALUATE(EXP) \
    std::cout << #EXP " = " << EXP << std::endl;

int main()
{
    double num1 = 6.63;
    double num2 = 9.81;

    EVALUATE((num1 + num2))
    EVALUATE((num1 - num2))
    EVALUATE((num1 * num2))
    EVALUATE((num1 / num2))

    return 0;
}