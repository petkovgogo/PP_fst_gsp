#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        std::cout << atol(argv[i]) << std::endl;
    }
    
    return 0;
}