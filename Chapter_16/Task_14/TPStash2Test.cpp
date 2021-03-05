#include "TPStash2.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Int
{
private:
    int m_num;

public:
    Int(int num = 0) : m_num(num)
    {
        std::cout << ">" << m_num << ' ';
    }

    ~Int() { std::cout << "~" << m_num << ' '; }

    operator int() const { return m_num; }

    friend std::ostream &operator<<(std::ostream &os, const Int &x)
    {
        return os << "Int: " << x.m_num;
    }

    friend std::ostream &operator<<(std::ostream &os, const Int *x)
    {
        return os << "Int: " << x->m_num;
    }
};

int main()
{
    { // To force destructor call
        PStash<Int> ints;

        for (int i = 0; i < 30; i++)
        {
            ints.add(new Int(i));
        }

        std::cout << std::endl;

        PStash<Int>::iterator it = ints.begin();

        it += 5;

        PStash<Int>::iterator it2 = it + 10;

        for (; it != it2; it++)
        {
            delete it.remove(); // Default removal
        }

        std::cout << std::endl;

        for (it = ints.begin(); it != ints.end(); it++)
        {
            if (*it) // Remove() causes "holes"
            {
                std::cout << *it << std::endl;
            }
        }
    } // "ints" destructor called here

    std::cout << "\n-------------------\n";

    std::ifstream in("TPStash2Test.cpp");

    // Instantiate for std::string:
    PStash<std::string> strings;
    std::string line;

    while (getline(in, line))
    {
        strings.add(new std::string(line));
    }

    PStash<std::string>::iterator sit = strings.begin();

    for (; sit != strings.end(); sit++)
    {
        std::cout << **sit << std::endl;
    }

    int n = 26;

    sit = strings.begin();
    sit += n;

    for (; sit != strings.end(); sit++)
    {
        std::cout << n++ << ": " << **sit << std::endl;
    }

    return 0;
}