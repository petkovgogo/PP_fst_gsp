#ifndef STRING_VECTOR_H
#define STRING_VECTOR_H

#include <vector>
#include <string>

class StringVector : public std::vector<void *>
{
public:
    void push_back(std::string *data)
    {
        std::vector<void *>::push_back(data);
    }

    std::string *operator[](int index)
    {
        return static_cast<std::string *>(std::vector<void *>::operator[](index));
    }
};

#endif // STRING_VECTOR_H