#ifndef TCONTAINER_H
#define TCONTAINER_H

#include <vector>

template <class T>
class TContainer : public std::vector<void *>
{
public:
    void push_back(T *data)
    {
        std::vector<void *>::push_back(data);
    }

    T *operator[](int index)
    {
        return static_cast<T *>(std::vector<void *>::operator[](index));
    }
};

#endif // TCONTAINER_H