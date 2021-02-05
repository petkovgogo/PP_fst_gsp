#include <iostream>
#include "Stack4.h"
#include "Counted.h"

int main()
{
    Stack countedStack;

    const int COUNT = 7;

    for (int i = 0; i < COUNT; i++)
    {
        countedStack.push(new Counted);
    }

    Counted *countedPtr = 0;

    while ((countedPtr = (Counted *)countedStack.pop()) != 0)
    {
        std::cout << *countedPtr << " -> ";
        countedPtr->f();

        delete countedPtr;
        countedPtr = 0;
    }
    
    return 0;
}