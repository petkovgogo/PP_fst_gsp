#include "../inc/Mirror.h"

extern Mirror &initMirror();

Mirror &m1()
{
    static Mirror mirror1(initMirror());

    return mirror1;
}