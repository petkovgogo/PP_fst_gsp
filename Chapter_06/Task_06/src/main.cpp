#include <iostream>
#include "../inc/Handle.h"

int main()
{
    Handle u;
    std::cout << u.read() << std::endl;
    
    u.change(1);

    std::cout << u.read() << std::endl;

    return 0;
}