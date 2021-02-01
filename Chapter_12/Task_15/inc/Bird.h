#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <string>

class Bird
{
private:
    std::string m_id;

public:
    Bird();
    Bird(const Bird &origin);

    Bird &operator=( const Bird &origin);

    friend std::ostream &operator<<(std::ostream &out, const Bird &bird);
};

#endif // BIRD_H