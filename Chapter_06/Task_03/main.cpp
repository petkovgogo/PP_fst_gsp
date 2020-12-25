#include <iostream>

class Simple
{
    int m_number;

public:
    Simple(int number);
    ~Simple();
};

Simple::Simple(int number)
{
    m_number = number;
    std::cout << "I am created with the value " << m_number << std::endl;
}

Simple::~Simple()
{
    std::cout << "I still hold the value " << m_number << ", but my existance ends here" << std::endl;
}

int main()
{
    const int NUMBER = 42;

    Simple simple(NUMBER);

    return 0;
}