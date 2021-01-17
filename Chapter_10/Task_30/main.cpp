#include <iostream>

#define INIT // comment this for an output without initialisation to 0

void autoInitExample()
{
    const int SIZE = 7;

    struct IntHolder
    {
        int m_num;

#ifdef INIT
        
        IntHolder() : m_num(0) {}
        
#endif // INIT

    } intHolderArr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << intHolderArr[i].m_num << " ";
    }

    std::cout << std::endl;
}

int main()
{
    autoInitExample();

    return 0;
}