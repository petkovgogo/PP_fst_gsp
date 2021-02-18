#ifndef RODENT_H
#define RODENT_H

#include <iostream>

#define VIRTUAL_DESTRUCTOR

class Rodent
{
public:
#ifdef VIRTUAL_DESTRUCTOR

    virtual ~Rodent() = 0;

#else

    ~Rodent();

#endif // VIRTUAL_DESTRUCTOR

    virtual void gnaw() const = 0;
    virtual void move() const = 0;
    virtual void hide() const = 0;
    virtual void squeak() const = 0;
};

inline Rodent::~Rodent() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

#endif // RODENT_H