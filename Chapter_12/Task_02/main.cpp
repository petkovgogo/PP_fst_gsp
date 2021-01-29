#include <iostream>

class Integer
{
private:
    int m_num;

public:
    Integer(int num = 0) : m_num(num) {}

    Integer operator+(Integer &op) { return Integer(m_num + op.m_num); }
    void print(std::ostream &out) const
    {
        out << m_num << std::endl;
    }
};

int main()
{
    Integer int1(42);
    Integer int2(451);

    (int1 + int2).print(std::cout);

    return 0;
}