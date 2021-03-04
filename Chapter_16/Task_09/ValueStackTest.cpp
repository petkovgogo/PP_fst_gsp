#include "ValueStack.h"
#include "SelfCounter.h"
#include <iostream>

int main()
{
    Stack<SelfCounter> sc;

    const int COUNT = 15;

    for (int i = 0; i < COUNT; i++)
    {
        sc.push(SelfCounter());
    }

    // OK to peek(), result is a temporary:
    std::cout << sc.peek() << std::endl;

    for (int k = 0; k < COUNT; k++)
    {
        std::cout << sc.pop() << std::endl;
    }

    return 0;
}