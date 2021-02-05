#include <iostream>

class Counted
{
private:
    static int count;
    int m_id;

public:
    Counted() : m_id(count++)
    {
        std::cout << "Counted object #" << m_id << " created." << std::endl;
    }

    ~Counted()
    {
        std::cout << "Counted object #" << m_id << " destroyed." << std::endl;
    }
};

int Counted::count;

int main()
{
    const int COUNT = 7;

    for (int i = 0; i < COUNT; i++)
    {
        Counted();
    }

    return 0;
}