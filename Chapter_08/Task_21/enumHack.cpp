#include <iostream>

class Numbers
{
    enum
    {
        ARR_SIZE = 7
    };

    const int M_NUM;
    int m_arr[ARR_SIZE];

public:
    Numbers();

    void printArr();
};

Numbers::Numbers() : M_NUM(42)
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        m_arr[i] = M_NUM + i;
    }
}

void Numbers::printArr()
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        std::cout << m_arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    Numbers numbers;

    numbers.printArr();

    return 0;
}