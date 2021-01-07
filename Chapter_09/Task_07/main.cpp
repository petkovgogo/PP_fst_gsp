#include <iostream>
#include <cstring>

class MyString
{
    static const int BUF_SIZE = 80;
    char m_text[BUF_SIZE];

public:
    MyString(char initValue = ' ') 
    {
        memset(m_text, initValue, BUF_SIZE - 1);
    }

    void print() const
    {
        std::cout << m_text << std::endl;
    }
};

int main()
{
    MyString str('g');

    str.print();

    return 0;
}

