#ifndef CREATOR_H
#define CREATOR_H

#include <string>

class Robot;

#include "Robot.h"

class Creator
{
private:
    std::string m_name;
public:
    Creator(std::string name);
    ~Creator();

    std::string getName() const;
    void introduceCreation(Robot *creation);
};

#endif // CREATOR_H