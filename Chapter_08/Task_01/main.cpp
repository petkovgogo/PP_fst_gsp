#include <stdio.h>

int main()
{
    const int SIZE_1 = 7;
    const int SIZE_2 = 2;
    const int SIZE_3 = 5;

    int arr[SIZE_1 + SIZE_2 + SIZE_3];

    printf("Array size: %d\n", (int)(sizeof(arr) / sizeof(*arr)));

    return 0;
}