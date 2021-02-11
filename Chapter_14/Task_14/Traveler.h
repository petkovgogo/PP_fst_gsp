#ifndef TRAVELER_H
#define TRAVELER_H

#include <iostream>

class Traveler
{
private:
    const char *m_str;

public:
    Traveler(const char *str);
    Traveler(const Traveler &traveler);

    Traveler &operator=(const Traveler &origin);
    friend std::ostream &operator<<(std::ostream &out, const Traveler &traveler);
};

inline Traveler::Traveler(const char *str) : m_str(str) {}
inline Traveler::Traveler(const Traveler &traveler) : m_str(traveler.m_str) {}

inline Traveler &Traveler::operator=(const Traveler &origin)
{
    if (this != &origin)
    {
        m_str = origin.m_str;   
    }

    return *this;
}

inline std::ostream &operator<<(std::ostream &out, const Traveler &traveler)
{
    return out << traveler.m_str;
}

#endif // TRAVELER_H