#ifndef CALL_FUNC

#include <iostream>

#endif // CALL_FUNC

#include "../inc/Monitor.h"
#include "../inc/Monitor2.h"

void monitorTheMonitor()
{
    static Monitor2 monitor2(new Monitor());
}

int main()
{
#ifdef CALL_FUNC

    monitorTheMonitor();

#else

    std::cout << "Function was not called" << std::endl;

#endif // CALL_FUNC

    return 0;
}