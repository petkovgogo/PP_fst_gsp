#include <iostream>
#include "../inc/PStash.h"
#include "../inc/Counted.h"

int main()
{
    PStash stash;

    const int COUNT = 7;

    for (int i = 0; i < COUNT; i++)
    {
        stash.add(new Counted);
    }

    for (int i = 0; i < stash.count(); i++)
    {
        std::cout << *(Counted *)stash[i] << " -> ";
        ((Counted *)stash[i])->f();
    }

    for (int i = 0; i < stash.count(); i++)
    {
        delete (Counted *)stash.remove(i);
    }

    return 0;
}