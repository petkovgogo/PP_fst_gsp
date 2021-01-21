#include <iostream>
#include "../inc/Initializer.h"
#include "../inc/Mirror.h"

int Initializer::initCount = 0;
Mirror *pExternMirror = &gMirror;

Initializer::Initializer()
{
    std::cout << "Initializer()" << std::endl;

    // Initialize first time only
    if (initCount++ == 0)
    {
        std::cout << "performing initialization" << std::endl;

        pExternMirror = new Mirror();
    }
}

Initializer::~Initializer()
{
    std::cout << "~Initializer()" << std::endl;

    if (--initCount == 0)
    {
        std::cout << "performing cleanup" << std::endl;

        delete pExternMirror;
    }
}