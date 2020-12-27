#include <iostream>

#ifdef PLACEHOLDER_ARGUMENT

int sum(int num1, int)
{
    return num1;
}

#else

int sum(int num1, int num2)
{
    return num1 + num2;
}

#endif // PLACEHOLDER_ARGUMENT

int main() // The main function doesn't change. The output, on the other hand, changes, because one of the arguments becomes unusable
{
    std::cout << sum(1, 2) << std::endl;
    
    return 0;
}
