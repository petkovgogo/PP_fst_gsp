#ifndef STRING_STACK_H
#define STRING_STACK_H

#include <string>

class StringStack
{
    static const int SIZE = 100;
    const std::string *stack[SIZE];
    int index;

public:
    StringStack();
    void push(const std::string *s);
    const std::string *pop();
};

inline void StringStack::push(const std::string *s)
{
    if (index < SIZE)
    {
        stack[index++] = s;
    }
}

inline const std::string *StringStack::pop()
{
    if (index > 0)
    {
        const std::string *rv = stack[--index];
        stack[index] = 0;

        return rv;
    }

    return 0;
}

#endif // STRING_STACK_H