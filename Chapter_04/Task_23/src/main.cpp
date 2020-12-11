#include <iostream>
#include <fstream>
#include "../inc/Stash.h"
#include "../inc/StashStack.h"

void printStack(StashStack &stashStack)
{
    Stash *p_stringStash;

    while ((p_stringStash = stashStack.pop()) != 0)
    {
        for (int i = p_stringStash->count() - 1; i >= 0; i--)
        {
            std::cout << (char *)p_stringStash->fetch(i) << std::endl;
        }

        delete p_stringStash;
    }
}

int main()
{
    std::ifstream file("../inc/dummy.txt");
    StashStack stashStack;

    stashStack.push(file);

    printStack(stashStack);

    stashStack.cleanup();

    return 0;
}
