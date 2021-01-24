#include <iostream>

struct MyString
{
    const char *m_str;

    MyString(const char *str) : m_str(str) {}
    MyString(MyString &str)
    {
        std::cout << "\nUsing MyString's copy-constructor..." << std::endl;
        m_str = str.m_str;
    }
};

class StringHolder
{
private:
    MyString m_string;
    int m_timesUsed;

public:
    StringHolder(MyString &str) : m_string(str), m_timesUsed(0) {}
    MyString useString()
    {
        std::cout << "You used this string " << ++m_timesUsed << " times up to now" << std::endl;
        return m_string;
    }
};

int main()
{
    MyString myString("What do you get if you multiply six by nine?");
    StringHolder holder(myString);

    std::cout << holder.useString().m_str << std::endl; // using the function one time

    StringHolder holderCopy(holder);

    std::cout << holder.useString().m_str << std::endl; // getting the expected result for a second call, proving the synthesized copy-constructor
                                                        // performs a bitcopy of primitive types

    return 0;
}
