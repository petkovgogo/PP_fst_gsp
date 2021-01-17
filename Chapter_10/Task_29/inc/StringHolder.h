#ifndef STRING_HOLDER_H
#define STRING_HOLDER_H

#include <string>

class StringHolder
{
private:
    std::string m_text;

public:
    StringHolder(std::string text);

    void print() const;
};

#endif // STRING_HOLDER_H