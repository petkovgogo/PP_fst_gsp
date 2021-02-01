#ifndef BIRD_HOUSE_H
#define BIRD_HOUSE_H

#include "Bird.h"

#include <iostream>

class BirdHouse
{
private:
    Bird m_birdObj;
    Bird *m_birdPtr;
    Bird &m_birdRef;

    bool m_needsCleanup;

    BirdHouse(const BirdHouse &bh);
    Bird &operator=(Bird &);

public:
    BirdHouse(const Bird birdObj, Bird *birdPtr, Bird &birdRef);
    ~BirdHouse();

    const BirdHouse operator+(const BirdHouse &roperand) const;
    const BirdHouse operator-(const BirdHouse &roperand) const;
    const BirdHouse operator*(const BirdHouse &roperand) const;
    const BirdHouse operator/(const BirdHouse &roperand) const;

    friend std::ostream &operator<<(std::ostream &out, const BirdHouse &house);
};

#endif // BIRD_HOUSE_H