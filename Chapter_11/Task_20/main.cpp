#include <iostream>

class Dog
{
private:
    const char *m_name;

public:
    Dog(const char *name) : m_name(name) {}

    void printName() const
    {
        std::cout << m_name;
    }
};

Dog tempDogInstance()
{
    Dog dog("Rio");

    return dog;
}

#ifdef NON_CONST

void callDog(Dog &dog)

#else

void callDog(const Dog &dog)

#endif // NON_CONST
{
    std::cout << "Hey ";
    dog.printName();
    std::cout << ", come here!" << std::endl;
}

int main()
{
    // tempDogInstance() returns a temporary object which is a const object, hence the error
    callDog(tempDogInstance());

    return 0;
}