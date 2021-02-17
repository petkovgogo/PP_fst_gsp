#include <iostream>

enum note
{
    middleC,
    Csharp,
    Cflat
}; // Etc.

class Instrument
{
public:
    virtual void play(note) const
    {
        std::cout << "Instrument::play" << std::endl;
    }

    virtual void prepare() const
    {
        std::cout << "Instrument::prepare" << std::endl;
    }
};

// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument
{
public:
    // Override interface function:
    void play(note) const
    {
        std::cout << "Wind::play" << std::endl;
    }

    void prepare() const
    {
        std::cout << "Wind::prepare" << std::endl;
    }
};

void tune(Instrument &i)
{
    // ...
    i.play(middleC);
    i.prepare();
}

int main()
{
    Wind flute;

    tune(flute); // Upcasting

    return 0;
}