#include <iostream>
#include "TPStash.h"

int main()
{
    PStash<int *> integers; // initial incr value is 10 (default argument)

    std::cout 
    << "New increment value: "
    << integers.changeIncrValue(40)
    << std::endl;

    return 0;
}