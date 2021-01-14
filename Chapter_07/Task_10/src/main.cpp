#include <iostream>
#include "../inc/MemStash.h"

int main()
{
    MemStash intStash(sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        intStash.add(new int(i));
    }
    

    for (int i = 0; i < intStash.size(); i++)
    {
        std::cout << *(int *)intStash.get(i) << std::endl;
    }

    return 0;
}