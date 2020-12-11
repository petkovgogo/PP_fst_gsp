#include "../inc/Creator.h"
#include "../inc/Robot.h"

int main()
{
    const char *CREATOR_NAME = "The Creator";
    const char *ROBOT_NAME = "R. Daneel Olivaw";
    
    Creator creator(CREATOR_NAME);
    Robot robot(ROBOT_NAME);
    
    creator.introduceCreation(&robot);
    robot.introduceCreator(&creator);
    Corporation::authenticate(creator);

    return 0;
}
