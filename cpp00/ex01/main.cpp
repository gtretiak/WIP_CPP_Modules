#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <string>
#include <iostream>
#define PROMPT "\033[32mEnter one of these commands: ADD, SEARCH, EXIT.\n\033[0m"

int	main(void)
{
	std::string	input;
	int		ret;
	PhoneBook	PB;

	while (1)
	{
		std::cout << PROMPT;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\033[31mCtrl+D has pressed (EoF). Exit with code 1.\033[0m" << std::endl;
			return (1);
		}
		else if (input == "ADD")
		{
			ret = PB.addContact();
			if (ret == -1)
				return (1);
			else if (ret == 1)
				std::cout << "\033[31mContact can’t have empty fields. Not saved. " <<
					"Back to the main menu...\033[0m" << std::endl;
			else
				std::cout << "\033[32mBack to the main menu.\033[0m" << std::endl;
		}
		else if (input == "SEARCH")
		{
			ret = PB.searchContact();
			if (ret == -1)
				return (1);
			else if (ret == 1)
				std::cout << "\033[31mThe index of the entry to display is out of range (insert digits only from 1 to 8).\n" <<
					"Back to the main menu...\033[0m" << std::endl;
		}
		else if (input == "EXIT")
			break ;
		else
			continue ;
	}
	return (0);
}
