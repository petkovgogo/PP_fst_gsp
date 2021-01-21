#include "../inc/Mirror.h"

Mirror &initMirror()
{
    static Mirror gMirror;

    return gMirror;
}