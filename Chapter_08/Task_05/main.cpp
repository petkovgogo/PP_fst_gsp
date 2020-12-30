#include <ctime>

int main()
{

    const std::time_t t = std::time(0);
    tm *now = std::localtime(&t);

    // t = std::time(0); // error!
    // now = std::localtime(&t);

    return 0;
}