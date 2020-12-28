#include <iostream>
#include "../inc/Mem2.h"

void copyContents(byte *dest, byte *source, int startBytes)
{
    for (int i = 0; i < sizeof(int); i++)
    {
        dest[startBytes + i] = source[i];
    }

    delete source;
}

int main()
{
    Mem intMem(sizeof(int));

    byte *storage = intMem.pointer();
    byte *integerBytes = (byte *)new int(42);

    copyContents(storage, integerBytes, 0);

    std::cout << "Moved: " << intMem.moved() << std::endl;

    storage = intMem.pointer(sizeof(int) * 2);
    integerBytes = (byte *)new int(415);

    copyContents(storage, integerBytes, sizeof(int));

    std::cout << "Moved: " << intMem.moved() << std::endl;

    std::cout << "1st int: " << *(int *)storage << std::endl;
    std::cout << "2nd int: " << *(int *)(&storage[sizeof(int)]) << std::endl;

    return 0;
}