#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

#define PROMPT "Enter one of these commands: ADD, SEARCH, EXIT.\n"

int     main(void)
{
        std::string     input;
        PhoneBook       PB;

        while (1)
        {
                std::cout << PROMPT;
                getline(std::cin, input);
                if (std::cin.eof())
                {
                        std::cout << "Ctrl+D has pressed (EoF). Exit with code 1." << std::endl;
                        exit(1);
                }
                else if (input == "ADD")
                {
                        if (PB.addContact())
                                std::cout << "Contact can’t have empty fields. Not saved. " <<
                                        "Back to the main menu..." << std::endl;
                        else
                                std::cout << "Back to the main menu." << std::endl;
                }
                else if (input == "SEARCH")
                {
                        if (PB.searchContact())
                                std::cout << "The index of the entry to display is out of range. " <<
                                        "Back to the main menu..." << std::endl;
                }
                else if (input == "EXIT")
                        PB.terminateProgram();
                else
                        continue ;
        }
        return (0);
}
