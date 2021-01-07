#include <cstring> // memset()
#include "../inc/Holder.h"

Holder::Holder()
{
    memset(arr, 0, SIZE * sizeof(int));
}

Holder::Pointer::Pointer(Holder *rv)
{
    h = rv;
    p = rv->arr;
}