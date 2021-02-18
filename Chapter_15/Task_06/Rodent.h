#ifndef RODENT_H
#define RODENT_H

class Rodent
{
public:
    virtual ~Rodent() = 0;

    virtual void gnaw() const = 0;
    virtual void move() const = 0;
    virtual void hide() const = 0;
    virtual void squeak() const = 0;
};

inline Rodent::~Rodent() {};

#endif // RODENT_H