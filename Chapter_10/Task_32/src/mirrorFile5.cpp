#include "../inc/Mirror.h"

#include <iostream>

extern Mirror mirror3;

Mirror mirror4(mirror3);

int main()
{
    // I tried to change the linking by compiling the files in different order (e.g. 1, 4, 5, 3, 2, then 2, 4, 1, 5, 3 and etc.),
    // but the output was always true. I also tried compiling the files one-by-one and linking the .o files
    // in different order, but the result was the same

    std::cout << (mirror4.test() ? "true" : "false") << std::endl;

    return 0;
}