#include <iostream>

void func()
{
    int i = 0;
    std::cout << "i = " << ++i << std::endl;
}

int main()
{
    for (int x = 0; x < 10; x++)
    {
        func();
    }

    return 0;
}
