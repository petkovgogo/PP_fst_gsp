#include "../inc/Initializer.h"

#include <iostream>
#include "../inc/Mirror.h"

Mirror *mirror4;

int main()
{
    std::cout << (mirror4->test() ? "true" : "false") << std::endl;

    return 0;
}