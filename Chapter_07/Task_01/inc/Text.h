#ifndef TEXT_H
#define TEXT_H

#include <string>

class Text
{
    std::string m_text;

public:
    Text();
    Text(std::string fileName);
    ~Text();

    std::string contents();
};

#endif // TEXT_H