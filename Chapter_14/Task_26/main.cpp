#include <iostream>
#include <vector>

class Rock
{
private:
    static int constructorsCalled; // for an easier tracing
    static int ccsCalled;          // for an easier tracing
    static int destructorsCalled;  // for an easier tracing

public:
    Rock()
    {
        std::cout << __PRETTY_FUNCTION__
                  << " #" << ++constructorsCalled
                  << std::endl;
    }

    Rock(const Rock &)
    {
        std::cout << __PRETTY_FUNCTION__
                  << " #" << ++ccsCalled
                  << std::endl;
    }

    ~Rock()
    {
        std::cout << __PRETTY_FUNCTION__
                  << " #" << ++destructorsCalled
                  << std::endl;
    }

    Rock &operator=(Rock &origin)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        if (this == &origin)
        {
            /* self assignment */
        }

        return *this;
    }
};

int Rock::constructorsCalled;
int Rock::ccsCalled;
int Rock::destructorsCalled;

int main()
{
    const int COUNT = 12;

    std::vector<Rock> rocks; // destructors are called

    for (int i = 0; i < COUNT; i++)
    {
        // exactly 12 objects are created using the default constructor,
        // but the copy-constructor is called much more than that, which could be part
        // of the std::vector implementation
        rocks.push_back(Rock());
    }

    rocks[0] = rocks[1]; // call an assignment operator

    std::cout << std::endl; // just an empty line for console formatting

    std::vector<Rock *> rockPtrs; // destructors are called only if cleanup is performed

    for (int i = 0; i < COUNT; i++)
    {
        rockPtrs.push_back(new Rock);
    }

#define CLEANUP
#ifdef CLEANUP

    for (auto it = rockPtrs.begin(); it != rockPtrs.end(); it++)
    {
        delete *it;
        *it = 0;
        rockPtrs.erase(it--);
    }

#endif // CLEANUP

    // possible to declare, but impossible to initialise,
    // because a vector needs assignable values and references
    // are not assignable
    // std::vector<Rock &> rockRefs; 

    return 0;
}