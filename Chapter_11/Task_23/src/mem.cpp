#include "../inc/Mem.h"
#include <cstring>

Mem::Mem(int sz)
{
    m_mem = 0;
    m_size = 0;
    ensureMinSize(sz);
}

Mem::~Mem() { delete[] m_mem; }

int Mem::msize() { return m_size; }

void Mem::ensureMinSize(int minSize)
{
    if (m_size < minSize)
    {
        byte *newmem = new byte[minSize];

        memset(newmem + m_size, 0, minSize - m_size);
        memcpy(newmem, m_mem, m_size);

        delete[] m_mem;
        m_mem = newmem;
        m_size = minSize;
    }
}

#ifdef FIXED_EXAMPLE

byte *&Mem::pointer(int minSize)

#else

byte *Mem::pointer(int minSize)

#endif // FIXED_EXAMPLE

{
    ensureMinSize(minSize);
    return m_mem;
}