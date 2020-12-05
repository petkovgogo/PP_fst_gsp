#include "../inc/Robot.h"

int main()
{
    const char* BATTERY_TYPE = "Lithium Polymer";
    const int BATTERY_CAPACITY = 80000;
    const char* ROBOT_NAME = "R. Daneel Olivaw";

    Robot::Battery battery(BATTERY_TYPE, BATTERY_CAPACITY);
    Robot robot(ROBOT_NAME, battery);
    
    robot.greeting();
    robot.m_battery->charge();
    robot.m_battery->printDetails();
    robot.beep();

    return 0;
}
