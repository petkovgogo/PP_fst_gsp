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
    const int SIZE = 7;

    Counted *countedPtr = new Counted;

    delete countedPtr;
    countedPtr = 0;

    Counted *const countedArr = new Counted[SIZE];

    delete[] countedArr;

    return 0;
}