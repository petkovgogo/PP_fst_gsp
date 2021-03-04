#include <iostream>
#include "Integer.h"

void add(const Integer num1, const Integer num2)
{
    std::cout << (num1 + num2) << std::endl;
}

int main()
{
    Integer num(42);

    add(num, Integer(56, Minus));

    return 0;
}