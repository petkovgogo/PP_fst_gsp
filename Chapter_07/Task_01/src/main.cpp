#include <iostream>
#include "../inc/Text.h"

int main()
{
    const char *FILE_PATH = "../inc/dummy.txt";

    Text text(FILE_PATH);

    std::cout << text.contents() << std::endl;

    return 0;
}
