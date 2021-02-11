#ifndef PAGER_H
#define PAGER_H

#include <iostream>

class Pager
{
private:
    const char *m_str;

public:
    Pager(const char *str);
    Pager(const Pager &pager);

    Pager &operator=(const Pager &origin);
    friend std::ostream &operator<<(std::ostream &out, const Pager &pager);
};

inline Pager::Pager(const char *str) : m_str(str) {}
inline Pager::Pager(const Pager &Pager) : m_str(Pager.m_str) {}

inline Pager &Pager::operator=(const Pager &origin)
{
    if (this != &origin)
    {
        m_str = origin.m_str;   
    }

    return *this;
}

inline std::ostream &operator<<(std::ostream &out, const Pager &pager)
{
    return out << pager.m_str << ((pager.m_str[0] == '\0') ? "" : "'s pager");
}

#endif // PAGER_H