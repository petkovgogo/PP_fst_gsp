#include <iostream>
#include "../inc/Bird.h"
#include "../inc/BirdHouse.h"

int main()
{
    Bird bird1;
    Bird bird2;
    Bird bird3;

    BirdHouse
        house1(bird1, &bird2, bird3),
        house2(bird2, &bird1, bird3),
        house3(bird3, &bird2, bird1); // you can chain assignments

    // house1 = house2;               // error: use of deleted function ‘BirdHouse& BirdHouse::operator=(BirdHouse&)’
    // BirdHouse tempHouse(house3);   // error: ‘BirdHouse::BirdHouse(BirdHouse&)’ is private within this context

    std::cout << house1 << house2 << house3 << std::endl;

    return 0;
}