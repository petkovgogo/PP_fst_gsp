#include <iostream>
#include <string>

enum Colors 
{
    GREEN,
    RED,
    BLUE,
    CYAN,
    MAGENTA,
    YELLOW,
    BLACK,
    ELEMENT_COUNT
};

int main()
{
    std::string colorNames[Colors::ELEMENT_COUNT] = {"Green", "Red", "Blue", "Cyan", "Magenta", "Yellow", "Black"};
    Colors colors[Colors::ELEMENT_COUNT] = {GREEN, RED, BLUE, CYAN, MAGENTA, YELLOW, BLACK};

   for (int i = 0; i < Colors::ELEMENT_COUNT; i++)
   {
       std::cout << colorNames[i] << " -> " << colors[i] << std::endl;
   }
    
    return 0;
}