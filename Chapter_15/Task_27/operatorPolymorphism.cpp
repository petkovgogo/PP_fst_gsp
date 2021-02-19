#include <iostream>

class Matrix;
class Scalar;
class Vector;
class Tensor;

class Math
{
public:
    virtual Math &operator*(Math &rv) = 0;
    virtual Math &multiply(Matrix *) = 0;
    virtual Math &multiply(Scalar *) = 0;
    virtual Math &multiply(Vector *) = 0;
    virtual Math &multiply(Tensor *) = 0;

    virtual ~Math() {}
};

class Matrix : public Math
{
public:
    Math &operator*(Math &rv) { return rv.multiply(this); }

    Math &multiply(Matrix *)
    {
        std::cout << "Matrix * Matrix" << std::endl;
        return *this;
    }

    Math &multiply(Scalar *)
    {
        std::cout << "Scalar * Matrix" << std::endl;
        return *this;
    }

    Math &multiply(Vector *)
    {
        std::cout << "Vector * Matrix" << std::endl;
        return *this;
    }

    Math &multiply(Tensor *)
    {
        std::cout << "Tensor * Matrix" << std::endl;
        return *this;
    }
};

class Scalar : public Math
{
public:
    Math &operator*(Math &rv) { return rv.multiply(this); }

    Math &multiply(Matrix *)
    {
        std::cout << "Matrix * Scalar" << std::endl;
        return *this;
    }

    Math &multiply(Scalar *)
    {
        std::cout << "Scalar * Scalar" << std::endl;
        return *this;
    }

    Math &multiply(Vector *)
    {
        std::cout << "Vector * Scalar" << std::endl;
        return *this;
    }

    Math &multiply(Tensor *)
    {
        std::cout << "Tensor * Scalar" << std::endl;
        return *this;
    }
};

class Vector : public Math
{
public:
    Math &operator*(Math &rv) { return rv.multiply(this); }

    Math &multiply(Matrix *)
    {
        std::cout << "Matrix * Vector" << std::endl;
        return *this;
    }

    Math &multiply(Scalar *)
    {
        std::cout << "Scalar * Vector" << std::endl;
        return *this;
    }

    Math &multiply(Vector *)
    {
        std::cout << "Vector * Vector" << std::endl;
        return *this;
    }

    Math &multiply(Tensor *)
    {
        std::cout << "Tensor * Vector" << std::endl;
        return *this;
    }
};

class Tensor : public Math
{
public:
    Math &operator*(Math &rv) { return rv.multiply(this); }

    Math &multiply(Matrix *)
    {
        std::cout << "Matrix * Tensor" << std::endl;
        return *this;
    }

    Math &multiply(Scalar *)
    {
        std::cout << "Scalar * Tensor" << std::endl;
        return *this;
    }

    Math &multiply(Vector *)
    {
        std::cout << "Vector * Tensor" << std::endl;
        return *this;
    }

    Math &multiply(Tensor *)
    {
        std::cout << "Tensor * Tensor" << std::endl;
        return *this;
    }
};

int main()
{
    Matrix m;
    Vector v;
    Scalar s;
    Tensor t;

    Math *math[] = {&m, &v, &s, &t};

    for (int i = 0; i < 4; i++)
    {
        std::cout << std::endl;

        for (int j = 0; j < 4; j++)
        {
            Math &m1 = *math[i];
            Math &m2 = *math[j];
            m1 * m2;
        }
    }

    return 0;
}