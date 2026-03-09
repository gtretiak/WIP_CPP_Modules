#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

int	main(void) {
	try {
		//Form	test1("test1", 200, 10);
		//Form	test2("test2", 0, 110);
		Bureaucrat	financas("Alice", 100);
		Bureaucrat	aima("Joana", 60);
		Bureaucrat	bank("Olga", 140);
		Form	blank;
		Form	mortgage("Mortgage", 145, 135);
		std::cout << mortgage << std::endl;
		Form	irs1("IRS1", 120, 110);
		std::cout << irs1 << std::endl;
		financas.signForm(irs1);
		std::cout << irs1 << std::endl;
		Form	irs2(irs1);
		std::cout << irs2 << std::endl;
		Form	modulo1("Modulo-1", 70, 60);
		bank.signForm(mortgage);
		std::cout << mortgage << std::endl;
		aima.signForm(modulo1);
		std::cout << modulo1 << std::endl;
		bank.signForm(irs2);
		modulo1 = blank;
		std::cout << modulo1 << std::endl;
		bank.signForm(modulo1);
		aima.signForm(modulo1);
		std::cout << modulo1 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
