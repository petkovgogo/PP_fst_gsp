#include <iostream>

enum note
{
    middleC,
    Csharp,
    Cflat
}; // Etc.

// #define VIRTUAL_FUNC

class Instrument
{
public:
#ifdef VIRTUAL_FUNC

    virtual void play(note n) const

#else

    void play(note n) const

#endif // VIRTUAL_FUNC

    {
        std::cout << "Instrument::play() - playing note " << n << std::endl;
    }
};

// Wind objects are Instruments
// because they have the same interface:
class Wind : public Instrument
{
    void play(note n) const
    {
        std::cout << "Wind::play() - playing note " << n << std::endl;
    }
};

void tune(Instrument &i)
{
    // calling the function without it being virtual uses the Instrument::play() version,
    // whereas calling it when it is virtual uses the Wind::play() one

    // when using the wind as an instrument, we might need
    // the wind behaviour of the redefined instrument functions.
    // Then, without the virtual function, we wouldn't get the desired results
    i.play(Csharp);
}

int main()
{
    Wind flute;
    tune(flute); // Upcasting

    return 0;
}