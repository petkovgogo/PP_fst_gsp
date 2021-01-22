#include <iostream>

#define PRINT(PTR) std::cout << #PTR " = " << PTR << std::endl;

void increment(int **ptr) { (*ptr)++; }
void increment(int *&ptr) { ptr++; }

int main()
{
    int arr[] = {1, 2, 3};
    int *pArr = arr;

    PRINT(*pArr);
    increment(&pArr);
    PRINT(*pArr);
    increment(pArr);
    PRINT(*pArr);

    return 0;
}