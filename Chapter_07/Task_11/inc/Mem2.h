#ifndef MEM2_H
#define MEM2_H

typedef unsigned char byte;

class Mem
{
    byte *m_mem;
    byte *m_oldMem;
    int m_size;

    void ensureMinSize(int minSize);

public:
    Mem(int size = 0);
    ~Mem();

    int msize();
    bool moved();
    byte *pointer(int minSize = 0);
};

#endif // MEM2_H