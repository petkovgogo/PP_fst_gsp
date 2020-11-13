#include <iostream>
#include <vector>

int main()
{
    std::vector<float> v;

    for (int i = 1; i <= 25; i++)
    {
        v.push_back(i * 3.14);
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
}