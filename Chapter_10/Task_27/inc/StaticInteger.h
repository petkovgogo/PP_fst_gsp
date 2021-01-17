#ifndef STATIC_INTEGER_H
#define STATIC_INTEGER_H

#include "Integer.h"

class StaticInteger
{
private:
    static Integer m_integer;

public:
    static void print();
};

#endif // STATIC_INTEGER_H