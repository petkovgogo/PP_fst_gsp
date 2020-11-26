#include <iostream>

// Different outputs for the first part are in the outputs folder

#define SIZE1 6
#define SIZE2 SIZE1 / 2

#define PRINT_ADDRESS(EXP) std::cout << #EXP" -> " << (long)EXP << std::endl;

int main()
{
    int arr1[SIZE1]{3};
    char ch = '8'; // char is defined before arr2 (why?) so there is no change
    int arr2[SIZE2]{2}; // arr2 is defined before arr1

    PRINT_ADDRESS(arr1);
    PRINT_ADDRESS(&ch);
    PRINT_ADDRESS(arr2);

    std::cout << "First index of arr1: " << arr1[0] << std::endl;
    std::cout << "Putting a value one index after the end of arr2" << std::endl;
    arr2[SIZE2] = INT32_MAX;
    std::cout << "First index of arr1: " << arr1[0] << std::endl;

    return 0;
}
