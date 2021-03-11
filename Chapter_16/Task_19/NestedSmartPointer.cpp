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

class Circle
{
public:
    void draw() { std::cout << "Drawing Circle" << std::endl; }
};

// Container:
template <class T>
class ObjContainer
{
private:
    std::vector<T> a;

public:
    void add(const T &obj) { a.push_back(obj); }

    class SmartPointer;
    friend SmartPointer;
    class SmartPointer
    {
    private:
        ObjContainer &oc;
        unsigned int index;

    public:
        SmartPointer(ObjContainer &objc) : oc(objc), index(0) {}

        // Return value indicates end of list:
        bool operator++() // Prefix
        {
            if (index >= oc.a.size() || &oc.a[++index] == 0)
            {
                return false;
            }

            return true;
        }

        bool operator++(int) // Postfix
        {
            return operator++(); // Use prefix version
        }

        T *operator->() const
        {
            return &oc.a[index];
        }

        T &operator*() const
        {
            return oc.a[index];
        }
    };

    // Function to produce a smart pointer that
    // points to the beginning of the ObjContainer:
    SmartPointer begin()
    {
        return SmartPointer(*this);
    }
};

int main()
{
    const int sz = 10;
    Obj o[sz];
    ObjContainer<Obj> oc;

    for (int i = 0; i < sz; i++)
    {
        oc.add(o[i]); // Fill it up
    }

    ObjContainer<Obj>::SmartPointer sp = oc.begin();

    do
    {
        sp->f(); // Pointer dereference operator call
        sp->g();
    } while (++sp);

    ObjContainer<Circle *> circleOC;

    for (int i = 0; i < sz; i++)
    {
        circleOC.add(new Circle); // Fill it up
    }

    ObjContainer<Circle *>::SmartPointer circleSP = circleOC.begin();

    do
    {
        (*circleSP)->draw(); // Pointer dereference operator call

        delete *circleSP;
        *circleSP = 0;

    } while (++circleSP);

    return 0;
}