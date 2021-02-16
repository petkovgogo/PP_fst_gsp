#include <iostream>

class Shape
{
public:
    virtual void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Circle : public Shape
{
public:
    void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Square : public Shape
{
public:
    void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Triangle : public Shape
{
public:
    void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main()
{
    const int COUNT = 25;
    Shape **shapeArr = new Shape*[COUNT];

    for (int i = 1; i <= COUNT; i++)
    {
        if (i % 5 == 0)
        {
            shapeArr[i] = new Circle;
        }
        else if(i % 2 == 0)
        {
            shapeArr[i] = new Square;
        }
        else
        {
            shapeArr[i] = new Triangle;
        }

        shapeArr[i]->draw();
    }

    delete[] shapeArr;
    
    return 0;
}