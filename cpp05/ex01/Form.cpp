#include "Form.hpp"
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form() : name_("blank"), isSigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "Form-" << this->name_ << " printed. Grade to sign: " << this->signGrade_ << ". Grade to execute: " << this->execGrade_ << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : name_(name), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	if (signGrade_ < 1 || execGrade_ < 1)
		throw GradeTooHighException();
	else if (signGrade_ > 150 || execGrade > 150)
		throw GradeTooLowException();
	else
		std::cout << "Form-" << this->name_ << " printed. Grade to sign: " << this->signGrade_ << ". Grade to execute: " << this->execGrade_ << std::endl;
}

Form::Form(const Form &Another) : name_(Another.name_), isSigned_(Another.isSigned_), signGrade_(Another.signGrade_), execGrade_(Another.execGrade_) {
	std::cout << "Form-" << this->name_ << " copied and filled exactly like an example. Grade to sign: " << this->signGrade_ << ". Grade to execute: " << this->execGrade_ << std::endl;
}

Form	&Form::operator=(const Form &Another) {
	if (this != &Another)
	{
		this->isSigned_ = Another.isSigned_;
		std::cout << "Form-" << this->name_ << " copy-assigned from " << Another.getName() << ", but status has been changed only (the rest are const). New status: " << this->isSigned_ << std::endl;
	}
	return (*this);
}

std::string	Form::getName() const {
	return (this->name_);
}

bool	Form::getStatus() const {
	return (this->isSigned_);
}

int	Form::getGradeToSign() const {
	return (this->signGrade_);
}

int	Form::getGradeToExec() const {
	return (this->execGrade_);
}

const char	*Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

void	Form::beSigned(Bureaucrat &obj) {
	if (obj.getGrade() <= this->signGrade_)
		this->isSigned_ = true;
	else
		throw GradeTooLowException();
}

Form::~Form() {
	std::cout << "Form-" << this->name_ << ". Grade to sign: " << this->signGrade_ << ", to execute: " << this->execGrade_ << ", signed: " << std::boolalpha << this->isSigned_ << " was shredered" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Form &obj) {
	os << "Form-" << obj.getName() << ". Grade to sign: " << obj.getGradeToSign() << ", to execute: " << obj.getGradeToExec() << ", signed: " << std::boolalpha << obj.getStatus() << std::endl;
	return (os);
}
