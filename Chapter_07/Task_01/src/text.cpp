#include <string>
#include <fstream>
#include "../inc/Text.h"

Text::Text()
{
    m_text = "No file given :/";
}

Text::Text(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;

    while (getline(file, line))
    {
        m_text += "\n";
        m_text += line;
    }
}

Text::~Text() {}

std::string Text::contents()
{
    return m_text;
}
