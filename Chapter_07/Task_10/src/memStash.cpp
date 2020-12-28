#include <cassert>
#include "../inc/Mem2.h"
#include "../inc/MemStash.h"

const int INFLATE_SIZE = 20;

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

    if (m_mem->msize() < m_dataSize * m_elementCount)
    {
        storage = m_mem->pointer(m_mem->msize() + INFLATE_SIZE);
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

void *MemStash::get(int index)
{
    assert(index < m_elementCount);

    return &(m_mem->pointer()[index * m_dataSize]);
}

int MemStash::size()
{
    return m_elementCount;
}