#include <iostream>
#include <vector>

int main()
{
    std::vector<float> v1;
    std::vector<float> v2;

    for (int i = 1; i <= 25; i++)
    {
        v1.push_back(i * 3.14);
        v2.push_back(i * 2.72);
    }

    std::vector<float> v3;

    for (int i = 0; i < v1.size(); i++)
    {
        v3.push_back(v1[i] + v2[i]);
    }

    std::cout << "v1: ";
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << "  ";
    }

    std::cout << "\nv2: ";
    for (int i = 0; i < v2.size(); i++)
    {
        std::cout << v2[i] << "  ";
    }
    
    std::cout << "\nv3: ";
    for (int i = 0; i < v3.size(); i++)
    {
        std::cout << v3[i] << "  ";
    }

    std::cout << std::endl;

    return 0;
}