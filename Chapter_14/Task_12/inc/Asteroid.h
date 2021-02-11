#ifndef ASTEROID_H
#define ASTEROID_H

class Asteroid
{
private:
    int m_size;    

public:
    Asteroid(int size) : m_size(size) {}

    int getSize() const { return m_size; }
};

#endif // ASTEROID_H