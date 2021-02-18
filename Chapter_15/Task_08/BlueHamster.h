#ifndef BLUE_HAMSTER_H
#define BLUE_HAMSTER_H

#include <iostream>
#include "Hamster.h"

class BlueHamster : public Hamster
{
public:
    void gnaw() const;
    void squeak() const;
};

inline void BlueHamster::gnaw() const { std::cout << "Mmmm, this pear sure is delicious.\n"; }
inline void BlueHamster::squeak() const { std::cout << "Squeak squeak I am a happy BlueHamster.\n"; }

#endif // BLUE_HAMSTER_H