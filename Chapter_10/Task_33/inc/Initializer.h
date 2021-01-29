#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "../inc/Mirror.h"

extern Mirror *gMirror;
extern Mirror *mirror1;
extern Mirror *mirror2;
extern Mirror *mirror3;
extern Mirror *mirror4;

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