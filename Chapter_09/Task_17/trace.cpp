#include <iostream>

#define TRACE(s)                      \
    std::cerr << #s ":" << std::endl; \
    s

void func()
{
    std::cout << "\n- What is my purpose?" << std::endl;
    std::cout << "- You get TRACE-d COUNT times" << std::endl;
    std::cout << "- Oh, my god...\n" << std::endl;
}

int main()
{
    const int COUNT = 7;

    for (int i = 0; i < COUNT; i++) // added brackets
    {
        TRACE(func());
    }

    return 0;
}