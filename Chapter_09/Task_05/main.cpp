#include <iostream>
#include <ctime>

const int COUNT = 2;

inline int f1(int num)
{
    if (num == 0)
    {
        return 0;
    }

    return f1(num - 1);
}

int f2(int num)
{
    if (num == 0)
    {
        return 0;
    }

    return f2(num - 1);
}

int main()
{
    clock_t timeFor_f1 = clock();

    f1(COUNT);

    timeFor_f1 = clock() - timeFor_f1;

    clock_t timeFor_f2 = clock();

    f2(COUNT);

    timeFor_f2 = clock() - timeFor_f2;

    // The results are quite different, but most of the times f2() is faster
    // I tried compiling on Linux (with g++) and on Windows (with MinGW), but the only output on Windows is 0 (for both functions)
    // T also compiled it with another C++ compiler - Zapcc
    std::cout << "Time for f1 execution: " << ((double)timeFor_f1 / CLOCKS_PER_SEC) << std::endl;
    std::cout << "Time for f2 execution: " << ((double)timeFor_f2 / CLOCKS_PER_SEC) << std::endl;

    return 0;
}