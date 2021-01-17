#include "../inc/StaticInteger.h"

#include "../inc/Integer.h"

Integer StaticInteger::m_integer(42);

void StaticInteger::print()
{
    m_integer.print();
}