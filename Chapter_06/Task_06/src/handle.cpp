#include <iostream>
#include "../inc/Handle.h"

struct Handle::Cheshire
{
    int i;
};

Handle::Handle()
{
    std::cout << "Initializing smile" << std::endl;

    smile = new Cheshire;
    smile->i = 0;
}

Handle::~Handle()
{
    std::cout << "freeing storage..." << std::endl;
    delete smile;
}

int Handle::read()
{
    return smile->i;
}

void Handle::change(int x)
{
    smile->i = x;
}