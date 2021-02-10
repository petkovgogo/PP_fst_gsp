#include <iostream>
#include <vector>

class StringVector : public std::vector<void *>
{
public:
    void push_back(const char *str)
    {
        std::vector<void *>::push_back(reinterpret_cast<void *>(const_cast<char *>(str)));
    }

    const char *operator[](int index)
    {
        return reinterpret_cast<const char *>(std::vector<void *>::operator[](index));
    }
};

// #define USE_VOID_PTR

int main()
{
    StringVector strVector;

    const char *str = "Lorem ipsum dolor sit amet";
    strVector.push_back(str);

#ifdef USE_VOID_PTR

    int num = 42;
    void *mystery = &num;
    strVector.push_back(mystery); // function is redefined

#endif // USE_VOID_PTR

    std::cout << strVector[0] << std::endl;

    return 0;
}