#ifndef OSHAPE_H
#define OSHAPE_H

class Object {};
class Shape {};

class Circle : public Shape {};
class Square : public Shape {};
class Triangle : public Shape {};

class OShape : public Object, public Shape {};

class OCircle : public OShape, public Circle {};
class OSquare : public OShape, public Square {};
class OTriangle : public OShape, public Triangle {};

#endif // OSHAPE_H