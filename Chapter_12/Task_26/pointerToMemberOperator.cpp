#include <iostream>

class Dog
{
public:
    int run(int i) const
    {
        std::cout << "run\n";

        return i;
    }

    int eat(int i) const
    {
        std::cout << "eat\n";

        return i;
    }

    int sleep(int i) const
    {
        std::cout << "ZZZ\n";

        return i;
    }

    void sit() const
    {
        std::cout << "sit\n";
    }

    void bark() const
    {
        std::cout << "BARK BARK\n";
    }

    typedef int (Dog::*PMF)(int) const;
    typedef void (Dog::*PVMF)() const; // PVMF stands for pointer to void member function

    // operator->* must return an object
    // that has an operator():

    class FunctionObject
    {
        Dog *ptr;
        PMF m_pmf;
        PVMF m_pvmf;

    public:
        // Save the object pointer and member pointer
        FunctionObject(Dog *wp, PMF pmf) : ptr(wp), m_pmf(pmf), m_pvmf(0)
        {
            std::cout << "FunctionObject PMF constructor\n";
        }

        FunctionObject(Dog *wp, PVMF pvmf) : ptr(wp), m_pmf(0), m_pvmf(pvmf)
        {
            std::cout << "FunctionObject PVMF constructor\n";
        }

        // Make the call using the object pointer
        // and member pointer
        int operator()(int i) const
        {
            std::cout << "FunctionObject::operator(int)\n";

            return (ptr->*m_pmf)(i); // Make the call
        }

        void operator()() const
        {
            std::cout << "FunctionObject::operator(void)\n";

            return (ptr->*m_pvmf)(); // Make the call
        }
    };

    FunctionObject operator->*(PMF pmf)
    {
        std::cout << "operator->*PMF" << std::endl;

        return FunctionObject(this, pmf);
    }

    FunctionObject operator->*(PVMF pvmf)
    {
        std::cout << "operator->*PVMF" << std::endl;

        return FunctionObject(this, pvmf);
    }
};

int main()
{
    Dog dog;
    
    Dog::PMF pmf = &Dog::run;
    std::cout << (dog->*pmf)(1) << std::endl;

    pmf = &Dog::sleep;
    std::cout << (dog->*pmf)(2) << std::endl;

    pmf = &Dog::eat;
    std::cout << (dog->*pmf)(3) << std::endl;

    Dog::PVMF pvmf = &Dog::sit;
    (dog->*pvmf)();

    pvmf = &Dog::bark;
    (dog->*pvmf)();

    return 0;
}