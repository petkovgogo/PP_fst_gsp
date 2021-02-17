#include <iostream>

#define PVF_DEFINITION

class Shape
{
public:
    Shape() { draw(); } // prints a warning

    virtual void draw() = 0;
};

#ifdef PVF_DEFINITION

void Shape::draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

#endif // PVF_DEFINITION

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

    return 0;
}