#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>

class Aircraft
{
public:
    virtual ~Aircraft() = 0;

    virtual void print(std::ostream &out) const = 0;

    virtual void board() const = 0;
    virtual void prepare() const = 0;
    virtual void standby() const = 0;
    virtual void takeoff() const = 0;
    virtual void fly() const = 0;
    virtual void land() const = 0;

    friend std::ostream &operator<<(std::ostream &out, Aircraft &ac);
};

inline Aircraft::~Aircraft() {}

inline std::ostream &operator<<(std::ostream &out, Aircraft &ac)
{
    ac.print(out);

    return out;
}

#endif // AIRCRAFT_H