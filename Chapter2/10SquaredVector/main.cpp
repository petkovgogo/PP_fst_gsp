#include <iostream>
#include <vector>

int main()
{
    std::vector<float> v;

    for (int i = 1; i <= 25; i++)
    {
        v.push_back(i * 3.14);
    }

    std::cout << "Before: ";

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "  ";
    }

    for (int i = 0; i < v.size(); i++)
    {
        v[i] *= v[i];
    }
    
    std::cout << "\nAfter: ";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "  ";
    }

    std::cout << std::endl;

    return 0;
}