#ifndef BLUE_HAMSTER_H
#define BLUE_HAMSTER_H

#include <iostream>
#include "Hamster.h"

class BlueHamster : public Hamster
{
public:
    void gnaw();
    void squeak();
};

inline void BlueHamster::gnaw() { std::cout << "Mmmm, this pear sure is delicious.\n"; }
inline void BlueHamster::squeak() { std::cout << "Squeak squeak I am a happy BlueHamster.\n"; }

#endif // BLUE_HAMSTER_H