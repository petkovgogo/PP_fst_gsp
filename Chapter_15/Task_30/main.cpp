#include <iostream>

class Fruit
{
public:
    virtual void identify() const { std::cout << "This is a fruit." << std::endl; };
};

class Mango : public Fruit
{
private:
    bool m_isRipe;

public:
    Mango(bool isRipe = false) : m_isRipe(isRipe) {}

    bool isRipe() const { return m_isRipe; }
    void identify() const
    {
        std::cout << "This is a mango. It "
                  << (m_isRipe ? "is" : "is not")
                  << " ripe."
                  << std::endl;
    };
};

void forceVCall(Fruit fruit)
{
    Mango *mangoPtr = reinterpret_cast<Mango *>(&fruit);

    // Even though the fruit is casted to a mango, the base identify() is called.
    // This happens, because even when the object is sliced (it is passed by value),
    // the function remains on the same position in the vptr, so a virtual call is performed and the program doesn't crash
    mangoPtr->identify();

    // This function is a different story. It can be used but the result is not correct because this object has
    // not been initialised as a Mango, so the m_isRipe is not set to false. Because this function is not virtual, there is no base
    // version of it in the vptr and it can't be used safely
    std::cout << (mangoPtr->isRipe() ? "Ripe" : "Not ripe") << std::endl;
}

int main()
{
    forceVCall(Mango());

    return 0;
}