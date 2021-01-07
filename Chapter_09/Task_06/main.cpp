#include <iostream>

inline int sum(int a, int b)
{
    return a + b;
}

int main()
{
    std::cout << sum(42, 451) << std::endl; // no linker error, which means inline functions have internal linkage

    return 0;
}