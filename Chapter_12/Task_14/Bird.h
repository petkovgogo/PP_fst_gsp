#ifndef BIRD_H
#define BIRD_H

#include <string>

class Bird
{
private:
    std::string m_id;

public:
    Bird();
    Bird(const Bird &origin);

    Bird &operator=(const Bird &origin);

    friend std::ostream &operator<<(std::ostream &out, const Bird &bird);
};

inline Bird::Bird()
{
    static int id;
    m_id = "Bird #" + std::to_string(++id);
}

inline Bird::Bird(const Bird &origin) : m_id(origin.m_id) {}

inline Bird &Bird::operator=(const Bird &origin)
{
    if (this != &origin)
    {
        m_id = origin.m_id;
    }

    return *this;
}

inline std::ostream &operator<<(std::ostream &out, const Bird &bird)
{
    out << bird.m_id;

    return out;
}

#endif // BIRD_H