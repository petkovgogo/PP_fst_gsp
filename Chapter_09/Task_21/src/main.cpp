#include <iostream>
#include <fstream>
#include "../inc/Require.h"

#define IFOPEN(VAR, NAME)    \
    std::ifstream VAR(NAME); \
    assure(VAR, NAME);

int main()
{
    IFOPEN(in, "in.txt");

    std::cout << "Successfuly opened file" << std::endl;

    return 0;
}
