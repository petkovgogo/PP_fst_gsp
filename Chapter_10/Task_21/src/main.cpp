#include <iostream>
#include "../inc/NamespaceInt.h"
#include "../inc/NamespaceMath.h"
#include "../inc/NamespaceCalculation.h"

#define PRINT(RESULT) \
    std::cout << #RESULT " = " << RESULT.getNum() << std::endl;

void printResult()
{

    using Calculation::divide;

    Int::Integer num1(42);
    Int::Integer num2(7);

    // No conflicts
    Int::Integer result1(Math::divide(num1, num2).getNum());
    Int::Integer result2(divide(num1, num2).getNum());

    PRINT(result1);
    PRINT(result2);
}

int main()
{
    printResult(); // no conflicts

    return 0;
}