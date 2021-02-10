#ifndef ASTEROID_STASH_H
#define ASTEROID_STASH_H

// #define USE_INHERITANCE

#include "Asteroid.h"
#include "PStash.h"

#ifdef USE_INHERITANCE

class AsteroidStash : public PStash
{

#else

class AsteroidStash
{
private:
    PStash m_storage;

#endif // USE_INHERITANCE
public:
    int add(Asteroid *element);
    Asteroid *operator[](int index) const; // Fetch

    // Remove the reference from this PStash:
    Asteroid *remove(int index);

#ifndef USE_INHERITANCE

    int count() const;

#endif // USE_INHERITANCE
};

#endif // ASTEROID_STASH_H