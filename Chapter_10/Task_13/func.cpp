#include "Func.h"

#include <iostream>

#ifdef STATIC_FUNC

static void printQuestionAndAnswer()

#else

void printQuestionAndAnswer()

#endif // STATIC_FUNC
{
    std::cout << "- What do you get if you multiply six by nine?" << std::endl;
    std::cout << "- Forty two." << std::endl;
}