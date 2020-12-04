#include <string>
#include <vector>
#include "../inc/Person.h"
#include "../inc/VideoTape.h"

const int maxRentCount = 16;
static int id = 0;

VideoTape::VideoTape(std::string name, double rentPrice, int totalCopies)
{
    m_id = ++id;
    m_name = name;
    m_rentPrice = rentPrice;
    m_rentedCopies = 0;
    m_totalCopies = totalCopies;
    m_timesRented = 0;
}

VideoTape::~VideoTape() {}

void VideoTape::rent(Person &person, int daysRented)
{
    if (m_timesRented == maxRentCount)
    {
        std::cout << "Tape " << m_name << " cannot be rented anymore. It is too old." << std::endl;
        if (!m_renters.empty())
        {
            std::cout << "Please return all copies before removing tape" << std::endl;
        }
    }
    else
    {
        if (m_rentedCopies == m_totalCopies)
        {
            std::cout << "All copies have already been rented." << std::endl;
        }
        else
        {
            person.setDateRented();

            try
            {
                struct tm tempDate = tm(person.getDateRented());
                tempDate.tm_mday += daysRented;

                person.setDateDue(tempDate);

                m_renters.push_back(&person);
                m_rentedCopies++;
                m_timesRented++;

                std::cout << "Have a nice time watching this tape." << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

void VideoTape::returnTape(Person &person)
{
    if (m_timesRented == maxRentCount && m_renters.empty())
    {
        std::cout << "Tape " << m_name << " has been removed and all copies have been returned." << std::endl;
    }
    else
    {
        bool notFound = true;
        for (int i = 0; i < m_renters.size(); i++)
        {
            if (m_renters[i] == &person)
            {
                m_renters.erase(m_renters.begin() + i);
                m_rentedCopies--;
                std::cout << "Thank you for returning the tape." << std::endl;
                notFound = false;
                break;
            }
        }

        if (notFound)
        {
            std::cout << "This person has not rented this video tape." << std::endl;
        }
    }
}

void VideoTape::print()
{
    std::cout << "ID: " << m_id << std::endl
              << "Name: " << m_name << std::endl
              << "Rent price: " << m_rentPrice << std::endl
              << "Currently rented copies: " << m_rentedCopies << std::endl
              << "Total available copies: " << m_totalCopies << std::endl
              << "Times this tape was rented: " << m_timesRented << std::endl
              << "Renters: " << std::endl;

    for (auto i = m_renters.begin(); i != m_renters.end(); i++)
    {
        std::cout << **i << std::endl;
    }
}