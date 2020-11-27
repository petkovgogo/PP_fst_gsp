#include <iostream>

#define PRINT_ARR(VAR, SIZE)        \
    std::cout << #VAR " = [";       \
    for (int i = 0; i < SIZE; i++)  \
    {                               \
        std::cout << " " << VAR[i]; \
    }                               \
                                    \
    std::cout << " ]" << std::endl;

void reasignValues(double arr[], int size)
{
    unsigned char* cpArr = reinterpret_cast<unsigned char*>(arr);

    for (int i = 0; i < sizeof(double) * size; i++)
    {
        cpArr[i] = 1;
    }
}

int main()
{
    #define SIZE 6
    double arr[SIZE]{0};
    PRINT_ARR(arr, SIZE);

    reasignValues(arr, SIZE);
    PRINT_ARR(arr, SIZE);

    return 0;
}
