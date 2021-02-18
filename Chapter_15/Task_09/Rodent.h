#ifndef RODENT_H
#define RODENT_H

#include <iostream>

#define VIRTUAL_DESTRUCTOR

class Rodent
{
public:
#ifdef VIRTUAL_DESTRUCTOR

    virtual ~Rodent();

#else

    ~Rodent();

#endif // VIRTUAL_DESTRUCTOR

    virtual void gnaw() = 0;
    virtual void move() = 0;
    virtual void hide() = 0;
    virtual void squeak() = 0;
};

inline Rodent::~Rodent() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

#endif // RODENT_H