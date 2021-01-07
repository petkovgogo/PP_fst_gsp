#include <iostream>
#include <ctime>

const int COUNT = 1000000;

inline void f1() { for (int i = 0; i < COUNT; i++) {} }

void f2() { for (int i = 0; i < COUNT; i++) {} }

int main()
{
    clock_t timeFor_f1 = clock();

    f1();

    timeFor_f1 = clock() - timeFor_f1;

    clock_t timeFor_f2 = clock();

    f2();

    timeFor_f2 = clock() - timeFor_f2;

    // Sometimes f1 is executed faster than f2, other times it's the opposite
    std::cout << "Time for f1 execution: " << ((double) timeFor_f1 / CLOCKS_PER_SEC) << std::endl;
    std::cout << "Time for f2 execution: " << ((double) timeFor_f2 / CLOCKS_PER_SEC) << std::endl;

    return 0;
}