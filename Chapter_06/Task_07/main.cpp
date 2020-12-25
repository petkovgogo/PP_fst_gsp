#include <iostream>

/* When an array is passed to a function you cannot directly 
take its size with sizeof, because it decays to a pointer */

void printArr(double arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    double arr1[7] = {1, 2, 3, 4};

    printArr(arr1, sizeof(arr1) / sizeof(*arr1));

    double arr2[] = {5, 6, 7, 8};

    printArr(arr2, sizeof(arr2) / sizeof(*arr2));

    return 0;
}