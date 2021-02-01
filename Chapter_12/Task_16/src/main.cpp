#include <iostream>
#include "../inc/Bird.h"
#include "../inc/BirdHouse.h"

#define EVALUATE(EXP)\
std::cout << #EXP " = " << EXP << "\n" << std::endl;

int main()
{
    Bird bird1(42);
    Bird bird2(451);
    Bird bird3(12);

    EVALUATE((bird1 + bird2 - bird3))
    EVALUATE((bird2 / bird3))
    EVALUATE((bird1 * bird3))

    BirdHouse
        house1(bird1, &bird2, bird3),
        house2(bird2, &bird1, bird3),
        house3(bird3, &bird2, bird1);

    EVALUATE((house1 + house2 - house3))
    EVALUATE((house2 / house3))
    EVALUATE((house1 * house3))

    return 0;
}