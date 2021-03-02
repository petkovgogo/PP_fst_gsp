#include "../inc/Shape.h"
#include "../inc/TStack2.h"

int main()
{
    const int COUNT = 25;
    Stack<Shape> shapes;

    for (int i = 0; i < COUNT; i++)
    {
        if (i % 5 == 0)
        {
            shapes.push(new Circle);
        }
        else if (i % 2 == 0)
        {
            shapes.push(new Square);
        }
        else
        {
            shapes.push(new Triangle);
        }
    }

    for (Stack<Shape>::iterator sit = shapes.begin(); sit != shapes.end(); sit++)
    {
        sit->draw();
    }

    const int DELETE_COUNT = 7;

    std::cout << "\n\nDeleting popped elements:\n" << std::endl;

    for (int i = 0; i < DELETE_COUNT; i++)
    {
        delete shapes.pop();
    }

    std::cout << "\nCleaned up by Stack<Shapes>:\n" << std::endl;

    return 0;
}