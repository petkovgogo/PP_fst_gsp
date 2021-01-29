#include <iostream>
#include "../inc/Number.h"

#define EVALUATE(EXP) \
    std::cout << #EXP " = " << EXP << std::endl;

int main()
{
    Number num1(3.14);
    Number num2(6.63);

    EVALUATE((num1 + num2));
    EVALUATE((num1 - num2));
    EVALUATE((num1 * num2));
    EVALUATE((num1 / num2));

    // I use a cast in this expression, becase the compiler is not sure whether
    // it should convert the Number to int or the int to double and then to Number via the constructor.
    // Because of that two operators can be called:
    // operator/(int, int) and operator/(Number, Number)
    EVALUATE(((num1 = ((int)num2 / 2)) + num2));

    return 0;
}