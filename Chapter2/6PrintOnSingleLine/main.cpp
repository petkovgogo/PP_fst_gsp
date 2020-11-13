#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::vector<std::string> v;
    std::ifstream in("dummy.txt");
    std::string line;

    while (getline(in, line))
    {
        v.push_back(line);
    }

    line = std::string(v.begin(), v.end());

    std::cout << line << std::endl;
}