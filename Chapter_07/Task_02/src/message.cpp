#include <iostream>
#include <string>
#include "../inc/Message.h"

Message::Message(std::string message)
{
    m_message = message;
}

Message::~Message() {}

void Message::print()
{
    std::cout << m_message << std::endl;
}

void Message::print(std::string bonusMessage)
{
    std::cout << m_message << " " << bonusMessage << std::endl;
}

/*
The bonus message is not used as a flag and does not change
the output if defaulted to "", so it's perfectly safe to define
the function with a default argument:

in Message.h:
    void print(std::string bonusMessage = "");

in message.cpp:
    void Message::print(std::string bonusMessage)
    {
        std::cout << m_message << " " << bonusMessage << std::endl;
    }
*/