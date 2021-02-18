#include "Rodent.h"
#include "Hamster.h"

int main()
{
    Rodent *rodentPtr = new Hamster;
    delete rodentPtr;

    return 0;
}