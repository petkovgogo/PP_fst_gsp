#include <iostream>

#define PRINT_TRIGRAPH(EXP) std::cout << EXP << std::endl;

int main()
{
    // Only works if compiled with -trigraphs flag
    PRINT_TRIGRAPH("??=");
    PRINT_TRIGRAPH("\??/");
    PRINT_TRIGRAPH("??'");
    PRINT_TRIGRAPH("??(");
    PRINT_TRIGRAPH("??)");
    PRINT_TRIGRAPH("??!");
    PRINT_TRIGRAPH("??<");
    PRINT_TRIGRAPH("??>");
    PRINT_TRIGRAPH("??-");

    return 0;
}
