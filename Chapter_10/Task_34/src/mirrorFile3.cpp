#include "../inc/Mirror.h"

extern Mirror &m1();

Mirror &m2()
{
    static Mirror mirror2(m1());

    return mirror2;
}