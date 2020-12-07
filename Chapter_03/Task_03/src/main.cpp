#include <iostream>

enum Choice 
{
    Duck,
    Dragon,
    InvalidChoice = -1
};

int main()
{
    std::string input;
    Choice choice;
    bool quit = false;

    while (true)
    {
        if (quit)
        {
            break;
        }

        std::cout << "Input duck, dragon or quit" << std::endl;
        std::cin >> input;
        if (input == "duck")
        {
            choice = Duck;
        }
        else if (input == "dragon")
        {
            choice = Dragon;
        }
        else if (input == "quit")
        {
            quit = true;
            continue;
        }
        else
        {
            choice = InvalidChoice;
        }

        switch (choice)
        {
        case Duck:
            std::cout << "    _\n"
                         ".__(.)< (MEOW)\n"
                         " \\___)\n"
                      << std::endl;
            break;
        case Dragon:
            std::cout << "     \\\n"
                         "      \\                    ^    /^\n"
                         "       \\                  / \\  // \\\n"
                         "        \\   |\\___/|      /   \\//  .\\\n"
                         "         \\  /V  V  \\__  /    //  | \\ \\           *----*\n"
                         "           /     /  \\/_/    //   |  \\  \\          \\   |\n"
                         "           @___@`    \\/_   //    |   \\   \\         \\/\\ \\\n"
                         "           0/0/|       \\/_ //     |    \\    \\         \\  \\\n"
                         "      0/0/0/0/ |        \\///      |     \\     \\       |  |\n"
                         "   0/0/0/0/0/ _|_ /   (  //       |      \\     _\\     |  /\n"
                         "0/0/0/0/0/0/`/,_ _ _/  ) ; -.    |    _ _\\.-~       /   /\n"
                         "             ,-}        _      *-.|.-~-.           .~    ~\n"
                         "              `/\\      /                 ~-. _ .-~      /\n"
                         "                  *.   }            {                   /\n"
                         "                 .----~-.\\        \\-`                 .~\n"
                         "                 ///.----..<        \\             _ -~\n"
                         "                    ///-._ _ _ _ _ _ _{^ - - - - ~\""
                      << std::endl;
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
    }

    return 0;
}