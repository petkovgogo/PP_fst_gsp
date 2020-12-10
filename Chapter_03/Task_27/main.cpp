#include <iostream>

const int SIZE = 5;

#define PRINT_ARR(VAR)                  \
    std::cout << #VAR " = [";           \
    for (int i = 0; i < SIZE; i++)      \
    {                                   \
        std::cout << " " << VAR[i];     \
    }                                   \
                                        \
    std::cout << " ]" << std::endl;

int main()
{
    const double constArr[SIZE] = {1.6, 4, 6.63, 8, 3.14};
    volatile double volArr[SIZE] = {2.24, 14.5, 2.15, 9.81, 24.8};

    for (int i = 0; i < SIZE; i++)
    {
        const_cast<double*>(constArr)[i] = constArr[i] * constArr[i];
        const_cast<double*>(volArr)[i] = volArr[i] * volArr[i];
    }

    PRINT_ARR(constArr);
    PRINT_ARR(volArr);

    return 0;
}
