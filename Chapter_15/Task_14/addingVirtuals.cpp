#include <iostream>
#include <string>

class Pet
{
private:
    std::string pname;

public:
    Pet(std::string petName) : pname(petName) {}

    virtual std::string name() const = 0;
    virtual std::string speak() const = 0;
};

std::string Pet::name() const { return pname; }

class Dog : public Pet
{
public:
    Dog(const std::string petName) : Pet(petName) {}
    // New virtual function in the Dog class:
    virtual std::string sit() const
    {
        return name() + " sits";
    }

    std::string name() const { return Pet::name(); }

    std::string speak() const
    { // Override
        return name() + " says 'Bark!'";
    }
};

int main()
{
    Pet *p[] = {/* new Pet("generic"), */ new Dog("bob")};

    std::cout << "p[0]->speak() = "
              << p[0]->speak() << std::endl;

    //! cout << "p[1]->sit() = "
    //! << p[1]->sit() << endl; // Illegal

    return 0;
}