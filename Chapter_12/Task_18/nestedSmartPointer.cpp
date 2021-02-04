#include <iostream>
#include <vector>

class Obj
{
private:
    static int i, j;

public:
    void f() { std::cout << i++ << std::endl; }
    void g() { std::cout << j++ << std::endl; }
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

    class SmartPointer;
    friend SmartPointer;
    class SmartPointer
    {
    private:
        ObjContainer &m_container;
        size_t m_index;

    public:
        SmartPointer(ObjContainer &objc) : m_container(objc), m_index(0) {}
        SmartPointer(ObjContainer &objc, size_t index) : m_container(objc), m_index(index) {}

        SmartPointer &operator=(const SmartPointer &origin)
        {
            if (this != &origin)
            {
                m_container = origin.m_container;
                m_index = origin.m_index;
            }

            return *this;
        }

        // Return value indicates end of list:
        bool operator++() // Prefix
        {
            if (m_index >= m_container.m_objStorage.size() ||
                m_container.m_objStorage[++m_index] == 0)
            {
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

    // Function to produce a smart pointer that
    // points to the beginning of the ObjContainer:
    SmartPointer begin()
    {
        return SmartPointer(*this);
    }

    SmartPointer end()
    {
        return SmartPointer(*this, m_objStorage.size() - 1);
    }
};

int main()
{
    const int sz = 10;

    Obj objArr[sz];
    ObjContainer container;

    for (int i = 0; i < sz; i++)
    {
        container.add(&objArr[i]); // Fill it up
    }

    ObjContainer::SmartPointer it = container.begin();

    std::cout << "Using ++" << std::endl;

    do
    {
        it->f(); // Pointer dereference operator call
        it->g();
    } while (++it);

    std::cout << "\nUsing --" << std::endl;

    it = container.end();

    while (--it)
    {
        it->f(); // Pointer dereference operator call
        it->g();
    }

    return 0;
}