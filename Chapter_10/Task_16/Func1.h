#ifndef FUNC_1_H
#define FUNC_1_H

#include <iostream>

#define FUNC_CREATOR(NAME) \
    void NAME() { std::cout << "Hello! I am " #NAME << std::endl; }

namespace namespaceWithAReallyLongName
{
    FUNC_CREATOR(func1);
    FUNC_CREATOR(func2);
    FUNC_CREATOR(func3);
} // namespace namespaceWithAReallyLongName

#endif // FUNC_1_H