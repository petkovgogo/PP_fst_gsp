#include <iostream>

struct Robot
{
    void greeting()
    {
        std::cout << "Hello fellow human :]!" << std::endl;
    }
};

int main()
{
    Robot robot;
    robot.greeting();
    
    return 0;
}

