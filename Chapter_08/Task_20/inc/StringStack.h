#ifndef STRING_STACK_H
#define STRING_STACK_H

#include "MyString.h"

class StringStack
{
    static const int m_size = 100;
    MyString *m_stack[m_size];
    int m_index;

public:
    StringStack();
    ~StringStack();
    
    void push(MyString *s);
    const MyString *pop();
};

#endif // STRING_STACK_H