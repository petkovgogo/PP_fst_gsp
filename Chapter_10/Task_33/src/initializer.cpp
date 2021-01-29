#include <iostream>
#include "../inc/Initializer.h"
#include "../inc/Mirror.h"

int Initializer::initCount = 0;

Initializer::Initializer()
{
    std::cout << "Initializer()" << std::endl;

    // Initialize first time only
    if (initCount++ == 0)
    {
        std::cout << "performing initialization" << std::endl;

        gMirror = new Mirror();
        mirror1 = new Mirror(*gMirror);
        mirror2 = new Mirror(*mirror1);
        mirror3 = new Mirror(*mirror2);
        mirror4 = new Mirror(*mirror3);
    }
}

Initializer::~Initializer()
{
    std::cout << "~Initializer()" << std::endl;

    if (--initCount == 0)
    {
        std::cout << "performing cleanup" << std::endl;

        delete gMirror;
        delete mirror1;
        delete mirror2;
        delete mirror3;
        delete mirror4;
    }
}