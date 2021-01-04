#include <iostream>

class Floats
{
    const float m_num1;
    float m_num2;

public:
    Floats(const float num1, float num2);
    void printNums();
};

Floats::Floats(const float num1, float num2) : m_num1(num1)
{
    m_num2 = num2;
}

void Floats::printNums() 
{
    std::cout << "Num1: " << m_num1 << "\nNum2: " << m_num2 << std::endl;
}

int main()
{
    const float NUM1 = 3.14F;
    float num2 = 6.63F;

    Floats floats(NUM1, num2);

    floats.printNums();

    return 0;
}