#ifndef ASTEROID_STASH_H
#define ASTEROID_STASH_H

// #define USE_INHERITANCE

#include <vector>
#include "Asteroid.h"

#ifdef USE_INHERITANCE

class AsteroidVector : public std::vector<void *>
{

#else

class AsteroidVector
{
private:
    std::vector<void *> m_storage;

#endif // USE_INHERITANCE
public:
    void push_back(Asteroid *element);
    Asteroid *operator[](int index) const; // Fetch

    // Remove the reference from this PStash:
    Asteroid *remove(int index);

#ifndef USE_INHERITANCE

    size_t size() const;

#endif // USE_INHERITANCE
};

#endif // ASTEROID_STASH_H