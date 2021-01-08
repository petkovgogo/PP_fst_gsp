#include <iostream>
#include "../inc/StringHolder.h"

int main()
{
    const int HOLDER_ELEMENT_COUNT = 3;

    StringHolder holder;

    for (int i = 1; i <= HOLDER_ELEMENT_COUNT; i++)
    {
        std::cout << holder.lookup(i) << std::endl;
    }

    return 0;
}