#include "../inc/AsteroidStash.h"
#include "../inc/Asteroid.h"
#include "../inc/PStash.h"

int AsteroidStash::add(Asteroid *element)
{
#ifdef USE_INHERITANCE

    return PStash::add(reinterpret_cast<void *>(element));

#else

    return m_storage.add(reinterpret_cast<void *>(element));

#endif // USE_INHERITANCE
}

Asteroid *AsteroidStash::operator[](int index) const
{
#ifdef USE_INHERITANCE

    return reinterpret_cast<Asteroid *>(PStash::operator[](index));

#else

    return reinterpret_cast<Asteroid *>(m_storage[index]);

#endif // USE_INHERITANCE
}

Asteroid *AsteroidStash::remove(int index)
{
#ifdef USE_INHERITANCE

    return reinterpret_cast<Asteroid *>(PStash::remove(index));

#else

    return reinterpret_cast<Asteroid *>(m_storage.remove(index));

#endif // USE_INHERITANCE
}

#ifndef USE_INHERITANCE

int AsteroidStash::count() const { return m_storage.count(); }

#endif // USE_INHERITANCE