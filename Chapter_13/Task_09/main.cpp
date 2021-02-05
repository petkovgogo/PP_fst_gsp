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
    Counted *countedPtr = new Counted;
    void *anonymousPtr = reinterpret_cast<void *>(countedPtr);
    
    countedPtr = 0;

    /**
     * EXPLANATION:
     *  The whole memory is safely released, however the destructor is not called, because
     * the compiler doesn't know what type of object it deletes.
     * 
     * The following warning is displayed:
     * 
     * warning: deleting ‘void*’ is undefined
    **/

    delete anonymousPtr;
    anonymousPtr = 0;

    return 0;
}