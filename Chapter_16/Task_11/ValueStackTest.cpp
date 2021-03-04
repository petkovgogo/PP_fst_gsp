#include <iostream>
#include <vector>
#include "SelfCounter.h"

int main()
{
    std::vector<SelfCounter> sc; // doesn't automatically create a bunch of default objects

    const int COUNT = 50;

    for (int i = 0; i < COUNT; i++)
    {
        sc.push_back(SelfCounter()); // first object created here
    }

    // OK to peek(), result is a temporary:
    std::cout << sc.back() << std::endl;

    for (int k = 0; k < COUNT; k++)
    {
        std::cout << sc.back() << std::endl;
        sc.pop_back();
    }

    return 0;
}