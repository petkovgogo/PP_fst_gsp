#include <iostream>

#define SIZE 8
#define BYTE_RANGE 16
#define SUBSTITUTION_VALUE 42
#define PRINT_ARR(VAR)              \
    std::cout << #VAR" = [";         \
    for (int i = 0; i < SIZE; i++)  \
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
        cpArr[i] = value - i;
    }

    PRINT_ARR(cpArr);
}

int main()
{
    int arr[SIZE]{0};
    PRINT_ARR(arr);

    void *pArr = static_cast<void *>(arr);
    setBytes(pArr, BYTE_RANGE, SUBSTITUTION_VALUE);

    PRINT_ARR(arr);
    return 0;
}
