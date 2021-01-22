#include <iostream>

void modify(int **&ptr) { (*(*ptr))++; }

int main()
{
    int num = 41;
    int *pNum = &num;
    int **ppNum = &pNum;

    std::cout << "Before: " << (*(*ppNum)) << std::endl;

    modify(ppNum);

    std::cout << "After: " << (*(*ppNum)) << std::endl;

    return 0;
}