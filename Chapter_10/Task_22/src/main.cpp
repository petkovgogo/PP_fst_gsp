#include <iostream>
#include "../inc/Bird1.h"
#include "../inc/Bird2.h"

// Remove this #define to see errors from local using directives
// Change this #define to GLOBAL_DIRECTIVES to see errors from global using directives
#define FIXED

#ifdef GLOBAL_DIRECTIVES

using namespace bird1;
using namespace bird2;

#endif // GLOBAL_DIRECTIVES

void doBirdThings()
{
#ifndef GLOBAL_DIRECTIVES
#ifndef FIXED

    using namespace bird1;
    using namespace bird2;

#endif // FIXED
#endif // GLOBAL_DIRECTIVES

#ifdef FIXED

    bird1::Bird parrot("Parrot");
    bird2::Bird sparrow("Sparrow");

#else

    Bird parrot("Parrot");
    Bird sparrow("Sparrow");

#endif // FIXED

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