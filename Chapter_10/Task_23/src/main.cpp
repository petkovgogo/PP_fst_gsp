#include <iostream>
#include "../inc/Bird1.h"
#include "../inc/Bird2.h"

void doBirdThings()
{
#ifdef BIRD1

    using bird1::Bird;

#else

    using bird2::Bird;

#endif // BIRD1

    Bird parrot("Parrot");
    Bird sparrow("Sparrow");

    std::cout << parrot.getSpecies() << ": " << std::endl;
    parrot.makeNest();

    std::cout << sparrow.getSpecies() << ": " << std::endl;
    sparrow.makeNest();
}

int main()
{
    doBirdThings();

    return 0;
}