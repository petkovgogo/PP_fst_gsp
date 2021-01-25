#ifndef MEM_H
#define MEM_H

typedef unsigned char byte;

class Mem
{
private:
    byte *m_mem;
    int m_size;
    void ensureMinSize(int minSize);

public:
    Mem(int sz = 0);
    ~Mem();
    int msize();

#ifdef FIXED_EXAMPLE

    byte *&pointer(int minSize = 0);

#else

    byte *pointer(int minSize = 0);

#endif // FIXED_EXAMPLE
};

#endif // MEM_H