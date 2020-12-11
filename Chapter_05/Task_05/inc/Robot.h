#ifndef ROBOT_H
#define ROBOT_H

#include <string>

class Creator;

#include "Creator.h"

class Robot
{
private:
    std::string m_name;

public:
    Robot(std::string name);
    ~Robot();

    std::string getName() const;
    void introduceCreator(Creator *creator);
};

#endif // ROBOT_H