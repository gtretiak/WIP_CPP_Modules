#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#define PROMPT "Enter one of these commands: ADD, SEARCH, EXIT.\n"

int	main(void)
{
	std::string	input;
	PhoneBook	PhoneBook;

	while (1)
	{
		std::cout << PROMPT;
		std::cin >> input;
		if (std::cin.eof())
			exit(1);
		else if (input == "ADD")
		{
			PhoneBook.addContact();
		}
		else if (input == "SEARCH")
		{
			PhoneBook.searchContact();
			std::cout << std::setw(10) << "test" << std::endl;
		}
		else if (input == "EXIT")
			PhoneBook.terminateProgram();
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
