#include "../inc/Bird.h"

#include <iostream>
#include <string>

Bird::Bird(int num) : m_num(num)
{
    static int id;
    m_id = "Bird #" + std::to_string(++id);
}

Bird::Bird(const Bird &origin) : m_id(origin.m_id), m_num(origin.m_num) {}

Bird &Bird::operator=(Bird &origin)
{
    if (this != &origin)
    {
        m_id = origin.m_id;
    }

    return *this;
}

const Bird operator+(const Bird &loperand, const Bird &roperand) { return Bird(loperand.m_num + roperand.m_num); }
const Bird operator-(const Bird &loperand, const Bird &roperand) { return Bird(loperand.m_num - roperand.m_num); }
const Bird operator*(const Bird &loperand, const Bird &roperand) { return Bird(loperand.m_num * roperand.m_num); }
const Bird operator/(const Bird &loperand, const Bird &roperand) { return Bird(loperand.m_num / roperand.m_num); }

std::ostream &operator<<(std::ostream &out, const Bird &bird)
{
    out << bird.m_id
        << " Number: " << bird.m_num;

    return out;
}