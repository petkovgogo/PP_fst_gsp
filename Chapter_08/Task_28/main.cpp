#include <iostream>

class Bird
{
public:
    void fly() { std::cout << "I'm flying" << std::endl; }
};

class Rock {};

int main()
{
    Rock rock;
    void *obj = &rock;
    // Bird *pBird = obj; // error when done without casting
    Bird *pBird = static_cast<Bird *>(obj); // works fine (?), but is dangerous, because no error is thrown

    pBird->fly();   

    return 0;
}