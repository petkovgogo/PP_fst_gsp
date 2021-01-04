#include <string>
#include "../inc/StringStack.h"
#include "../inc/MyString.h"

//! DOES NOT WORK!!!

int main()
{
    const char *iceCream[] = {
        "pralines & cream",
        "fudge ripple",
        "jamocha almond fudge",
        "wild mountain blackberry",
        "raspberry sorbet",
        "lemon swirl",
        "rocky road",
        "deep chocolate fudge"
    };

    const int SIZE = sizeof(iceCream) / sizeof(*iceCream);

    StringStack textStack;

    for (int i = 0; i < SIZE; i++)
    {
        textStack.push(new MyString(iceCream[i]));
    }

    const MyString *pMyString;

    while ((pMyString = textStack.pop()) != 0)
    {
        pMyString->printText();
        delete pMyString;
    }

    return 0;
}