#include <iostream>

int dog, cat, bird, fish;
void f(int pet)
{
    std::cout << "pet id number: " << pet << std::endl;
}

int main()
{
    int i, j, k;
    std::cout << "f(): " << (long)&f << std::endl;
    std::cout << "dog: " << (long)&dog << std::endl;
    std::cout << "cat: " << (long)&cat << std::endl;
    std::cout << "bird: " << (long)&bird << std::endl;
    std::cout << "fish: " << (long)&fish << std::endl;
    std::cout << "i: " << (long)&i << std::endl;
    std::cout << "j: " << (long)&j << std::endl;
    std::cout << "k: " << (long)&k << std::endl;

    return 0;
}