#include <iostream>
#include "../inc/Stash.h"

int main()
{
    const int COUNT = 25;

    Stash doubleStash;
    doubleStash.initialize(sizeof(double));
    
    for (int i = 1; i <= COUNT; i++)
    {
        doubleStash.add(new double(i * 6.63));
    }
    
    for (int i = 0; i < doubleStash.count(); i++)
    {
        std::cout << "doubleStash.fetch(" << i << ") = " <<
        *(double*)doubleStash.fetch(i) << std::endl;
    }
    
    return 0;
}
