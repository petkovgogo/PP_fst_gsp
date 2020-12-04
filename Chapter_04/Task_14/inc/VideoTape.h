#ifndef VIDEO_TAPE_H
#define VIDEO_TAPE_H

#include <string>
#include <vector>
#include "Person.h"

class VideoTape
{
private:
    int m_id;
    std::string m_name;
    double m_rentPrice;
    std::vector<Person *> m_renters;
    int m_rentedCopies;
    int m_totalCopies;
    int m_timesRented;
    bool m_isRemoved;

public:
    VideoTape(std::string name, double rentPrice, int totalCopies);
    ~VideoTape();

    void rent(Person &person, int daysRented);
    void returnTape(Person &person);
    void print();
};

#endif // VIDEO_TAPE_H