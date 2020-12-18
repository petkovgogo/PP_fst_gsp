#include <iostream>
#include "Handle.h"

struct Handle::Cheshire
{
    int i;
};

void Handle::initialize()
{
    smile = new Cheshire;
    smile->i = 0;
}

void Handle::cleanup()
{
    std::cout << "Deleting smile..." << std::endl; // Changed the implementation
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