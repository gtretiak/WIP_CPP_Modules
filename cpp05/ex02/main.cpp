#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void) {
	std::srand(std::time(NULL));
	try {
		Bureaucrat	a("Alice", 44);
		Bureaucrat	b("Bob", 3);
		Bureaucrat	c("Carten", 140);
		ShrubberyCreationForm	tree("garden");
		RobotomyRequestForm	robocop("cop");
		PresidentialPardonForm	pardon("Bony");
		b.signForm(pardon);
		b.executeForm(pardon);
		a.signForm(robocop);
		a.executeForm(robocop);
		c.signForm(tree);
		c.executeForm(tree);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
