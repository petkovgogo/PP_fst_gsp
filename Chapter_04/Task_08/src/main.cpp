#include <iostream>
#include "../inc/Stack.h"

int main()
{
    const int COUNT = 25;

    Stack stack;
    stack.initialize();
    
    for (int i = 1; i <= COUNT; i++)
    {
        stack.push(new double(i * 6.63));
    }

    double* dPtr;
    while ((dPtr = (double*) stack.pop()) != 0)
    {
        std::cout << *dPtr << std::endl;
        delete dPtr;
    }
    
    stack.cleanup();

    return 0;
}
