#include <iostream>

typedef int (*pFunc)(double num);

int func(double num)
{
    return num * num;
}

int main()
{
    pFunc ptr = &func;

    std::cout << ptr(9.81) << std::endl;
    
    return 0;
}
