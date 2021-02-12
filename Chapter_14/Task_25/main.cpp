#include <iostream>
#include <vector>
#include <fstream>

class StringStack
{
private:
    std::vector<const char *> m_stack; // Embed instead of inherit

public:
    void push(const char *str)
    {
        m_stack.push_back(str);
    }

    const char *peek() const
    {
        return m_stack[size() - 1];
    }

    const char *pop()
    {
        if (size() == 0)
        {
            return 0;
        }

        const char *result = m_stack[size() - 1];
        m_stack.erase(m_stack.begin() + size() - 1);

        return result;
    }

    size_t size() const
    {
        return m_stack.size();
    }
};

int main()
{
    std::ifstream in("main.cpp");

    const int BUF_SIZE = 80;

    StringStack textlines;
    char *line = new char[BUF_SIZE];

    while (in.getline(line, BUF_SIZE))
    {
        textlines.push(line);
        line = new char[BUF_SIZE];
    }

    const char *str;
    while ((str = textlines.pop()) != 0) // No cast!
    {
        std::cout << str << std::endl;
        delete[] str;
    }

    return 0;
}