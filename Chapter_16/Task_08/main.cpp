#include <iostream>
#include "OwnerStack.h"

int main()
{
    Stack<int *> ownerStack;
    Stack<char *> chars(false);

    const int COUNT = 26;

    for (int i = 1; i <= COUNT; i++)
    {
        ownerStack.push(new int(i * 10));
        chars.push(new char(i + '@'));
    }

    int *elem = 0;

    while ((elem = ownerStack.pop()) != 0)
    {
        std::cout << *elem << " ";
    }

    std::cout << std::endl;

    char *symbol = 0;

    while ((symbol = chars.pop()) != 0)
    {
        std::cout << *symbol << " ";

        delete symbol;
        symbol = 0;
    }

    std::cout << std::endl;

    return 0;
}