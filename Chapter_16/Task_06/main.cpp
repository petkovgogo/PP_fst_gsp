#include <iostream>

// #define STL_SET
#ifdef STL_SET

#include <set>

#endif // STL_SET

#include "Set.h"

#define PRINT(EXP) \
    std::cout << #EXP " -> " << EXP << std::endl;

template <class T>
void print(T &container)
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
#ifdef STL_SET

    std::set<int> integers;

#else

    Set<int> integers;

#endif // STL_SET

    const int COUNT = 25;
    const int MULT = 10;

    for (int i = 1; i <= COUNT; i++)
    {
        integers.insert(i * MULT);

        if (i % 5 == 0)
        {
            integers.insert(i * MULT); // attempt for insetring a number again
        }
    }

    print(integers);

#ifdef STL_SET

    std::set<int>::iterator iter = integers.begin();

    integers.erase(++iter, integers.end());

#else

    Set<int>::iterator iter = integers.begin();

    PRINT(*(iter += 16));
    PRINT(*(iter -= 7));

    integers.erase(iter + 5);
    integers.erase(iter + 5, integers.end());

#endif // STL_SET

    print(integers);

    integers.erase(integers.begin(), integers.end());

    print(integers);

    return 0;
}