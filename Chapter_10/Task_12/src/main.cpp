#include "../inc/IntContainer.h"

int main()
{
    extern IntContainer container;

    container.setNum(42);
    container.print();

    return 0;
}