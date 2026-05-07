#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int	main(void) {
	std::srand(std::time(NULL));
	try {
		std::cout << "Bureaucrats hiring" << std::endl;
		Bureaucrat	a("Alice", 44);
		Bureaucrat	b("Bob", 3);
		Bureaucrat	c("Carten", 130);
		std::cout << "\nInterns being hired and working" << std::endl;
		Intern	first;
		AForm	*Shrub = first.makeForm("Shrubbery", "garden");
		Intern	second;
		AForm	*Robot = second.makeForm("robotomy", "cop");
		Intern	third;
		AForm	*Presi = third.makeForm("Presidential Pardon", "Bony");
		std::cout << "\nWorking with forms" << std::endl;
		b.signForm(*Presi);
		b.executeForm(*Presi);
		a.signForm(*Robot);
		a.executeForm(*Robot);
		c.signForm(*Shrub);
		c.executeForm(*Shrub);
		std::cout << "\nDeleting forms" << std::endl;
		delete Shrub;
		delete Robot;
		delete Presi;
		std::cout << "\nStack cleaning" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
