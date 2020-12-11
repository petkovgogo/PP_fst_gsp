#ifndef LIBC_H
#define LIBC_H

#include <string>

class Libc
{
private:
    /*
    std::string a;
    std::string b;
    std::string c;
    */

   std::string arr[3];

public:
    Libc();
    ~Libc();

    void setA(std::string text);
    void setB(std::string text);
    void setC(std::string text);

    std::string getA() const;
    std::string getB() const;
    std::string getC() const;
};

#endif // LIBC_H