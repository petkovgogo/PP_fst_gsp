#include <iostream>
#include <vector>
#include <cstring>

class StringHolder
{
public:
    static std::vector<const char *> holder;

    void *operator new(size_t size, const char *str)
    {
        holder.push_back(str);

        return ::new char[size];
    }
};

std::vector<const char *> StringHolder::holder;

char *createString(int line, const char *funcName)
{
    const int BUFF_SIZE = 80;

    char str[BUFF_SIZE];

    strcpy(str, "Created at line ");
    strcat(str, std::to_string(line).c_str());
    strcat(str, ", within function ");
    strcat(str, funcName);
    strcat(str, " in file ");
    strcat(str, __FILE__);

    char *result = new char[BUFF_SIZE];

    strcpy(result, str);

    return result;
}

StringHolder *creator() { return new (createString(__LINE__, __func__)) StringHolder; }

int main()
{
    StringHolder *shPtr = 0;

    shPtr = new (createString(__LINE__, __func__)) StringHolder;
    delete shPtr;
    shPtr = 0;

    shPtr = creator();
    delete shPtr;
    shPtr = 0;

    for (auto it = StringHolder::holder.begin(); it != StringHolder::holder.end(); it++)
    {
        std::cout << *it << std::endl;
        delete *it;
        *it = 0;
    }

    return 0;
}