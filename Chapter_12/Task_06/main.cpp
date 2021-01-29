#include <iostream>

class Integer
{
private:
    int m_num;

public:
    Integer(int num = 0) : m_num(num) {}

    const Integer operator+(const Integer &op) const { return Integer(m_num + op.m_num); }
    friend std::ostream &operator<<(std::ostream &out, const Integer &integer);
};

std::ostream &operator<<(std::ostream &out, const Integer &integer)
{
    out << integer.m_num;
    
    return out;
}

int main()
{
    Integer int1(42);
    Integer int2(451);

    std::cout << (int1 + int2) << std::endl;

    return 0;
}