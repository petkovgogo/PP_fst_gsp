#include <iostream>
#include "../inc/Colour.h"

int main()
{
    Colour colour(RED);

    std::cout << "Initial colour: " << hueToText(colour.colour()) << std::endl;

    colour.colour(YELLOW);

    std::cout << "After change: " << hueToText(colour.colour()) << std::endl;

    return 0;
}