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

    Counted *countedArr = new Counted[SIZE];

    /**
     * OBSERVATION:
     *  Only the fisrt object's destructor is called, but the whole memory is released.
     * The compiler knows countedArr is an array, so when the pointer is passed to free(),
     * the memory is not released correctly, resulting in the following error:
     * 
     *  munmap_chunk(): invalid pointer
     *  Aborted (core dumped)
    **/

    delete countedArr;

    return 0;
}