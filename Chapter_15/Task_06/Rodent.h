#ifndef RODENT_H
#define RODENT_H

class Rodent
{
public:
    virtual ~Rodent() {};

    virtual void gnaw() = 0;
    virtual void move() = 0;
    virtual void hide() = 0;
    virtual void squeak() = 0;
};


#endif // RODENT_H