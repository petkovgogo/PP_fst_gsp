#include "../inc/Person.h"
#include "../inc/VideoTape.h"

int main()
{
    const int MAX_TAPES = 5;
    VideoTape videoTape("The Lord of the rings: The fellowship of the Ring", 5.90, MAX_TAPES);
    Person person("John", "Doe");

    videoTape.rent(person, 5);
    videoTape.print();
    videoTape.returnTape(person);

    // What happens if more people rent, than copies are available?
    
    for (int i = 0; i < MAX_TAPES + 1; i++)
    {
        videoTape.rent(person, 6);
    }
    
    videoTape.print();
    
    // Return all tapes
    for (int i = 0; i < MAX_TAPES; i++)
    {
        videoTape.returnTape(person);
    }

    // What happens if tape gets too old?
    for (int i = 0; i < 56; i++)
    {
        videoTape.rent(person, 6);
        videoTape.returnTape(person);
    }
    
    return 0;
}
