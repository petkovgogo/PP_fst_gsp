#include <iostream>

#define SIZE 8
#define BYTE_RANGE 16
#define SUBSTITUTION_VALUE 42
#define PRINT_ARR(VAR, LENGTH)              \
    std::cout << #VAR" = [";         \
    for (int i = 0; i < LENGTH; i++)  \
    {                               \
        std::cout << " " << VAR[i]; \
    }                               \
                                    \
    std::cout << " ]" << std::endl;

void setBytes(void *vpArr, int byteRange, int value)
{
    char *cpArr = static_cast<char *>(vpArr);

    for (int i = 0; i < byteRange; i++)
    {
        cpArr[i] = value + i * 2;
    }

    PRINT_ARR(cpArr, byteRange);
}

int main()
{
    int arr[SIZE]{0};
    PRINT_ARR(arr, SIZE);

    void *pArr = static_cast<void *>(arr);
    setBytes(pArr, BYTE_RANGE, SUBSTITUTION_VALUE);

    PRINT_ARR(arr, SIZE);
    return 0;
}
