#include <iostream>
#include <string>
#include "../inc/Dog.h"
#include "../inc/DogHouse.h"

int main()
{
    DogHouse
        fidos(Dog::make("Fido"), "FidoHouse"),
        spots(Dog::make("Spot"), "SpotHouse");

    std::cout << "Entering copy-construction" << std::endl;

    DogHouse bobs(fidos);

    std::cout << "After copy-constructing bobs" << std::endl;
    std::cout << "fidos:" << fidos << std::endl;
    std::cout << "spots:" << spots << std::endl;
    std::cout << "bobs:" << bobs << std::endl;
    std::cout << "Entering spots = fidos" << std::endl;
    
    spots = fidos;

    std::cout << "After spots = fidos" << std::endl;
    std::cout << "spots:" << spots << std::endl;
    std::cout << "Entering self-assignment" << std::endl;

    bobs = bobs;

    std::cout << "After self-assignment" << std::endl;
    std::cout << "bobs:" << bobs << std::endl;

    std::cout << "Entering rename(\"Bob\")" << std::endl;
    bobs.getDog()->rename("Bob");
    std::cout << "After rename(\"Bob\")" << std::endl;

    return 0;
}