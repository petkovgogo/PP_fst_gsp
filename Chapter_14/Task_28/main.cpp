#include <iostream>
#include "Widget.h"
#include "Framis.h"

class WidgetHeir : public Widget {};
class FramisHeir : public Framis {};

int main()
{
    const int SIZE = 12;

    /**
     * WIDGET:
     *  In the output file we can see that Widget's operators are called for a WidgetHeir object
     * (meaning they can be inherited), so the allocation works correctly
     * 
     * FRAMIS:
     *  Allocation after inheriting from Framis works correctly as shown in the output file.
    **/

    trace << "new WidgetHeir" << std::endl;
    WidgetHeir *heir = new WidgetHeir;

    trace << "\ndelete WidgetHeir" << std::endl;
    delete heir;

    trace << "\nnew WidgetHeir[" << SIZE << "]" << std::endl;
    WidgetHeir *heirArr = new WidgetHeir[SIZE];

    trace << "\ndelete []WidgetHeir" << std::endl;
    delete[] heirArr;

    FramisHeir *f[FramisHeir::psize];

    try
    {
        for (int i = 0; i < FramisHeir::psize; i++)
        {
            f[i] = new FramisHeir;
        }

        new FramisHeir; // Out of memory
    }
    catch (std::bad_alloc &)
    {
        std::cerr << "Out of memory!" << std::endl;
    }

    delete f[10];
    f[10] = 0;

    // Use released memory:
    FramisHeir *x = new FramisHeir;
    delete x;

    for (int j = 0; j < FramisHeir::psize; j++)
    {
        delete f[j]; // Delete f[10] OK
    }

    return 0;
}