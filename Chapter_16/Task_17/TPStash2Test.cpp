#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "TPStash2.h"

template <class T>
class Data
{
private:
    T m_data;

public:
    Data(T data = 0) : m_data(data) {}

    ~Data() {}

    operator int() const { return m_data; }

    friend std::ostream &operator<<(std::ostream &os, const Data &x)
    {
        return os << "Data: " << x.m_data;
    }

    friend std::ostream &operator<<(std::ostream &os, const Data *x)
    {
        return os << "Data: " << x->m_data;
    }
};
int main()
{
    { // To force destructor call
        PStash<Data<int>> ints;

        for (int i = 0; i < 30; i++)
        {
            ints.add(new Data<int>(i));
        }

        PStash<Data<int>>::iterator it = ints.begin();

        it += 5;

        PStash<Data<int>>::iterator it2 = it + 10;

        for (; it != it2; it++)
        {
            delete it.remove(); // Default removal
        }

        for (it = ints.begin(); it != ints.end(); it++)
        {
            if (*it) // Remove() causes "holes"
            {
                std::cout << *it << std::endl;
            }
        }
    } // "ints" destructor called here

    std::cout << "\n-------------------\n\n";

    std::ifstream in("TPStash2Test.cpp");

    // Instantiate for String:
    PStash<Data<std::string>> strings;
    std::string line;

    while (getline(in, line))
    {
        strings.add(new Data<std::string>(line));
    }

    PStash<Data<std::string>>::iterator sit = strings.begin();

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

    std::cout << "\n-------------------\n\n";

    PStash<Data<double>> doubles;

    const double PI = 3.14159;

    for (int i = 0; i < 30; i++)
    {
        doubles.add(new Data<double>(i * PI));
    }

    PStash<Data<double>>::iterator it = doubles.begin();

    it += 5;

    for (it = doubles.begin(); it != doubles.end(); it++)
    {
        if (*it)
        {
            std::cout << *it << std::endl;
        }
    }

    return 0;
}