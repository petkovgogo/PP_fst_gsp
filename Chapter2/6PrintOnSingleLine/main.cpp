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

    std::string output;

    for (int i = 0; i < v.size(); i++)
    {
        output += v[i];
    }

    std::cout << output << std::endl;
}