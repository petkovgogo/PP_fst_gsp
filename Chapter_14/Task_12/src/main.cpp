#include <iostream>
#include "../inc/Asteroid.h"
#include "../inc/AsteroidStash.h"

int main()
{
    const int COUNT = 25;

    AsteroidVector asteroidStash;

    for (int i = 1; i <= COUNT; i++)
    {
        asteroidStash.push_back(new Asteroid(i * 42));
    }

    for (size_t j = 0; j < asteroidStash.size(); j++)
    {
        std::cout << "asteroidStash[" << j << "]'s size = "
                  << asteroidStash[j]->getSize() << " km" << std::endl;
    }

    // Clean up:
    for (size_t k = 0; k < asteroidStash.size(); k++)
    {
        delete asteroidStash.remove(k);
    }

    return 0;
}