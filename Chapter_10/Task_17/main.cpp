#include <iostream>
#include "Func.h"

namespace
{
    void printQuestionAndAnswer()
    {
        std::cout << "- What do you get if you multiply six by nine?" << std::endl;
        std::cout << "- Forty two." << std::endl;
    }
} // namespace

// executes without linker errors, which means
// the unnamed namespace is unique to each translation unit
int main()
{
    printQuestionAndAnswer();

    return 0;
}