#include <string>
#include <cstring>
#include "../inc/StringStack.h"

StringStack::StringStack() : index(0)
{
    memset(stack, 0, SIZE * sizeof(std::string *));
}