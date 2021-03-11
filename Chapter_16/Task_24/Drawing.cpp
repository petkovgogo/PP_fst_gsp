#include <vector> // Uses Standard vector too!
#include "TPStash2.h"
#include "TStack2.h"
#include "Shape.h"

// A Drawing is primarily a container of Shapes:
class Drawing : public PStash<Shape>
{
public:
    ~Drawing() { std::cout << "~Drawing" << std::endl; }
};

// A Plan is a different container of Shapes:
class Plan : public Stack<Shape>
{
public:
    ~Plan() { std::cout << "~Plan" << std::endl; }
};

// A Schematic is a different container of Shapes:
class Schematic : public std::vector<Shape *>
{
public:
    ~Schematic() { std::cout << "~Schematic" << std::endl; }
};

// A function template:
template <class Iter>
void drawAll(Iter start, Iter end)
{
    while (start != end)
    {
        (*start)->draw();
        start++;
    }
}

template <class Iter>
void eraseAll(Iter start, Iter end)
{
    while (start != end)
    {
        (*start)->erase();
        start++;
    }
}

int main()
{
    // Each type of container has
    // a different interface:
    Drawing d;
    d.add(new Circle);
    d.add(new Square);
    d.add(new Line);

    Plan p;
    p.push(new Line);
    p.push(new Square);
    p.push(new Circle);

    Schematic s;
    s.push_back(new Square);
    s.push_back(new Circle);
    s.push_back(new Line);

    Shape *sarray[] = {new Circle, new Square, new Line};

    // The iterators and the template function
    // allow them to be treated generically:
    std::cout << "Drawing d:" << std::endl;
    drawAll(d.begin(), d.end());

    std::cout << std::endl;
    eraseAll(d.begin(), d.end());

    std::cout << "\nPlan p:" << std::endl;
    drawAll(p.begin(), p.end());
    
    std::cout << std::endl;
    eraseAll(p.begin(), p.end());

    std::cout << "\nSchematic s:" << std::endl;
    drawAll(s.begin(), s.end());

    std::cout << std::endl;
    eraseAll(s.begin(), s.end());
    
    // Even works with array pointers:
    std::cout << "\nArray sarray:" << std::endl;
    drawAll(sarray, sarray + sizeof(sarray) / sizeof(*sarray));

    std::cout << std::endl;
    eraseAll(sarray, sarray + sizeof(sarray) / sizeof(*sarray));

    std::cout << "End of main\n" << std::endl;

    return 0;
}