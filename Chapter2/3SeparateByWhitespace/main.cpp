#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    int wordCount = 0;
    std::ifstream file("dummy.txt");
    std::string word;

    while (file >> word)
    {
        wordCount++;
    }
    
    std::cout << wordCount << std::endl;

    return 0;
}