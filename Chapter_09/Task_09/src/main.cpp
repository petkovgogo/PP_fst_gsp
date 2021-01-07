#include <iostream>
#include <string>
#include "../inc/StringStack.h"

std::string iceCream[] = {
    "pralines & cream",
    "fudge ripple",
    "jamocha almond fudge",
    "wild mountain blackberry",
    "raspberry sorbet",
    "lemon swirl",
    "rocky road",
    "deep chocolate fudge"
};

const int iCsz = sizeof(iceCream) / sizeof(*iceCream);

int main()
{
    StringStack ss;

    for (int i = 0; i < iCsz; i++)
    {
        ss.push(&iceCream[i]);
    }

    const std::string *cp;

    while ((cp = ss.pop()) != 0)
    {
        std::cout << *cp << std::endl;
    }

    return 0;
}