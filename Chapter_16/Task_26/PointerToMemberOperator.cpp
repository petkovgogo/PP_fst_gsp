#include <iostream>

class Dog
{
public:
    int run() const
    {
        std::cout << "run (void)\n";
        return -1;
    }

    int eat(int i) const
    {
        std::cout << "eat (int)\n";
        return i;
    }

    int sleep(int i, int j) const
    {
        std::cout << "ZZZ (int, int)\n";
        return i + j;
    }

    typedef int (Dog::*PMFV)() const;
    typedef int (Dog::*PMFI)(int) const;
    typedef int (Dog::*PMFII)(int, int) const;

    // operator->* must return an object
    // that has an operator():
    template <class T, typename func_type>
    class FunctionObject
    {
    private:
        T *ptr;
        func_type pmem;

    public:
        // Save the object pointer and member pointer
        FunctionObject(T *wp, func_type pmf)
            : ptr(wp), pmem(pmf)
        {
            std::cout << "FunctionObject constructor\n";
        }

        // Make the call using the object pointer
        // and member pointer
        int operator()() const
        {
            std::cout << "FunctionObject::operator()\n";
            return (ptr->*pmem)(); // Make the call
        }

        int operator()(int i) const
        {
            std::cout << "FunctionObject::operator(int)\n";
            return (ptr->*pmem)(i); // Make the call
        }

        int operator()(int i, int j) const
        {
            std::cout << "FunctionObject::operator(int, int)\n";
            return (ptr->*pmem)(i, j); // Make the call
        }
    };

    template <typename func_type>
    FunctionObject<Dog, func_type> operator->*(func_type pmf)
    {
        std::cout << "operator->*" << std::endl;
        return FunctionObject<Dog, func_type>(this, pmf);
    }
};

int main()
{
    Dog w;
    Dog::PMFV pmfv = &Dog::run;

    std::cout << (w->*pmfv)() << std::endl;

    Dog::PMFII pmfii = &Dog::sleep;

    std::cout << (w->*pmfii)(2, 6) << std::endl;

    Dog::PMFI pmfi = &Dog::eat;

    std::cout << (w->*pmfi)(3) << std::endl;

    return 0;
}