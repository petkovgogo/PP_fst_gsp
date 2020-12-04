#include <iostream>
#include <cassert>

int main()
{
    assert(2 + 2 == 5);
    std::cout << "Execution went past assert" << std::endl;
    
    return 0;
}
