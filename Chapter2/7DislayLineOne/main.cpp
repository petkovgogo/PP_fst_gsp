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

    for (int i = 0; i < v.size(); i++)
    {
        std::cin.get();
        std::cout << i << ": " << v[i] << std::endl;
    }

    return 0;
}