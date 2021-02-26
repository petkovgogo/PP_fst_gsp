#include <iostream>

class Dog
{
public:
    virtual int run(int i) const
    {
        std::cout << "run\n";
        return i;
    }

    virtual int eat(int i) const
    {
        std::cout << "eat\n";
        return i;
    }

    virtual int sleep(int i) const
    {
        std::cout << "ZZZ\n";
        return i;
    }

    typedef int (Dog::*PMF)(int) const;

    // operator->* must return an object
    // that has an operator():
    class FunctionObject
    {
        Dog *ptr;
        PMF pmem;

    public:
        // Save the object pointer and member pointer
        FunctionObject(Dog *wp, PMF pmf) : ptr(wp), pmem(pmf)
        {
            // std::cout << "FunctionObject constructor\n";
        }

        // Make the call using the object pointer
        // and member pointer
        int operator()(int i) const
        {
            // std::cout << "FunctionObject::operator()\n";
            return (ptr->*pmem)(i); // Make the call
        }
    };

    FunctionObject operator->*(PMF pmf)
    {
        // std::cout << "operator->*" << std::endl;
        return FunctionObject(this, pmf);
    }
};

class Boxer : public Dog
{
public:
    virtual int run(int i) const
    {
        std::cout << "Boxer runs\n";
        return i;
    }

    virtual int eat(int i) const
    {
        std::cout << "Boxer eats\n";
        return i;
    }

    virtual int sleep(int i) const
    {
        std::cout << "Boxer says *ZZZ*\n";
        return i;
    }
};

int main()
{
    Boxer bDog;    // Boxer inherits operator->*
    Dog &w = bDog; // Upcasting to dog
    Dog::PMF pmf = &Dog::run;

    std::cout << (w->*pmf)(1) << std::endl;

    pmf = &Dog::sleep;

    std::cout << (w->*pmf)(2) << std::endl;

    pmf = &Dog::eat;

    std::cout << (w->*pmf)(3) << std::endl;

    return 0;
}