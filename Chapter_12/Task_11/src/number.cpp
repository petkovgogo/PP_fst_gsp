#include "../inc/Number.h"

Number::Number(double num) : m_num(num) {}

Number &Number::operator=(const Number &number)
{
    this->m_num = number.m_num;
    return *this;
}

Number::operator int() const { return static_cast<int>(m_num); }

const Number operator+(const Number &num1, const Number &num2) { return Number(num1.m_num + num2.m_num); }
const Number operator-(const Number &num1, const Number &num2) { return Number(num1.m_num - num2.m_num); }
const Number operator*(const Number &num1, const Number &num2) { return Number(num1.m_num * num2.m_num); }
const Number operator/(const Number &num1, const Number &num2) { return Number(num1.m_num / num2.m_num); }

std::ostream &operator<<(std::ostream &out, const Number &num)
{
    out << num.m_num;

    return out;
}