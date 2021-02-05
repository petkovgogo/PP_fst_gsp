#include <iostream>

class Simple
{
public:
    Simple() { std::cout << "Simple::Simple()" << std::endl; }
    ~Simple() { std::cout << "Simple::~Simple()" << std::endl; }

    void *operator new(size_t size)
    {
        std::cout << "Simple::new -> " << size << " bytes" << std::endl;

        return ::new char[size];
    }

    void operator delete(void *simplePtr)
    {
        std::cout << "Widget::delete" << std::endl;

        ::delete[] simplePtr;
    }

    void *operator new[](size_t size)
    {
        std::cout << "Simple::new[] -> " << size << " bytes" << std::endl;

        return ::new char[size];
    }

    void operator delete[](void *simplePtr)
    {
        std::cout << "Widget::delete[]" << std::endl;

        ::delete[] simplePtr;
    }
};

int main()
{
    Simple *simplePtr = new Simple;
    delete simplePtr;
    
    Simple *simpleArr = new Simple[7];
    delete[] simpleArr;

    return 0;
}