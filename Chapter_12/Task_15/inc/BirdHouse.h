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

    BirdHouse(const BirdHouse &);
    Bird &operator=(const Bird &);

public:
    BirdHouse(Bird birdObj, Bird *birdPtr, Bird &birdRef);

    friend std::ostream &operator<<(std::ostream &out, const BirdHouse &house);
};

#endif // BIRD_HOUSE_H