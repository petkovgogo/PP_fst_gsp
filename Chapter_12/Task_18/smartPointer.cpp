#include <iostream>
#include <vector>
#include <limits>

class Obj
{
private:
    static int i, j;

public:
    void f() const { std::cout << i++ << std::endl; }
    void g() const { std::cout << j++ << std::endl; }
};

// Static member definitions:
int Obj::i = 47;
int Obj::j = 11;

// Container:
class ObjContainer
{
private:
    std::vector<Obj *> m_objStorage;

public:
    void add(Obj *obj) { m_objStorage.push_back(obj); }
    friend class SmartPointer;
};

class SmartPointer
{
private:
    ObjContainer &m_container;
    size_t m_index;

public:
    SmartPointer(ObjContainer &objc) : m_container(objc), m_index(0) {}

    // Return value indicates end of list:
    bool operator++() // Prefix
    {
        if (m_index >= m_container.m_objStorage.size() ||
            m_container.m_objStorage[++m_index] == 0)
        {
            m_index = m_container.m_objStorage.size() - 1; // returning the index inside the storage if it went over the value of size()

            return false;
        }

        return true;
    }

    bool operator++(int) // Postfix
    {
        return operator++(); // Use prefix version
    }

    bool operator--() // Prefix
    {
        // m_index is a size_t variable, which means it is unsigned, therefore it cannot be
        // below zero. So if the index goes below zero, m_index will change its value to the max
        // value of unsigned long. That is why instead of checking for m_index < 0, I am checking
        // for tha value being larger than the size of the vector
        if (m_index >= m_container.m_objStorage.size() ||
            m_container.m_objStorage[m_index--] == 0)
        {
            m_index = std::numeric_limits<unsigned long>::max(); // returning the index inside the storage if it went over the value of size()

            return false;
        }

        return true;
    }

    bool operator--(int) // Postfix
    {
        return operator--(); // Use prefix version
    }

    Obj *operator->() const
    {
        return m_container.m_objStorage[m_index];
    }
};

int main()
{
    const int SIZE = 10;

    Obj objArr[SIZE];
    ObjContainer objContainer;

    for (int i = 0; i < SIZE; i++)
    {
        objContainer.add(&objArr[i]); // Fill it up
    }

    SmartPointer it(objContainer); // Create an iterator

    std::cout << "Using ++" << std::endl;

    do
    {
        it->f(); // Pointer dereference operator call
        it->g();
    } while (it++);

    std::cout << "\nUsing --" << std::endl;

    while (it--)
    {
        it->f(); // Pointer dereference operator call
        it->g();
    }

    return 0;
}