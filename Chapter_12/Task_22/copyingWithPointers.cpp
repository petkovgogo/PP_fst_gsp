#include <iostream>
#include <string>

class Dog
{
private:
    std::string m_name;

public:
    Dog(const std::string &name) : m_name(name)
    {
        std::cout << "Creating Dog: " << *this << std::endl;
    }

    // Synthesized copy-constructor & operator=
    // are correct.
    // Create a Dog from a Dog pointer:
    Dog(const Dog *dp, const std::string &msg) : m_name(dp->m_name + msg)
    {
        std::cout << "Copied dog " << *this << " from "
                  << *dp << std::endl;
    }

    ~Dog()
    {
        std::cout << "Deleting Dog: " << *this << std::endl;
    }

    void rename(const std::string &newName)
    {
        m_name = newName;
        std::cout << "Dog renamed to: " << *this << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Dog &d)
    {
        return os << "[" << d.m_name << "]";
    }
};

class DogHouse
{
private:
    Dog *m_dogPtr;
    std::string m_houseName;

public:
    DogHouse(Dog *dog, const std::string &house)
        : m_dogPtr(dog), m_houseName(house) {}

    DogHouse(const DogHouse &dh)
        : m_dogPtr(new Dog(dh.m_dogPtr, " copy-constructed")),
          m_houseName(dh.m_houseName + " copy-constructed") {}

    ~DogHouse() { delete m_dogPtr; }

    // DogHouse &operator=(const DogHouse &dh)
    // {
    //     // Check for self-assignment:
    //     if (&dh != this)
    //     {
    //         m_dogPtr = new Dog(dh.m_dogPtr, " assigned");
    //         m_houseName = dh.m_houseName + " assigned";
    //     }

    //     return *this;
    // }

    void renameHouse(const std::string &newName)
    {
        m_houseName = newName;
    }

    Dog *getDog() const { return m_dogPtr; }

    friend std::ostream &operator<<(std::ostream &os, const DogHouse &dh)
    {
        os << "[" << dh.m_houseName << "] contains " << *dh.m_dogPtr;

        return os << "\nThe address of the dog pointer is " << (long)dh.m_dogPtr;
    }
};

int main()
{
    DogHouse fidos(new Dog("Fido"), "FidoHouse");

    std::cout << fidos << std::endl;

    DogHouse fidos2 = fidos; // Copy construction - creates new Dog

    std::cout << fidos2 << std::endl;

    fidos2.getDog()->rename("Spot");
    fidos2.renameHouse("SpotHouse");

    std::cout << fidos2 << std::endl;

    fidos = fidos2; // Assignment

    // The string is copied, but the address of the dog is the same as the one created in the copy-construction,
    // meaning  it was only aliased
    std::cout << fidos << std::endl;

    fidos.getDog()->rename("Max");
    fidos2.renameHouse("MaxHouse");

    // Upon deleting the Dog there is an error:
    // free(): double free detected in tcache 2
    // Aborted (core dumped)

    return 0;
}