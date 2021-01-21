#include "../inc/Mirror.h"

extern Mirror &m2();

Mirror &m3()
{
    static Mirror mirror3(m2());

    return mirror3;
}