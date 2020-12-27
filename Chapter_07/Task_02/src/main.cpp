#include "../inc/Message.h"

int main()
{
    const char *BONUS_MESSAGE = "Bonus message";

    Message message;

    message.print();
    message.print(BONUS_MESSAGE);

    return 0;
}
