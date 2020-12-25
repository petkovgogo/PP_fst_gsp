#include <iostream>

class Simple
{
    int m_id;

public:
    Simple(int id);
    ~Simple();
};

Simple::Simple(int id)
{
    m_id = id;
    std::cout << "I am object number " << m_id << " created" << std::endl;
}

Simple::~Simple()
{
    std::cout << "Object number " << m_id << " destroyed" << std::endl;
}

int main()
{
    const int COUNT = 25;

    for (int i = 0; i < COUNT; i++)
    {
        Simple simple(i);

        if (i == 5)
        {
            goto after_loop;
        }
            
    }

    after_loop: // Destructor of object number 5 is called

    return 0;
}