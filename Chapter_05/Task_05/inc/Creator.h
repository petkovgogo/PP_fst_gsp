#ifndef CREATOR_H
#define CREATOR_H

#include <string>

class Robot;

#include "Robot.h"
#include "Corporation.h"

class Creator
{
    friend Robot;

private:
    std::string m_name;

public:
    Creator(std::string name);
    ~Creator();

    void introduceCreation(Robot *creation);
    friend void Corporation::authenticate(Creator &employee);
};

#endif // CREATOR_H