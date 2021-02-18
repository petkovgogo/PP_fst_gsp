#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <iostream>
#include "Aircraft.h"

class Helicopter : public Aircraft
{
public:
    void print(std::ostream &out) const;

    void board() const;
    void prepare() const;
    void standby() const;
    void takeoff() const;
    void fly() const;
    void land() const;
};

inline void Helicopter::print(std::ostream &out) const { out << "helicopter"; }

inline void Helicopter::board() const { std::cout << "Get in the chopper!!\n"; }
inline void Helicopter::prepare() const { std::cout << "Starting the rotors...\n"; }
inline void Helicopter::standby() const { std::cout << "Awaiting clearence for takeoff...\n"; }
inline void Helicopter::takeoff() const { std::cout << "Taking off, hold tight...\n"; }
inline void Helicopter::fly() const { std::cout << "Flying... ETA 45 min\n"; }
inline void Helicopter::land() const { std::cout << "Landing...\n"; }

#endif // HELICOPTER_H