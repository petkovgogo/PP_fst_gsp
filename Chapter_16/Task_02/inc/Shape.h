#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
public:
    virtual ~Shape() { std::cout << __PRETTY_FUNCTION__ << "\n" << std::endl; }

    virtual void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Circle : public Shape
{
public:
    virtual ~Circle() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Square : public Shape
{
public:
    virtual ~Square() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Triangle : public Shape
{
public:
    virtual ~Triangle() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void draw() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

#endif // SHAPE_H