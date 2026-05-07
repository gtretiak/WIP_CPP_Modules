#include "Intern.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	std::cout << "Another Intern who will never be remembered stepped the office" << std::endl;	
}
Intern::Intern(const Intern &An) {
	(void)An;
	std::cout << "Exactly the same faceless Intern stepped the office (copy constructor)" << std::endl;
}
Intern	&Intern::operator=(const Intern &An) {
	if (this != &An)
	{
		(void)An;
		std::cout << "Exactly the same faceless Intern stepped the office (copy assignment)" << std::endl;
	}
	return (*this);
}
AForm	*Intern::makeForm(const std::string &form, const std::string &targ) {
	std::string	forms[3] = {
		"robotomy request; Robotomy request; Robotomy Request",
		"shrubbery creation; Shrubbery creation Shrubbery Creation",
		"presidential pardon; Presidential pardon; Presidential Pardon"};
	AForm	*(*functions[3])(const std::string &) =
	{
		&Intern::robotomy,
		&Intern::shrubbery,
		&Intern::presidential
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].find(form) != std::string::npos)
		{
			std::cout << "Intern creates " << form << std::endl;
			return functions[i](targ);
		}
	}
	throw Intern::FormNotExist();
}

const char	*Intern::FormNotExist::what() const throw() {
	return ("The requested form has never been seen");
}

AForm	*Intern::robotomy(const std::string &target) {
	return (new RobotomyRequestForm(target));
}
AForm	*Intern::shrubbery(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}
AForm	*Intern::presidential(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

Intern::~Intern() {
	std::cout << "Intern left the office, but nobody even noticed" << std::endl;
}
