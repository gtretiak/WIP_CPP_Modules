#include "AForm.hpp"
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm() : name_("blank"), isSigned_(false), signGrade_(150), execGrade_(150) {
	std::cout << "AForm-" << this->name_ << " printed. Grade to sign: " << this->signGrade_ << ". Grade to execute: " << this->execGrade_ << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : name_(name), isSigned_(false), signGrade_(signGrade), execGrade_(execGrade) {
	if (signGrade_ < 1 || execGrade_ < 1)
		throw GradeTooHighException();
	else if (signGrade_ > 150 || execGrade > 150)
		throw GradeTooLowException();
	else
		std::cout << "AForm-" << this->name_ << " printed. Grade to sign: " << this->signGrade_ << ". Grade to execute: " << this->execGrade_ << std::endl;
}

AForm::AForm(const AForm &Another) : name_(Another.name_), isSigned_(Another.isSigned_), signGrade_(Another.signGrade_), execGrade_(Another.execGrade_) {
	std::cout << "AForm-" << this->name_ << " copied and filled exactly like an example. Grade to sign: " << this->signGrade_ << ". Grade to execute: " << this->execGrade_ << std::endl;
}

AForm	&AForm::operator=(const AForm &Another) {
	if (this != &Another)
	{
		this->isSigned_ = Another.isSigned_;
		std::cout << "AForm-" << this->name_ << " copy-assigned from " << Another.getName() << ", but status has been changed only (the rest are const). New status: " << this->isSigned_ << std::endl;
	}
	return (*this);
}

std::string	AForm::getName() const {
	return (this->name_);
}

bool	AForm::getStatus() const {
	return (this->isSigned_);
}

int	AForm::getGradeToSign() const {
	return (this->signGrade_);
}

int	AForm::getGradeToExec() const {
	return (this->execGrade_);
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const char	*AForm::SignedException::what() const throw() {
	return ("AForm hasn't been signed yet (No bureaucrat would ever execute an unsigned form!");
}

void	AForm::beSigned(Bureaucrat &obj) {
	if (obj.getGrade() <= this->signGrade_)
		this->isSigned_ = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (this->isSigned_ == false)
		throw SignedException();
	else if (executor.getGrade() > this->execGrade_)
		throw GradeTooLowException();
	execute2();
}

AForm::~AForm() {
	std::cout << "AForm-" << this->name_ << ". Grade to sign: " << this->signGrade_ << ", to execute: " << this->execGrade_ << ", signed: (" << std::boolalpha << this->isSigned_ << ") - was shredered" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, AForm &obj) {
	os << "AForm-" << obj.getName() << ". Grade to sign: " << obj.getGradeToSign() << ", to execute: " << obj.getGradeToExec() << ", signed: " << std::boolalpha << obj.getStatus() << std::endl;
	return (os);
}
