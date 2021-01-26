#include <iostream>

static const int MAX_SIZE = 12;

class Simple
{
public:
    int m_arr[MAX_SIZE];

    Simple() : m_arr{0} {}
};

typedef int (Simple::*m_arrPtr_t)[MAX_SIZE];

int main()
{
    Simple simpleObj;

    m_arrPtr_t m_arrPtr = &Simple::m_arr;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << (simpleObj.*m_arrPtr)[i] << " ";   // yes, we cen index through the array
    }

    std::cout << std::endl;

    return 0;
}