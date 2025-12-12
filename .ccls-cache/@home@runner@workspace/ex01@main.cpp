#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook::PhoneBook{};

	while (1)
	{
		std::cout << INITIAL_PROMPT;
		std::cin >> input;
		if (input == "ADD")
		{
			std::cout << "do add" << input.size() << std::endl;
		}
		else if (input == "SEARCH")
		{
			std::cout << std::right << "do search"
			<< std::setw(10) << "test" << std::endl;
		}
		else if (input == "EXIT")
			~PhoneBook; // destruct?
	}
	return (0);
}
