#include <iostream>
#include <fstream>
#include "../inc/Stash.h"
#include "../inc/StashStack.h"

void printStack(StashStack &stashStack)
{
    const char *p_contents;

    while ((p_contents = stashStack.pop()) != 0)
    {
        std::cout << p_contents;

        delete p_contents;
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
