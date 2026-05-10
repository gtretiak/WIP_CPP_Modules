#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
	}
	ScalarConverter.convert(argv[1]);
}
