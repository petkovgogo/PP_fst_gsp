#include <iostream>
#include <string>

#define SIZE 7

int main()
{
    std::string arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = "Element " + std::to_string(i);
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
