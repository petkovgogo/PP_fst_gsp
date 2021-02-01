#include "../inc/Bird.h"

#include <iostream>
#include <string>

Bird::Bird()
{
    static int id;
    m_id = "Bird #" + std::to_string(++id);
}

Bird::Bird(Bird &origin) : m_id(origin.m_id) {}

Bird &Bird::operator=(Bird &origin)
{
    if (this != &origin)
    {
        m_id = origin.m_id;
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, Bird &bird)
{
    out << bird.m_id;

    return out;
}