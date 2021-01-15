#ifndef NAMESPACEMATH_H
#define NAMESPACEMATH_H

#include "NamespaceInt.h"

namespace Math
{
    using namespace Int;
    Integer divide(Integer &num1, Integer &num2)
    {
        return Integer(num1.getNum() / num2.getNum());
    }
} // namespace Math

#endif // NAMESPACEMATH_H