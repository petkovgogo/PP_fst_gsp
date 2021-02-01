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

    BirdHouse(BirdHouse &);
    Bird &operator=(Bird &);

public:
    BirdHouse(Bird birdObj, Bird *birdPtr, Bird &birdRef);

    friend std::ostream &operator<<(std::ostream &out, BirdHouse &house);
};

#endif // BIRD_HOUSE_H