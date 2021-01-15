#ifndef NAMESPACE_CALCULATION_H
#define NAMESPACE_CALCULATION_H

#include "NamespaceInt.h"

namespace Calculation
{
    using namespace Int;
    Integer divide(Integer &num1, Integer &num2)
    {
        return Integer(num1.getNum() / num2.getNum());
    }
} // namespace Calculation

#endif // NAMESPACE_CALCULATION_H