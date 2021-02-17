#include <iostream>

class Shape
{
public:
    Shape() { draw(); } // prints a warning

    virtual void draw() = 0;
};

void Shape::draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

class Circle : public Shape
{
public:
    Circle() { draw(); }

    void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Square : public Shape
{
public:
    Square() { draw(); }

    void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Triangle : public Shape
{
public:
    Triangle() { draw(); }

    void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

#define PASS_BY_REF
#ifdef PASS_BY_REF

void passByRef(Shape &) {} // OK

#else

void passByValue(Shape) {} // error: cannot declare parameter to be of abstract type ‘Shape’

#endif // PASS_BY_REF

int main()
{
    const int COUNT = 25;

    // Shape shape; // cannot create an instance of an abstract class

    Shape **shapeArr = new Shape *[COUNT];

    for (int i = 1; i <= COUNT; i++)
    {
        if (i % 5 == 0)
        {
            shapeArr[i] = new Circle;
        }
        else if (i % 2 == 0)
        {
            shapeArr[i] = new Square;
        }
        else
        {
            shapeArr[i] = new Triangle;
        }

        // shapeArr[i]->draw();
    }

    delete[] shapeArr;

    Circle circleObj;

#ifdef PASS_BY_REF

    passByRef(circleObj); // OK

#else

    passByValue(circleObj); // error: cannot allocate an object of abstract type ‘Shape’

#endif // PASS_BY_REF

    return 0;
}