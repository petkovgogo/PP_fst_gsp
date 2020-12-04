#include <iostream>
#include "../inc/Stack.h"
#include "../inc/VideoTape.h"
#include "../inc/Person.h"

int main()
{
    const int COUNT = 25;

    Stack stack;
    stack.initialize();
    
    for (int i = 1; i <= COUNT; i++)
    {
        stack.push(new VideoTape("Video tape: " + std::to_string(i), 5.80, 3));
    }

    VideoTape* tapePtr;
    while ((tapePtr = (VideoTape*) stack.pop()) != 0)
    {
        tapePtr->print();
        delete tapePtr;
    }
    
    stack.cleanup();

    return 0;
}
