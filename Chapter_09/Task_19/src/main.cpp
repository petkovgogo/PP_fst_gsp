#include <iostream>
#include "../inc/StringHolder.h"

int main()
{
    const int HOLDER_ELEMENT_COUNT = 3;

    StringHolder holder;

    std::cout << holder.get_first_string() << std::endl;
    std::cout << holder.get_second_string() << std::endl;
    std::cout << holder.get_third_string() << std::endl;

    return 0;
}