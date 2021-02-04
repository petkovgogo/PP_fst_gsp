#include <iostream>

class Integer
{
private:
    int m_num;

public:
    Integer(int num) : m_num(num) {}

    friend const Integer operator+(const Integer &int1, const Integer &int2);
    friend std::ostream &operator<<(std::ostream &out, const Integer &integer);
};

class Double
{
private:
    double m_num;

public:
    Double(double num) : m_num(num) {}

    operator Integer() const { return Integer(static_cast<int>(m_num)); }
};



const Integer operator+(const Integer &int1, const Integer &int2) { return Integer(int1.m_num + int2.m_num); }
std::ostream &operator<<(std::ostream &out, const Integer &integer) { return out << integer.m_num; }

#define EVALUATE(EXP) \
    std::cout << #EXP " = " << EXP << std::endl;

int main()
{
    Integer int1(42);
    Integer int2(451);
    Double d1(6.63);
    Double d2(9.81);

    EVALUATE(int1 + int2)
    EVALUATE(int1 + d1)
    EVALUATE(d2 + int2)
    EVALUATE(d1 + d2)

    return 0;
}