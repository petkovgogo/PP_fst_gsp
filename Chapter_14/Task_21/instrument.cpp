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
    void play(note) const {}
    void prepare() const { std::cout << "Preparing..." << std::endl; }
};

// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument {};

void tune(Instrument &i)
{
    // ...
    i.prepare();
    i.play(middleC);
}

int main()
{
    Wind flute;
    tune(flute); // Upcasting

    return 0;
}