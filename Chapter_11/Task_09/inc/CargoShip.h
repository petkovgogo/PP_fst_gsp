#ifndef CARGO_SHIP_H
#define CARGO_SHIP_H

class CargoShip
{
private:
    const int m_capacity;
    int m_cargo;

public:
    CargoShip(int capacity, int cargo = 0);
    
    void load(int cargo);
    void unload(int cargo);
    void sail() const;
    void printCurrentLoad() const;
};

#endif // CARGO_SHIP_H