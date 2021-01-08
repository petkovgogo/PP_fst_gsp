#include <iostream>
#include <string>

#define DEBUG(x) std::cout << #x " => " << x << std::endl;

int main(int argc, char const *argv[])
{
    if (argc < 2) // string is passed as second argument. The first is the name of the program
    {
        std::cerr << "There must be a string given as a second argument!\nTerminating program..." << std::endl;
        return 0;
    }

    std::string argStr(argv[1]);
    DEBUG(argStr);

    while (argStr.size() > 0)
    {
        argStr.pop_back();
        DEBUG(argStr);
    }

    return 0;
}
