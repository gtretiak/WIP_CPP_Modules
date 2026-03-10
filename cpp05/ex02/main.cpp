#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

int	main(void) {
	try {
		Bureaucrat	financas("Alice", 100);
		Bureaucrat	aima("Joana", 60);
		Bureaucrat	bank("Olga", 140);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
