#include <iostream>

namespace Me
{
    class Us
    {
        const char *m_name;
    public:
        Us() : m_name("Marvin") {}

        friend void you(Us &us);
    };
} // namespace Me

void Me::you(Me::Us &us)
{
    std::cout << "Hey, " << us.m_name << " kid, how you doin'?" << std::endl;
}

int main() 
{
    Me::Us us;

    Me::you(us);

    return 0;
}