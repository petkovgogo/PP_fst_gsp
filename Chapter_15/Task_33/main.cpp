#include <iostream>
#include <typeinfo>

class Animal
{
private:
    int m_legs;
    bool m_hasTail;

public:
    Animal(int legs, bool hasTail) : m_legs(legs), m_hasTail(hasTail) {}

    virtual void move() { std::cout << "Moving..." << std::endl; }
    virtual void makeSound() { std::cout << "Making a sound..." << std::endl; }
};

typedef unsigned char byte;

void printPartsOfObj(Animal *animal)
{
    byte *animalObj = reinterpret_cast<byte *>(animal);

    void *vptr = reinterpret_cast<void *>(animal);
    int *legs = reinterpret_cast<int *>(animalObj + sizeof(void *));
    bool *hasTail = reinterpret_cast<bool *>(animalObj + sizeof(void *) + sizeof(int));

    std::cout << "VPTR address: " << vptr << std::endl;
    std::cout << "Leg count: " << *legs << std::endl;
    std::cout << "Has tail: " << (*hasTail ? "yes" : "no") << std::endl;
}

int main()
{
    Animal animal(2, false);

    printPartsOfObj(&animal);

    return 0;
}