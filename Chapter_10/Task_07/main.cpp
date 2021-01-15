#include <iostream>

class EmergencyExit
{
public:
    EmergencyExit();
    ~EmergencyExit();
};

EmergencyExit::EmergencyExit()
{
    std::cout << "Call from EmergencyExit()" << std::endl;
}

EmergencyExit::~EmergencyExit()
{
    std::cout << "Call from ~EmergencyExit()" << std::endl;
    exit(0);
}

EmergencyExit exitObj;

int main() { return 0; }