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
    virtual ~Instrument() {}

    void play(note) const
    {
        std::cout << "Instrument::play" << std::endl;
    }

    const char *what() const
    {
        return "Instrument";
    }

    // Assume this will modify the object:
    void adjust(int) {}
};

class Wind : public Instrument
{
public:
    void play(note) const
    {
        std::cout << "Wind::play" << std::endl;
    }

    const char *what() const { return "Wind"; }
    void adjust(int) {}
};

class Percussion : public Instrument
{
public:
    void play(note) const
    {
        std::cout << "Percussion::play" << std::endl;
    }

    const char *what() const { return "Percussion"; }
    void adjust(int) {}
};

class Stringed : public Instrument
{
public:
    void play(note) const
    {
        std::cout << "Stringed::play" << std::endl;
    }

    const char *what() const { return "Stringed"; }
    void adjust(int) {}
};

class Brass : public Wind
{
public:
    void play(note) const
    {
        std::cout << "Brass::play" << std::endl;
    }

    const char *what() const { return "Brass"; }
};

class Woodwind : public Wind
{
public:
    void play(note) const
    {
        std::cout << "Woodwind::play" << std::endl;
    }

    const char *what() const { return "Woodwind"; }
};

// Identical function from before:
void tune(Instrument &i)
{
    // This is a bad idea, because you are just guessing what the object is, based on the result of 
    // dynamic_cast, that slows the program and adds many more lines, which makes the code less readable
    Wind *windPtr = dynamic_cast<Wind *>(&i);
    Percussion *pptr = dynamic_cast<Percussion *>(&i);
    Stringed *sptr = dynamic_cast<Stringed *>(&i);
    Brass *bptr = dynamic_cast<Brass *>(&i);
    Woodwind *wwptr = dynamic_cast<Woodwind *>(&i);

    if (pptr)
    {
        pptr->play(middleC);
    }
    else if (sptr)
    {
        sptr->play(middleC);
    }
    else if (bptr)
    {
        bptr->play(middleC);
    }
    else if (wwptr)
    {
        wwptr->play(middleC);
    }
    else if (windPtr)
    {
        windPtr->play(middleC);
    }
    else
    {
        i.play(middleC);
    }
}

// New function:
void f(Instrument &i)
{
    Wind *windPtr = dynamic_cast<Wind *>(&i);
    Percussion *pptr = dynamic_cast<Percussion *>(&i);
    Stringed *sptr = dynamic_cast<Stringed *>(&i);
    Brass *bptr = dynamic_cast<Brass *>(&i);
    Woodwind *wwptr = dynamic_cast<Woodwind *>(&i);

    if (pptr)
    {
        pptr->adjust(1);
    }
    else if (sptr)
    {
        sptr->adjust(1);
    }
    else if (bptr)
    {
        bptr->adjust(1);
    }
    else if (wwptr)
    {
        wwptr->adjust(1);
    }
    else if (windPtr)
    {
        windPtr->adjust(1);
    }
    else
    {
        i.adjust(1);
    }
}

// Upcasting during array initialization:
// Instrument *A[] = {
//     new Wind,
//     new Percussion,
//     new Stringed,
//     new Brass,
// };

int main()
{
    Wind flute;
    Percussion drum;
    Stringed violin;
    Brass flugelhorn;
    Woodwind recorder;

    tune(flute);
    tune(drum);
    tune(violin);
    tune(flugelhorn);
    tune(recorder);
    f(flugelhorn);

    return 0;
}