#include <iostream>

int main()
{
    std::string input;
    int choice = -1;
    bool quit = false;

    while (true)
    {
        std::cout << "Input duck, dragon or quit" << std::endl;
        std::cin >> input;
        if (input == "duck")
        {
            choice = 0;
        }
        else if (input == "dragon")
        {
            choice = 1;
        }
        else if (input == "quit")
        {
            choice = 2;
        }
        else
        {
            choice = -1;
        }

        switch (choice)
        {
        case 0:
            std::cout << "    _\n"
                         ".__(.)< (MEOW)\n"
                         " \\___)\n"
                      << std::endl;
            break;
        case 1:
            std::cout << "   \\\n"
                         "    \\                    ^    /^\n"
                         "     \\                  / \\  // \\\n"
                         "      \\   |\\___/|      /   \\//  .\\\n"
                         "       \\  /V  V  \\__  /    //  | \\ \\           *----*\n"
                         "          /     /  \\/_/    //   |  \\  \\          \\   |\n"
                         "          @___@`    \\/_   //    |   \\   \\         \\/\\ \\\n"
                         "         0/0/|       \\/_ //     |    \\    \\         \\  \\\n"
                         "     0/0/0/0/|        \\///      |     \\     \\       |  |\n"
                         "   0/0/0/0/0/_|_ /   (  //       |      \\     _\\     |  /\n"
                         "0/0/0/0/0/0/`/,_ _ _/  ) ; -.    |    _ _\\.-~       /   /\n"
                         "            ,-}        _      *-.|.-~-.           .~    ~\n"
                         "             `/\\      /                 ~-. _ .-~      /\n"
                         "                 *.   }            {                   /\n"
                         "                .----~-.\\        \\-`                 .~\n"
                         "                ///.----..<        \\             _ -~\n"
                         "                   ///-._ _ _ _ _ _ _{^ - - - - ~\""
                      << std::endl;
            break;
        case 2:
            quit = true;
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }

        if (quit)
        {
            break;
        }
        
    }

    return 0;
}