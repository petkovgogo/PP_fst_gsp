#ifndef COLOUR_H
#define COLOUR_H

enum Hue
{
    RED,
    BLUE,
    YELLOW
};

class Colour
{
    Hue m_colour;

public:
    Colour(Hue colour) { m_colour = colour; };

    void setColour(Hue colour);
    Hue getColour();
};

inline void Colour::setColour(Hue colour)
{
    m_colour = colour;
}

inline Hue Colour::getColour()
{
    return m_colour;
}

inline const char *hueToText(Hue hue)
{
    switch (hue)
    {
    case RED:
        return "Red";
        break;

    case BLUE:
        return "Blue";
        break;

    case YELLOW:
        return "Yellow";
        break;

    default:
        return "Invalid";
        break;
    }
}

#endif // COLOUR_H