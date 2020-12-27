#include <iostream>
#include <cstring>
#include "../inc/Mem2.h"

class MyString
{
    Mem *buf;

public:
    MyString();
    MyString(const char *str);
    ~MyString();

    void concat(const char *str);
    void print(std::ostream &os);
};

MyString::MyString()
{
    buf = 0;
}

MyString::MyString(const char *str)
{
    buf = new Mem(strlen(str) + 1);
    strcpy((char *)buf->pointer(), str);
}

MyString::~MyString()
{
    delete buf;
}

void MyString::concat(const char *str)
{
    if (!buf)
    {
        buf = new Mem;
    }

    strcat((char *)buf->pointer(buf->msize() + strlen(str) + 1), str);
}

void MyString::print(std::ostream &os)
{
    if (buf)
    {
        os << buf->pointer() << std::endl;
    }
}

int main()
{
    MyString s("My test string");

    s.print(std::cout);
    s.concat(" some additional stuff");
    s.print(std::cout);

    MyString s2;

    s2.concat("Using default constructor");
    s2.print(std::cout);

    return 0;
}