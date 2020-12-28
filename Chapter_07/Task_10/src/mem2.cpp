#include <cstring>
#include "../inc/Mem2.h"

Mem::Mem(int size)
{
    m_mem = 0;
    m_size = 0;

    ensureMinSize(size);
}

Mem::~Mem()
{
    delete[] m_mem;
}

void Mem::ensureMinSize(int minSize)
{
    if (m_size < minSize)
    {
        byte *newMem = new byte[minSize];

        // Initialize the block of memory from the ocupied spaces to the min size, without touching the existing data
        // Set the bytes in the range [m_size; minSize) to zero, starting from the address after the existing data
        memset(newMem + m_size, 0, minSize - m_size);

        // Copy the existing data into the new array, starting from the address of m_mem for m_size bytes
        memcpy(newMem, m_mem, m_size);

        delete[] m_mem;

        m_mem = newMem;
        m_size = minSize;
    }
}

int Mem::msize()
{
    return m_size;
}

byte *Mem::pointer(int minSize)
{
    ensureMinSize(minSize);

    return m_mem;
}