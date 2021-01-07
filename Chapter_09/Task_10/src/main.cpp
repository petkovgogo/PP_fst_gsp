#include <iostream>
#include "../inc/Colour.h"

int main()
{
    Colour colour(RED);

    std::cout << "Initial colour: " << hueToText(colour.getColour()) << std::endl;

    colour.setColour(YELLOW);

    std::cout << "After change: " << hueToText(colour.getColour()) << std::endl;

    return 0;
}