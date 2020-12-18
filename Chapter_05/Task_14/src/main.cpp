#include <iostream>
#include "../inc/StackOfInts.h"

int main()
{
    StackOfInts stackOfInts;

    for (int i = 0; i <= STACK_CAPACITY; i++)
    {
        stackOfInts.push(i + 1);
    }

    int value;

    while ((value = stackOfInts.pop()) != 0)
    {
        std::cout << "Value: " << value << std::endl;
    }
    
    stackOfInts.cleanup();

    return 0;
}
