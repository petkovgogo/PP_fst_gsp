#include <iostream>
#include <string>

enum Colors 
{
    Green,
    Red,
    Blue,
    Cyan,
    Magenta,
    Yellow,
    Black,
    ELEMENT_COUNT
};

int main()
{
    std::string colorNames[Colors::ELEMENT_COUNT] = {"Green", "Red", "Blue", "Cyan", "Magenta", "Yellow", "Black"};
    Colors colors[Colors::ELEMENT_COUNT] = {Green, Red, Blue, Cyan, Magenta, Yellow, Black};

   for (int i = 0; i < Colors::ELEMENT_COUNT; i++)
   {
       std::cout << colorNames[i] << " -> " << colors[i] << std::endl;
   }
    
    return 0;
}