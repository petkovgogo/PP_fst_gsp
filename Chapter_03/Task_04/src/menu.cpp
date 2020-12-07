#include <iostream>

int main()
{
    char choice;

    while (true)
    {
        std::cout << "MAIN MENU:" << std::endl;
        std::cout << "l: left, r: right, q: quit -> ";
        std::cin >> choice;

        if (choice == 'q')
        {
            break;
        }

        switch (choice)
        {
        case 'l':
            std::cout << "LEFT MENU:" << std::endl;
            std::cout << "select a or b: ";
            std::cin >> choice;

            switch (choice)
            {
            case 'a':
                std::cout << "you chose 'a'" << std::endl;
                break;
            case 'b':
                std::cout << "you chose 'b'" << std::endl;
                break;
            default:
                std::cout << "you didn't choose a or b!" << std::endl;
                break;
            }

            break;
        case 'r':
            std::cout << "RIGHT MENU:" << std::endl;
            std::cout << "select c or d: ";
            std::cin >> choice;

            switch (choice)
            {
            case 'c':
                std::cout << "you chose 'c'" << std::endl;
                break;
            case 'd':
                std::cout << "you chose 'd'" << std::endl;
                break;
            default:
                std::cout << "you didn't choose c or d!" << std::endl;
                break;
            }
            
            break;
        default:
            std::cout << "you must type l or r or q!" << std::endl;
            break;
        }
    }

    std::cout << "quitting menu..." << std::endl;

    return 0;
}