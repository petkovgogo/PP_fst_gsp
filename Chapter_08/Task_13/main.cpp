#include <iostream>

int changeValue(const int NUMBER)
{
    //! NUMBER = 451; // expression must be a modifiable lvalue

    return NUMBER;
}

int main()
{
    std::cout << changeValue(42) << std::endl;

    return 0;
}