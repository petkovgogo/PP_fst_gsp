#include <iostream>
#include <sstream>
#include <fstream>

class Character
{
private:
    char m_char;

public:
    Character(char symbol) : m_char(symbol) {}

    friend std::istream &operator>>(std::istream &in, Character &character);
    friend std::ostream &operator<<(std::ostream &out, Character &character);
};

std::istream &operator>>(std::istream &in, Character &character)
{
    in >> character.m_char;

    return in;
}

std::ostream &operator<<(std::ostream &out, Character &character)
{
    out << character.m_char;

    return out;
}

int main()
{
    Character symbol('*');

    std::cin >> symbol;
    std::cout << symbol << std::endl;

    std::istringstream iss("Lorem ipsum");
    std::ofstream output("Output.txt");

    while (iss >> symbol)
    {
        output << symbol;
    }
    
    output << std::endl;

    return 0;
}