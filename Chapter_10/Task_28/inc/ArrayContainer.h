#ifndef ARRAY_CONTAINER_H
#define ARRAY_CONTAINER_H

class ArrayContainer
{
private:
    static const int m_arr1[];
    static int m_arr2[];

public:
    ArrayContainer();

    static void printArr1();
    static void printArr2();
};

#endif // ARRAY_CONTAINER_H