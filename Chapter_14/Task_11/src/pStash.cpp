#include "../inc/PStash.h"
#include <iostream>
#include <cstring>
#include <cassert>

PStash::PStash() :  m_storage(0), m_quantity(0), m_next(0) {}

// No ownership:
PStash::~PStash()
{
    for (int i = 0; i < m_next; i++)
    {
        assert(m_storage[i] == 0);
    }

    delete[] m_storage;
}

int PStash::add(void *element)
{
    const int inflateSize = m_quantity * 2 + 1;

    if (m_next >= m_quantity)
    {
        inflate(inflateSize);
    }

    m_storage[m_next] = element;

    return m_next++; // Index number
}

// Operator overloading replacement for fetch
void *PStash::operator[](int index) const
{
    assert(index >= 0);

    if (index >= m_next)
    {
        return 0; // To indicate the end
    }

    // Produce pointer to desired element:
    return m_storage[index];
}

void *PStash::remove(int index)
{
    void *v = operator[](index);

    // "Remove" the pointer:
    if (v != 0)
    {
        m_storage[index] = 0;
    }

    return v;
}

int PStash::count() const { return m_next; }

void PStash::inflate(int increase)
{
    const int P_SIZE = sizeof(void *);
    void **newStorage = new void *[m_quantity + increase];

    memset(newStorage, 0, (m_quantity + increase) * P_SIZE);
    memcpy(newStorage, m_storage, m_quantity * P_SIZE);

    m_quantity += increase;

    delete[] m_storage;     // Old storage
    m_storage = newStorage; // Point to new memory
}