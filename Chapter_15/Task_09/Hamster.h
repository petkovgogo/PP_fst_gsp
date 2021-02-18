#ifndef HAMSTER_H
#define HAMSTER_H

#include <iostream>
#include "Rodent.h"

class Hamster : public Rodent
{
public:
    ~Hamster();

    void gnaw();
    void move();
    void hide();
    void squeak();
};

inline Hamster::~Hamster() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

inline void Hamster::gnaw() { std::cout << "Yumm, this carrot is nice.\n"; }
inline void Hamster::move() { std::cout << "I just LOVE running in this wheel all day.\n"; }
inline void Hamster::squeak() { std::cout << "Squeak squeak I am a happy Hamster.\n"; }

inline void Hamster::hide()
{
    std::cout << "That owl is glaring strangely at me. "
                 "Good that it's outside the window. "
                 "I am still going to hide though.\n";
}

#endif // HAMSTER_H