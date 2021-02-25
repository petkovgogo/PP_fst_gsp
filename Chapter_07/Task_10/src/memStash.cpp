#include <cassert>
#include "../inc/Mem2.h"
#include "../inc/MemStash.h"

MemStash::MemStash(int dataSize, int initQuantity)
{
    m_dataSize = dataSize;
    m_elementCount = 0;
    m_mem = new Mem(m_dataSize * initQuantity);
}

MemStash::~MemStash()
{
    delete m_mem;
}

void MemStash::add(void *data)
{
    byte *storage;

    if (m_mem->msize() < m_dataSize * (m_elementCount + 1))
    {
        storage = m_mem->pointer(m_mem->msize() * 2);
    }
    else
    {
        storage = m_mem->pointer();
    }

    byte *element = (byte *)data;
    int startBytes = m_dataSize * m_elementCount;

    for (int i = 0; i < m_dataSize; i++)
    {
        storage[startBytes + i] = element[i];
    }

    m_elementCount++;
}

void *MemStash::fetch(int index)
{
    assert(index >= 0);

    if (index >= m_elementCount)
    {
        return 0;
    }
    

    return &(m_mem->pointer()[index * m_dataSize]);
}

int MemStash::count()
{
    return m_elementCount;
}