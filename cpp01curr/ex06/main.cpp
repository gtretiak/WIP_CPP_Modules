#include <iostream>
#include "Harl.class.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments. Give it one level." << std::endl;
		return (1);
	}
	std::string	filter(argv[1]);
	Harl	Instance(filter);
	Instance.complain("DEBUG");
	Instance.complain("INFO");
	Instance.complain("WARNING");
	Instance.complain("ERROR");
	return 0;
}
