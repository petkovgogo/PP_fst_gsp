#include <iostream>
#include "../inc/Stash3.h"

int main()
{
    Stash intStash(sizeof(int));

    intStash.add(new int(42));
    std::cout << *(int *)intStash.fetch(0) << std::endl;

    Stash doubleStash(sizeof(double), 16);

    doubleStash.add(new double(3.14));
    std::cout << *(double *)doubleStash.fetch(0) << std::endl;

    return 0;
}
