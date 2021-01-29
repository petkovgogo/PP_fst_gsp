#include <iostream>

class Integer
{
private:
    int m_num;

public:
    Integer(int num = 0) : m_num(num) {}

    friend const Integer operator+(const Integer &loperand, const Integer &roperand);
    friend const Integer operator-(const Integer &loperand, const Integer &roperand);
    friend std::ostream &operator<<(std::ostream &out, const Integer &integer);
};

const Integer operator+(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_num + roperand.m_num); }
const Integer operator-(const Integer &loperand, const Integer &roperand) { return Integer(loperand.m_num - roperand.m_num); }

std::ostream &operator<<(std::ostream &out, const Integer &integer)
{
    out << integer.m_num;
    
    return out;
}

int main()
{
    Integer int1(42);
    Integer int2(451);
    Integer int3(12);

    std::cout << (int1 + int2 - int3) << std::endl;

    return 0;
}