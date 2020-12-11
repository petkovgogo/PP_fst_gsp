#ifndef ROBOT_H
#define ROBOT_H

#include <string>

class Robot;

void greeting(Robot &robot);

class Robot
{
private:
    std::string m_name;

public:
    Robot(std::string name);
    ~Robot();

    friend void greeting(Robot &robot);
};

#endif // ROBOT_H