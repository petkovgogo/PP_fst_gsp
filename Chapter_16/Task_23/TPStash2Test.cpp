#include "TPStash2.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Int
{
private:
    int i;

public:
    Int(int ii = 0) : i(ii)
    {
        std::cout << ">" << i << ' ';
    }

    ~Int() { std::cout << "~" << i << ' '; }

    operator int() const { return i; }

    friend std::ostream &operator<<(std::ostream &os, const Int &x)
    {
        return os << "Int: " << x.i;
    }
    friend std::ostream &operator<<(std::ostream &os, const Int *x)
    {
        return os << "Int: " << x->i;
    }
};

int main()
{
    PStash<Int> ints;

    for (int i = 0; i < 30; i++)
    {
        ints.add(new Int(i));
    }

    std::cout << std::endl;

    PStash<Int>::iterator it = ints.begin();

    it += 25;

    PStash<Int>::iterator it2 = it - 15; // using operator-

    for (; it2 != it; it2++)
    {
        delete it2.remove(); // Default removal
    }

    std::cout << std::endl;

    for (it = ints.begin(); it != ints.end(); it++)
    {
        if (*it) // Remove() causes "holes"
        {
            std::cout << *it << std::endl;
        }
    }

    return 0;
}