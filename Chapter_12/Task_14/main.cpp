#include <iostream>
#include "Bird.h"

int main()
{
    Bird bird1;
    Bird bird2;
    Bird bird3(bird1);

    bird1 = bird2;

    bird2 = bird2; // sefl-assignment

    std::cout << bird1 << std::endl
              << bird2 << std::endl
              << bird3 << std::endl;

    return 0;
}