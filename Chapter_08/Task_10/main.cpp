#include <iostream>

int main()
{
    const int NUM_1 = 42;
    const int NUM_2 = 451;

    const int *const intPtr = &NUM_1;

    std::cout << *intPtr << std::endl;
    //! std::cout << *++intPtr << std::endl;

    //! intPtr = &NUM_2;

    return 0;
}