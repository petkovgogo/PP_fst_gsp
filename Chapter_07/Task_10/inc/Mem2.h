#ifndef MEM2_H
#define MEM2_H

typedef unsigned char byte;

class Mem
{
    byte *m_mem;
    int m_size;
    void ensureMinSize(int minSize);

public:
    Mem(int size = 0);
    ~Mem();
    
    int msize();
    byte *pointer(int minSize = 0);
};

#endif // MEM2_H