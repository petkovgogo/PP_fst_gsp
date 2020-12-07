#include <iostream>
#include <fstream>
#include "../inc/Stash.h"
#include "../inc/StashStack.h"

int main()
{
    std::ifstream file("../inc/dummy.txt");
    StashStack stashStack;

    stashStack.push(file);

    Stash *p_stringStash;
    while ((p_stringStash = stashStack.pop()) != 0)
    {
        for (int i = 0; i < p_stringStash->count(); i++)
        {
            std::cout << (const char *)p_stringStash->fetch(i) << " ";
        }

        std::cout << std::endl;

        delete p_stringStash;
    }

    stashStack.cleanup();

    return 0;
}
