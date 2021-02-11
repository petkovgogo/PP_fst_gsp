#include "../inc/AsteroidStash.h"
#include "../inc/Asteroid.h"

void AsteroidVector::push_back(Asteroid *element)
{
#ifdef USE_INHERITANCE

    return std::vector<void *>::push_back(reinterpret_cast<void *>(element));

#else

    return m_storage.push_back(reinterpret_cast<void *>(element));

#endif // USE_INHERITANCE
}

Asteroid *AsteroidVector::operator[](int index) const
{
#ifdef USE_INHERITANCE

    return reinterpret_cast<Asteroid *>(std::vector<void *>::operator[](index));

#else

    return reinterpret_cast<Asteroid *>(m_storage[index]);

#endif // USE_INHERITANCE
}

Asteroid *AsteroidVector::remove(int index)
{
    Asteroid *element;

#ifdef USE_INHERITANCE

    element = reinterpret_cast<Asteroid *>(std::vector<void *>::operator[](index));
    std::vector<void *>::erase(std::vector<void *>::begin() + index);

#else

    element = reinterpret_cast<Asteroid *>(m_storage[index]);
    m_storage.erase(m_storage.begin() + index);

#endif // USE_INHERITANCE

    return element;
}

#ifndef USE_INHERITANCE

size_t AsteroidVector::size() const
{
    return m_storage.size();
}

#endif // USE_INHERITANCE