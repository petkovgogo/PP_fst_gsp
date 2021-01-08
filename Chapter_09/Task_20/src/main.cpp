#include <fstream>
#include "../inc/Require.h"

int main(int argc, char const *argv[])
{
    requireArgs(argc, 2);

    int num = atoi(argv[1]);
    require((num > 5 && num < 10), "Number must be between 5 and 10");

    std::ifstream in(argv[2]);
    assure(in, argv[2]);

    return 0;
}
