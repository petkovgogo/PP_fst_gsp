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
    Bird(Bird &origin);

    Bird &operator=(Bird &origin);

    friend std::ostream &operator<<(std::ostream &out, Bird &bird);
};

#endif // BIRD_H