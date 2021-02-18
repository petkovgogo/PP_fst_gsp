#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <vector>
#include "Aircraft.h"

class Tower
{
private:
    std::vector<Aircraft *> m_aircrafts;

    Aircraft *findAircraft(Aircraft *aircraft) const;
    int findAircraftIndex(Aircraft *aircraft) const;

public:
    void assignAircraft(Aircraft &aircraft);
    void unassignAircraft(Aircraft &aircraft);

    void allowTakeoff(Aircraft &aircraft) const;
    void warnAircraft(Aircraft &ac1, Aircraft &ac2) const;
    void allowLanding(Aircraft &aircraft) const;
};

Aircraft *Tower::findAircraft(Aircraft *aircraft) const
{
    for (auto it = m_aircrafts.begin(); it != m_aircrafts.end(); it++)
    {
        if (*it == aircraft)
        {
            return *it;
        }
    }

    return 0;
}

int Tower::findAircraftIndex(Aircraft *aircraft) const
{
    for (size_t i = 0; i < m_aircrafts.size(); i++)
    {
        if (m_aircrafts[i] == aircraft)
        {
            return i;
        }
    }

    return 0;
}

inline void Tower::assignAircraft(Aircraft &aircraft)
{
    Aircraft *acPtr = findAircraft(&aircraft);

    if (acPtr)
    {
        std::cout << aircraft << " is already assigned.\n" << std::endl;

        return;
    }

    m_aircrafts.push_back(&aircraft);
}

inline void Tower::unassignAircraft(Aircraft &aircraft)
{
    int index = findAircraftIndex(&aircraft);

    if (index)
    {
        m_aircrafts.erase(m_aircrafts.begin() + index);

        return;
    }

    std::cout << aircraft << " is not assigned to this tower.\n" << std::endl;
}

inline void Tower::allowTakeoff(Aircraft &aircraft) const
{
    Aircraft *acPtr = findAircraft(&aircraft);

    if (acPtr)
    {
        aircraft.board();
        aircraft.prepare();
        aircraft.standby();

        std::cout << "Tower: Permission granted."
                  << std::endl;

        aircraft.takeoff();
        std::cout << std::endl;

        return;
    }

    std::cout << aircraft << " is not assigned to this tower.\n" << std::endl;
}

inline void Tower::warnAircraft(Aircraft &ac1, Aircraft &ac2) const
{
    Aircraft *acPtr1 = findAircraft(&ac1);
    Aircraft *acPtr2 = findAircraft(&ac2);

    if (acPtr1 && acPtr2)
    {
        std::cout << "\nAttention " << ac1
                  << " you are on a colission course with " << ac2
                  << "! Change your couse by 10 degrees to the North.\n"
                  << std::endl;

        return;
    }

    std::cout << "One (or both) of theese aircrafts does (do) are not assigned to this tower\n" << std::endl;
}

inline void Tower::allowLanding(Aircraft &aircraft) const
{
    Aircraft *acPtr = findAircraft(&aircraft);

    if (acPtr)
    {
        std::cout << "Aircraft " << aircraft << " is asking permission for landing.\n"
                  << "Tower: Permission granted."
                  << std::endl;

        aircraft.land();
        std::cout << std::endl;

        return;
    }

    std::cout << aircraft << " is not assigned to this tower." << std::endl;
}

#endif // TOWER_H