#include <iostream>
#include <sstream> // "String streams"
#include <cstring>

template <class T, size_t sz = 5>
class Array
{
private:
    T m_arr[sz];

public:
    Array() { memset(m_arr, 0, sz * sizeof(*m_arr)); }

    const T &operator[](int x) const { return m_arr[x]; }
    T &operator[](int x) { return m_arr[x]; }

    friend std::ostream &operator<<(std::ostream &os, const Array &ia)
    {
        for (size_t j = 0; j < sz; j++)
        {
            os << ia[j];

            if (j != sz - 1)
            {
                os << ", ";
            }
        }

        return os << std::endl;
    }

    friend std::istream &operator>>(std::istream &is, Array &ia)
    {
        for (size_t j = 0; j < sz; j++)
        {
            is >> ia[j];
        }

        return is;
    }
};

int main()
{
    std::stringstream ints("47 34 56 92 103");
    Array<int> intArr;

    ints >> intArr;
    intArr[4] = -1; // Use overloaded operator[]

    std::cout << intArr;

    std::stringstream doubles("6.63 3.14 42.7 2.72 1.6");
    Array<double> doubleArr;

    doubles >> doubleArr;
    doubleArr[4] = -1; // Use overloaded operator[]

    std::cout << doubleArr;
}