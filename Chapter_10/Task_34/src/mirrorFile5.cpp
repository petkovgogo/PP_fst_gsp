#include "../inc/Mirror.h"

#include <iostream>

extern Mirror &m3();

Mirror &m4()
{
    static Mirror mirror4(m3());

    return mirror4;
}

int main()
{
    Mirror &mirror4 = m4();

    std::cout << (mirror4.test() ? "true" : "false") << std::endl;

    return 0;
}