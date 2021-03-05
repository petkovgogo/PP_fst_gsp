#include <iostream>
#include "TStack2.h"
#include "TPStash2.h"
#include "Shape.h"

void fill(Stack<Shape> &stack)
{
    const int COUNT = 25;
    for (int i = 0; i < COUNT; i++)
    {
        if (i % 5 == 0)
        {
            stack.push(new Circle);
        }
        else if (i % 2 == 0)
        {
            stack.push(new Square);
        }
        else
        {
            stack.push(new Line);
        }
    }
}

void fill(PStash<Shape> &stash)
{
    const int COUNT = 25;
    for (int i = 0; i < COUNT; i++)
    {
        if (i % 5 == 0)
        {
            stash.add(new Line);
        }
        else if (i % 2 == 0)
        {
            stash.add(new Square);
        }
        else
        {
            stash.add(new Circle);
        }
    }
}

void iterate(Stack<Shape> &stack)
{
    std::cout << "\nIterating over a stack\n" << std::endl;

    for (Stack<Shape>::iterator it = stack.begin(); it != stack.end(); it++)
    {
        it->draw();
    }

    std::cout << std::endl;
}

void iterate(PStash<Shape> &stash)
{
    std::cout << "\nIterating over a statsh\n" << std::endl;

    for (PStash<Shape>::iterator it = stash.begin(); it != stash.end(); it++)
    {
        it->draw();
    }

    std::cout << std::endl;
}

int main()
{

    Stack<Shape> shapesStack;
    PStash<Shape> shapesStash;

    fill(shapesStack);
    fill(shapesStash);

    iterate(shapesStack);
    iterate(shapesStash);

    return 0;
}