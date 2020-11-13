#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    int wordCount = 0;
    std::ifstream file("dummy.txt");
    std::string word;
    std::string temp;

    std::cin >> word;

    while (file >> temp)
    {
        if (temp == word)
        {
            wordCount++;
        }
    }
    
    std::cout << wordCount << std::endl;

    return 0;
}