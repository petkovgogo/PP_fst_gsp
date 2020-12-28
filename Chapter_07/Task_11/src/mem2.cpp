#include <cstring>
#include "../inc/Mem2.h"

Mem::Mem(int size)
{
    m_mem = 0;
    m_size = 0;

    ensureMinSize(size);

    m_oldMem = m_mem;
}

Mem::~Mem()
{
    moved(); // to ensure m_oldMem points to the same address as m_mem so both of them get deleted with the next statement

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

        m_mem = newMem;
        m_size = minSize;
    }
}

int Mem::msize()
{
    return m_size;
}

// ANSWER
// I don't see a purpose for this function. I think calling pointer() for every use is enough.
// There is no need to know if the storage address moved. The only thing we can get from the function
// is that the array expanded, and I don't see how that information can be useful to us. The whole point of
// Mem is automatic memory management. It expands and deletes the array on its own. There is no need for the client
// programmer to know if the pointer moved.
bool Mem::moved()
{
    if (m_oldMem == pointer())
    {
        return false; // memory has not been reallocated
    }

    delete[] m_oldMem;
    m_oldMem = m_mem;

    return true; // memory has been reallocated
}

byte *Mem::pointer(int minSize)
{
    ensureMinSize(minSize);

    return m_mem;
}