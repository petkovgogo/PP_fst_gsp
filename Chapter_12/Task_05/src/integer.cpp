#include "../inc/Integer.h"

#include <iostream>

Integer::Integer(int num) : m_num(num) {}

const Integer Integer::operator+(const Integer &rval) const { return Integer(m_num + rval.m_num); }
const Integer Integer::operator-(const Integer &rval) const { return Integer(m_num - rval.m_num); }

Integer &Integer::operator++()
{
    ++m_num;
    return *this;
}

const Integer Integer::operator++(int)
{
    Integer temp(*this);
    m_num++;

    return temp;
}

Integer &Integer::operator--()
{
    --m_num;
    return *this;
}

const Integer Integer::operator--(int)
{
    Integer temp(*this);
    m_num--;

    return temp;
}

void Integer::print(std::ostream &out) const
{
    out << m_num << std::endl;
}