#include <iostream>

class PetFood
{
public:
    virtual const char *foodType() const = 0;
};

class Pet
{
public:
    virtual const char *type() const = 0;
    virtual PetFood *eatsPtr() = 0;
    virtual PetFood &eatsRef() = 0;
};

class Bird : public Pet
{
public:
    const char *type() const { return "Bird"; }

    class BirdFood : public PetFood
    {
    public:
        const char *foodType() const
        {
            return "Bird food";
        }
    };

    // Upcast to base type:
    PetFood *eatsPtr() { return &bf; }
    PetFood &eatsRef() { return bf; }

private:
    BirdFood bf;
};

class Cat : public Pet
{
public:
    const char *type() const { return "Cat"; }
    class CatFood : public PetFood
    {
    public:
        const char *foodType() const { return "Birds"; }
    };

    // Return exact type instead:
    CatFood *eatsPtr() { return &cf; }
    CatFood &eatsRef() { return cf; }

private:
    CatFood cf;
};

#define PRINT(EXP) \
    std::cout << #EXP " -> " << EXP << std::endl;

int main()
{
    Bird b;
    Cat c;

    Pet *p[] =
    {
        &b,
        &c,
    };

    std::cout << "<----Pointers---->" << std::endl;

    for (size_t i = 0; i < sizeof(p) / sizeof(*p); i++)
    {
        std::cout << p[i]->type() << " eats "
                  << p[i]->eatsPtr()->foodType() << std::endl;
    }

    // Can return the exact type:
    Cat::CatFood *cf1 = c.eatsPtr();
    Bird::BirdFood *bf1;

    // Cannot return the exact type:
    //! bf = b.eats();
    // Must downcast:
    bf1 = dynamic_cast<Bird::BirdFood *>(b.eatsPtr());

    PRINT(cf1->foodType())
    PRINT(bf1->foodType())

    std::cout << "\n<---References--->" << std::endl;

    for (size_t i = 0; i < sizeof(p) / sizeof(*p); i++)
    {
        std::cout << p[i]->type() << " eats "
                  << p[i]->eatsRef().foodType() << std::endl;
    }

    // Can return the exact type:
    Cat::CatFood &cf2 = c.eatsRef();
    Bird::BirdFood &bf2 = dynamic_cast<Bird::BirdFood &>(b.eatsRef());

    PRINT(cf2.foodType())
    PRINT(bf2.foodType())

    return 0;
}