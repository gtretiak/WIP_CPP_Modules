#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

#define PROMPT "Enter one of these commands: ADD, SEARCH, EXIT.\n"

int	main(void)
{
	std::string	input;
	PhoneBook	PB;

	while (1)
	{
		std::cout << PROMPT;
		getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		else if (input == "ADD")
		{
			PB.addContact(); // add check for invalid insertion?
		}
		else if (input == "SEARCH")
		{
			PB.searchContact();
		}
		else if (input == "EXIT")
			PB.terminateProgram();
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
