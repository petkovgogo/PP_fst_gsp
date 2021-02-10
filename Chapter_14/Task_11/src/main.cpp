#include <iostream>
#include "../inc/Asteroid.h"
#include "../inc/AsteroidStash.h"

int main()
{
    const int COUNT = 25;

    AsteroidStash asteroidStash;

    for (int i = 1; i <= COUNT; i++)
    {
        asteroidStash.add(new Asteroid(i * 42));
    }

    for (int j = 0; j < asteroidStash.count(); j++)
    {
        std::cout << "asteroidStash[" << j << "]'s size = "
                  << asteroidStash[j]->getSize() << " km" << std::endl;
    }

    // Clean up:
    for (int k = 0; k < asteroidStash.count(); k++)
    {
        delete asteroidStash.remove(k);
    }

    return 0;
}