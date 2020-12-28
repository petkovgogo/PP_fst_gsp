#include <iostream>
#include "../inc/MemStash.h"

int main()
{
    MemStash intStash(sizeof(int));

    intStash.add(new int(42));
    intStash.add(new int(415));

    for (int i = 0; i < intStash.size(); i++)
    {
        std::cout << *(int *)intStash.get(i) << std::endl;
    }

    return 0;
}