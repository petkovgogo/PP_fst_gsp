#include <iostream>
#include <fstream>
#include <string>
#include "OStack.h"

class MyFile : public std::ifstream, public Object
{
private:
    std::string m_fileName;
    bool isNamed;

public:
    MyFile() : isNamed(false) {}
    MyFile(const std::string &fname)
        : std::ifstream(fname.c_str()), m_fileName(fname), isNamed(true) {}

    std::string name() const { return m_fileName; }

    void name(const std::string &newName)
    {
        if (isNamed)
        {
            return; // Don't overwrite
        }

        m_fileName = newName;
        isNamed = true;
    }
};

int main()
{
    Stack fileStack;

    fileStack.push(new MyFile("dummy.txt"));
    fileStack.push(new MyFile("OStack.h"));

    MyFile *mfPtr;
    std::string str;

    while ((mfPtr = (MyFile *)fileStack.pop()) != 0)
    {
        std::cout << "\n" << std::endl;

        while (getline(*mfPtr, str))
        {
            std::cout << str << '\n';
        }
    }

    return 0;
}