#include <iostream>
#include "../inc/Integer.h"

int main()
{
    Integer int1(42);
    Integer int2(451);
    Integer int3(12);

    (++int1 + int2-- - int3++ + --int1).print(std::cout);

    return 0;
}