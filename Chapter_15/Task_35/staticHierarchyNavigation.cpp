#include <iostream>

enum ShapeType
{
    Shapes,
    Circles,
    Squares,
    Others
};

class Shape
{
public:
    virtual ~Shape(){};

    virtual ShapeType whatAmI() { return Shapes; }
};

class Circle : public Shape
{
public:
    virtual ShapeType whatAmI() { return Circles; }
};

class Square : public Shape
{
public:
    virtual ShapeType whatAmI() { return Squares; }
};

class Other
{
public:
    virtual ShapeType whatAmI() { return Others; }
};

int main()
{
// #define CIRCLE_OBJ
#ifdef CIRCLE_OBJ

    Circle c;
    Shape *s = &c;

#else

    Square sq;
    Shape *s = &sq; // Upcast: normal and OK

#endif // CIRCLE_OBJ

    Circle *cp = 0;
    Square *sp = 0;

    if (s->whatAmI() == Circles)
    {
        cp = static_cast<Circle *>(s);
    }
    else if (s->whatAmI() == Squares)
    {
        sp = static_cast<Square *>(s);
    }

    if (cp)
    {
        std::cout << "It's a circle!" << std::endl;
    }
    else if (sp)
    {
        std::cout << "It's a square!" << std::endl;
    }

    // Static navigation is ONLY an efficiency hack;
    // dynamic_cast is always safer. However:
    // Other* op = static_cast<Other*>(s);
    // Conveniently gives an error message, while
    // Other *op2 = (Other *)s;
    // does not

    return 0;
}