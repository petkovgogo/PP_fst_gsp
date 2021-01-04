#ifndef MY_STRING_H
#define MY_STRING_H

class MyString
{
    const char *m_text;

public:
    MyString(const char *text);

    void printText() const;
};

#endif // MY_STRING_H