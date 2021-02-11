#ifndef BUSINESS_TRAVELER_H
#define BUSINESS_TRAVELER_H

#include "Traveler.h"
#include "Pager.h"

#include <iostream>

class BusinessTraveler : public Traveler
{
private:
    Pager m_pager;

public:
    BusinessTraveler();
    BusinessTraveler(const char *str);
    BusinessTraveler(const BusinessTraveler &traveler);

    BusinessTraveler &operator=(const BusinessTraveler &origin);
    friend std::ostream &operator<<(std::ostream &out, const BusinessTraveler &traveler);
};

inline BusinessTraveler::BusinessTraveler() : Traveler(""), m_pager("") {}
inline BusinessTraveler::BusinessTraveler(const char *str) : Traveler(str), m_pager(str) {}
inline BusinessTraveler::BusinessTraveler(const BusinessTraveler &traveler) : Traveler(traveler), m_pager(traveler.m_pager) {}

inline BusinessTraveler &BusinessTraveler::operator=(const BusinessTraveler &origin)
{
    if (this != &origin)
    {
        Traveler::operator=(origin);
        m_pager = origin.m_pager;
    }
    
    return *this;
}

inline std::ostream &operator<<(std::ostream &out, const BusinessTraveler &traveler)
{
    return out << static_cast<Traveler>(traveler) << std::endl << traveler.m_pager;
}

#endif // BUSINESS_TRAVELER_H