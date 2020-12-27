#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message
{
    std::string m_message;

public:
    Message(std::string message = "Default message");
    ~Message();

    void print();
    void print(std::string bonusMessage);
};

#endif // MESSAGE_H