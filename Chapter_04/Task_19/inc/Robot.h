#ifndef ROBOT_H
#define ROBOT_H

#include <string>

struct Robot
{
    std::string m_name;
    struct Battery
    {
        std::string m_type;
        int m_capacity;

        Battery(std::string type, int capacity);
        void charge();
        void printDetails();
    } * m_battery;

    Robot(std::string name, Battery &battery);
    void greeting();
    void beep();
};

#endif // ROBOT_H