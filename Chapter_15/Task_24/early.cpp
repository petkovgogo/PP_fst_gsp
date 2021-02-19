#include <iostream>

class Pet
{
public:
    virtual const char *speak() const { return ""; }
};

class Dog : public Pet
{
public:
    const char *speak() const { return "Bark!"; }
};

int main()
{
    Dog ralph;
    Pet *p1 = &ralph;
    Pet &p2 = ralph;
    Pet p3;

    // Late binding for both:
    std::cout << "p1->speak() = " << p1->speak() << std::endl;
    std::cout << "p2.speak() = " << p2.speak() << std::endl;

    // Early binding (probably):
    std::cout << "p3.speak() = " << p3.speak() << std::endl;

    return 0;
}