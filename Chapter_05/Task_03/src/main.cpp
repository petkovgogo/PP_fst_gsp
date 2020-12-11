#include "../inc/Robot.h"

int main()
{
    const char *ROBOT_NAME = "R. Daneel Olivaw";

    Robot robot(ROBOT_NAME);
    greeting(robot);

    return 0;
}
