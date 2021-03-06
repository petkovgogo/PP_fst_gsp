#include <iostream>
#include <vector>

class Obj;
typedef void (Obj::*PMF)();

class Obj
{
private:
    static int i, j;
    PMF m_pmf;

public:
    void f() { std::cout << i++ << std::endl; }
    void g() { std::cout << j++ << std::endl; }

    void setPMF(PMF pmf) { m_pmf = pmf; }
    void operator()() { return (this->*m_pmf)(); }
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
        SmartPointer(ObjContainer &objc, size_t index = 0) : m_container(objc), m_index(index) {}

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

        // Postfix
        bool operator++(int) { return operator++(); }

        bool operator--() // Prefix
        {
            // m_index is a size_t variable, which means it is unsigned, therefore it cannot be
            // below zero. So if the index goes below zero, m_index will change its value to the max
            // value of unsigned long. That is why instead of checking for m_index < 0, I am checking
            // for tha value being larger than the size of the vector
            if (--m_index >= m_container.m_objStorage.size() ||
                m_container.m_objStorage[m_index] == 0)
            {
                return false;
            }

            return true;
        }

        // Postfix
        bool operator--(int) { return operator--(); }
        Obj *operator->() const { return m_container.m_objStorage[m_index]; }

        Obj operator->*(PMF pmf)
        {
            Obj *ptr = m_container.m_objStorage[m_index];

            ptr->setPMF(pmf);

            return *ptr;
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
        return SmartPointer(*this, m_objStorage.size());
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
    PMF fMemberFunction = &Obj::f;
    PMF gMemberFunction = &Obj::g;

    std::cout << "Using ++" << std::endl;

    do
    {
        (it->*fMemberFunction)();
        (it->*gMemberFunction)();
    } while (++it);

    std::cout << "\nUsing --" << std::endl;

    it = container.end();

    while (--it)
    {
        (it->*fMemberFunction)();
        (it->*gMemberFunction)();
    }

    return 0;
}