#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include "../inc/Mem.h"

class MyString
{
    Mem *m_buf;

public:
    MyString();
    MyString(const char *str);
    ~MyString();
    void concat(const char *str);
    void print(std::ostream &os);
};

#endif // MY_STRING_H