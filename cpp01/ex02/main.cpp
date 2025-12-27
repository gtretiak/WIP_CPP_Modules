#include <iostream>

int	main(void) {
	std::string	orig = "HI THIS IS BRAIN";
	std::string	*stringPTR = &orig;
	std::string	&stringREF = orig;
	std::cout << "The memory address of the string variable: " << &orig << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "The value of the string variable: " << orig << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}
