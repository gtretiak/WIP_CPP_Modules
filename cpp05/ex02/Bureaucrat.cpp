#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name_("unnamed"), grade_(150) {
	std::cout << "Bureaucrat " << this->name_ << " with default grade " << this->grade_ << " hired" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		std::cout << "Bureaucrat " << this->name_ << " with grade " << this->grade_ << " was born" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &Another) : name_(Another.name_), grade_(Another.grade_) {
	std::cout << "Full copy of bureaucrat " << this->name_ << " with grade " << this->grade_ << " was created" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &Another) {
	if (this != &Another)
	{
		std::cout << "Bureaucrat " << this->name_ << " with grade " << this->grade_ << " was reassigned with new grade, but kept the old name. The new grade is ";
		this->grade_ = Another.grade_;
		std::cout << this->grade_ << std::endl;
	}
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade can't be higher than 1!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade can't be below 150!");
}

const std::string	&Bureaucrat::getName() const {
	return (this->name_);
}

int		Bureaucrat::getGrade() const {
	return (this->grade_);
}

void		Bureaucrat::incrementGrade() {
	if (this->grade_ <= 1)
		throw GradeTooHighException();
	this->grade_--;
}

void		Bureaucrat::decrementGrade() {
	if (this->grade_ >= 150)
		throw GradeTooLowException();
	this->grade_++;
}

void		Bureaucrat::signForm(AForm &obj) {
	try {
		obj.beSigned(*this);
		std::cout << "Bureaucrat " << this->name_ << " signed form-" << obj.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Bureaucrat " << this->name_ << " couldn't sign form-" << obj.getName() << ": " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << "Bureaucrat " << this->name_ << " executed form-" << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Bureaucrat " << this->name_ << " couldn't execute form-" << form.getName() << ": " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->name_ << " with grade " << this->grade_ << " fired" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (os);
}
