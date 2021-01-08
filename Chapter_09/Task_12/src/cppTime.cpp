#include <iostream>
#include "../inc/CppTime.h"

int main()
{
    const char NEW_LINE = 10;
    const char C_RETURN = 13;

    Time start;

    bool pressedReturn = false;
    char key;

    while (!pressedReturn)
    {
        std::cin.get(key);

        if (key == NEW_LINE || key == C_RETURN)
        {
            pressedReturn = true;
        }
    }

    Time end;

    std::cout << std::endl;
    std::cout << "start = " << start.ascii();
    std::cout << "end = " << end.ascii();
    std::cout << "delta = " << end.delta(&start) << "s" << std::endl;

    return 0;
}