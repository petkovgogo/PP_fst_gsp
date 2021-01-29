#include <iostream>
#include "../inc/Integer.h"

int main()
{
    Integer int1(42);
    Integer int2(451);
    Integer int3(12);

    (++int1 + int2-- - int3++ + --int1).print(std::cout); // the same expression works
    (++++int1).print(std::cout); // this also works, because a non-const reference is returned
    (----int1).print(std::cout); // this also works, because a non-const reference is returned

    // this "feature" can be used to further modify the object, e.g. call a function that modifies the value after incrementing:
    // (++int1).modify(), where modify() is a non-const member function

    return 0;
}