#include "OStack.h"
#include <fstream>
#include <iostream>
#include <string>

// Use multiple inheritance. We want
// both a string and an Object:
class MyString : public std::string, public Object
{
public:
    ~MyString()
    {
        std::cout << "deleting string: " << *this << std::endl;
    }

    MyString(std::string s) : std::string(s) {}
};

int main()
{
    std::ifstream in("OStackTest.cpp");
    Stack<MyString> textlines;
    std::string line;

    // Read file and store lines in the stack:
    while (getline(in, line))
    {
        textlines.push(new MyString(line));
    }

    // Pop some lines from the stack:
    MyString *s;
    for (int i = 0; i < 10; i++)
    {
        if ((s = textlines.pop()) == 0)
        {
            break;
        }

        // std::cout << *s << std::endl;
        delete s;
    }

    std::cout << "\nLetting the destructor do the rest:"
              << std::endl;

    return 0;
}