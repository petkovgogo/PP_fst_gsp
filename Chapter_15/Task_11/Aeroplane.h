#ifndef AEROPLANE_H
#define AEROPLANE_H

#include <iostream>
#include "Aircraft.h"

class Aeroplane : public Aircraft
{
private:
    static int flightId;
    const int m_id;

public:
    Aeroplane();

    void print(std::ostream &out) const;

    void board() const;
    void prepare() const;
    void standby() const;
    void takeoff() const;
    void fly() const;
    void land() const;
};

int Aeroplane::flightId = 700;

inline Aeroplane::Aeroplane() : m_id(++flightId) {}

inline void Aeroplane::print(std::ostream &out) const { out << "flight #" << m_id; }

inline void Aeroplane::board() const { std::cout << "Please proseed to board flight #" << m_id << "\n"; }
inline void Aeroplane::prepare() const { std::cout << "Starting the engines, performing final checks...\n"; }
inline void Aeroplane::standby() const { std::cout << "Awaiting clearence for takeoff...\n"; }
inline void Aeroplane::takeoff() const { std::cout << "Taking off...\n"; }
inline void Aeroplane::fly() const { std::cout << "Flying... We are entering turbulence, please fasten your seatbelts.\n"; }
inline void Aeroplane::land() const { std::cout << "Landing...\n"; }

#endif // AEROPLANE_H