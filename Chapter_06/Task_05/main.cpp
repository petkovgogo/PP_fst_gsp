#include <iostream>

int main()
{
    int i;

    for (i = 0; i < 10; i++)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl; // the compiler does not throw an error. It uses the local for that scope variable

    return 0;
}