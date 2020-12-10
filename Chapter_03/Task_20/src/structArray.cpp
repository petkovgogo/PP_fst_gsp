#include <iostream>

typedef struct
{
    int i, j, k;
} ThreeDpoint;

int main()
{
    const int SIZE = 10;

    ThreeDpoint p[SIZE];

    std::cout << "sizeof(ThreeDpoint) = " << sizeof(ThreeDpoint) << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "&arr[" << i << "] = " << (long)&p[i] << std::endl;
    }

    std::cout << std::endl;

    return 0;
}