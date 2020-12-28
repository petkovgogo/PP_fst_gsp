#ifndef MEM_STASH_H
#define MEM_STASH_H

#include "Mem2.h"

class MemStash
{
    int m_dataSize;
    int m_elementCount;
    Mem *m_mem;

public:
    MemStash(int dataSize, int initQuantity = 1);
    ~MemStash();

    void add(void *data);
    void *get(int index);
    int size();
};

#endif // MEM_STASH_H