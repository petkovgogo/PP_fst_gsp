#include <string>
#include "../inc/Libc.h"

Libc::Libc() {}

Libc::~Libc() {}

/*
void Libc::setA(std::string text)
{
    a = text;
}

void Libc::setB(std::string text)
{
    b = text;
}

void Libc::setC(std::string text)
{
    c = text;
}

std::string Libc::getA() const
{
    return a;
}

std::string Libc::getB() const
{
    return b;
}

std::string Libc::getC() const
{
    return c;
}
*/

void Libc::setA(std::string text)
{
    arr[0] = text;
}

void Libc::setB(std::string text)
{
    arr[1] = text;
}

void Libc::setC(std::string text)
{
    arr[2] = text;
}

std::string Libc::getA() const
{
    return arr[0];
}

std::string Libc::getB() const
{
    return arr[1];
}

std::string Libc::getC() const
{
    return arr[2];
}
