#include <iostream>

int &modify(int *value)
{
    *value = 42;

    return *value;
}

int main()
{
    int initValue = 451;

    std::cout << "initValue = " << initValue << std::endl;

    int &valRef = modify(&initValue);

    std::cout
        << "initValue = " << initValue
        << ", valRef = " << valRef << std::endl;

    return 0;
}