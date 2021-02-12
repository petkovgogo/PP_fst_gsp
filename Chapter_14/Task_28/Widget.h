#ifndef WIDGET_H
#define WIDGET_H

#include <fstream>

std::ofstream trace("ArrayOperatorNew.out.txt");

class Widget
{
private:
    static const int sz = 10;
    int i[sz];

public:
    Widget() { trace << "*"; }
    ~Widget() { trace << "~"; }

    void *operator new(size_t sz)
    {
        trace << "Widget::new: "
              << sz << " bytes" << std::endl;
        
        return ::new char[sz];
    }

    void operator delete(void *p)
    {
        trace << "Widget::delete" << std::endl;
        ::delete[] p;
    }

    void *operator new[](size_t sz)
    {
        trace << "Widget::new[]: "
              << sz << " bytes" << std::endl;
      
        return ::new char[sz];
    }

    void operator delete[](void *p)
    {
        trace << "Widget::delete[]" << std::endl;
        ::delete[] p;
    }
};

#endif // WIDGET_H