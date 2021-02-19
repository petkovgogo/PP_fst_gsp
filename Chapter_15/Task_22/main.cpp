#include <iostream>

class Base
{
public:
    virtual void func() const { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    virtual void func(int) const { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    virtual void func(char) const { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

#define OVERRIDE_FUNC

class Derived : public Base
{
public:
#ifdef OVERRIDE_FUNC

    void func() const { std::cout << __PRETTY_FUNCTION__ << std::endl; }

#endif // OVERRIDE
};

int main()
{
    Derived dObj;

#ifdef OVERRIDE_FUNC

    dObj.func();

#else

    dObj.func();
    dObj.func(42);
    dObj.func('*');

#endif // OVERRIDE

    Base *basePtr = &dObj;

    basePtr->func();
    basePtr->func(42);  // calls Base::func(int), even though it is an upcasted Derived object
    basePtr->func('*'); // calls Base::func(char), even though it is an upcasted Derived object

    return 0;
}
