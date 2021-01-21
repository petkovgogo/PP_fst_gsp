#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "../inc/Mirror.h"

extern Mirror gMirror;

class Initializer
{
private:
    static int initCount;

public:
    Initializer();
    ~Initializer();
};

static Initializer init;

#endif // INITIALIZER_H