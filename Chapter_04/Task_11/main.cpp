#include <iostream>

int main()
{
    #ifdef SECRET_MESSAGE
    std::cout << "This is the secret message" << std::endl;
    #endif // SECRET_MESSAGE

    #ifndef SECRET_MESSAGE
    std::cout << "This is just a message" << std::endl;
    #endif // SECRET_MESSAGE

    return 0;
}
