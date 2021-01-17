#ifndef ARRAY_HOLDER_H
#define ARRAY_HOLDER_H

#include "StringHolder.h"

class ArrayHolder
{
private:
    static const StringHolder m_constHolderArr[];
    static StringHolder m_holderArr[];
    
public:
    static void printConstArr();
    static void printArr();
};

#endif // ARRAY_HOLDER_H