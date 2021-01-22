#include <stdio.h>
int main()
{
    struct Bird *pBird;
    struct Rock *pRock;
    void *unknownPtr;

    unknownPtr = pBird;
    // pRock = unknownPtr; // error: invalid conversion

    puts("Compiled successfuly");

    return 0;
}