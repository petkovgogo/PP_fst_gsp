#include <iostream>
#include <vector>
#include "Counted.h"

int main()
{
    std::vector<Counted *> countedVector;

    const int COUNT = 7;

    for (int i = 0; i < COUNT; i++)
    {
        countedVector.push_back(new Counted);
    }

    for (auto it = countedVector.begin(); it != countedVector.end(); it++)
    {
        std::cout << **it << " -> ";
        (*it)->f();
    }

    for (auto it = countedVector.begin(); it != countedVector.end(); it++)
    {
        delete *it;
    }

    return 0;
}