#include "../inc/Person.h"

int main()
{
    const char* FIRST_NAME = "Georgi";
    const char* LAST_NAME = "Petkov";
    const int AGE = 17;

    Person person(FIRST_NAME, LAST_NAME, AGE);

    person.m_firstName = "Stoyan";
    person.m_lastName = "Glaushev";
    person.m_age = 31;

    person.m_hobbies.push_back("Sailing");
    
    person.singFavSong();
    person.introduceSelf();
    
    return 0;
}
