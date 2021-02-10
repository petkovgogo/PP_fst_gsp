class Vechicle
{
private:
    int m_fuelCapacity;

public:
    Vechicle(int fuelCapacity) : m_fuelCapacity(fuelCapacity) {}

    int getFuelCapacity() const { return m_fuelCapacity; }

    void move() const {}
    void stop() const {}
};

class Engine
{
public:
    void start() const {}
    void rev() const {}
    void stop() const {}
};

class Wheel
{
public:
    void inflate(int) const {}
};

class Window
{
public:
    void rollup() const {}
    void rolldown() const {}
};

class Door
{
public:
    Window window;
    void open() const {}
    void close() const {}
};

class Car : public Vechicle
{
public:
    Car(int fuelCapacity) : Vechicle(fuelCapacity) {}

    Engine engine;
    Wheel wheel[4];
    Door left, right; // 2-door
};

int main()
{
    Car car(120);

    car.move();            // Vechicle member function
    car.stop();            // Vechicle member function
    car.getFuelCapacity(); // Vechicle member function
    
    car.left.window.rollup();
    car.wheel[0].inflate(72);

    return 0;
}