#include <iostream>
#include <new> // Size_t definition
#include <vector>

class Widget
{
private:
    enum { sz = 10 };
    int i[sz];

public:
    static std::vector<Widget *> widgetAddresses;

    Widget() { std::cout << "*"; }
    ~Widget() { std::cout << "~"; }

    void *operator new(size_t sz)
    {
        std::cout << "\nWidget::new: " << sz << " bytes" << std::endl;

        void *allocAddress = new char[sz];
        widgetAddresses.push_back((Widget *)allocAddress);

        return allocAddress;
    }

    void operator delete(void *p)
    {
        std::cout << "Widget::delete" << std::endl;
        
        for (size_t i = 0; i < widgetAddresses.size(); i++)
        {
            if ((void *)widgetAddresses[i] == p)
            {
                widgetAddresses.erase(i + widgetAddresses.begin());
                break;
            }
        }

        ::delete[] p;
    }

    void *operator new[](size_t sz)
    {
        std::cout << "\nWidget::new[]: " << sz << " bytes" << std::endl;

        void *allocAddress = new char[sz];
        widgetAddresses.push_back((Widget *)allocAddress);

        return allocAddress;
    }

    void operator delete[](void *p)
    {
        std::cout << "\nWidget::delete[]" << std::endl;

        for (size_t i = 0; i < widgetAddresses.size(); i++)
        {
            if ((void *)widgetAddresses[i] == p)
            {
                widgetAddresses.erase(i + widgetAddresses.begin());
                break;
            }
        }

        ::delete[] p;
    }
};

std::vector<Widget *> Widget::widgetAddresses;

class MemoryChecker
{
private:
    static MemoryChecker checker;
    
    MemoryChecker() {}
    MemoryChecker(MemoryChecker &);

public:
    ~MemoryChecker() 
    {
        std::cout << "\n\n" << Widget::widgetAddresses.size() << " pointer(s) need cleanup" << std::endl;
    }
};

MemoryChecker MemoryChecker::checker;

int main()
{
    std::cout << "new Widget" << std::endl;

    Widget *w = new Widget;

// #define CLEAN

#ifdef CLEAN

    std::cout << "\ndelete Widget" << std::endl;

    delete w;

#endif // CLEAN

    std::cout << "\nnew Widget[25]" << std::endl;

    Widget *wa = new Widget[25];

    std::cout << "\ndelete []Widget" << std::endl;

    delete[] wa;

#ifndef CLEAN

    for (int i = 0; i < 7; i++)
    {
        new Widget; // objects that are created, but not deleted, therefore not removed from the vector
    }

    new Widget[12];

#endif // CLEAN

return 0;
}