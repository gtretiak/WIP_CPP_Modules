#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), target_(target) {
	std::cout << "Presidential form " << AForm::getName() << " printed. Grade to sign: " << AForm::getGradeToSign() << ". Grade to execute: " << AForm::getGradeToExec() << ". Target: " << this->target_ << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Another) : AForm(Another), target_(Another.target_) {
	std::cout << "Presidential form " << AForm::getName() << " copied and filled exactly like an example. Grade to sign: " << AForm::getGradeToSign() << ". Grade to execute: " << AForm::getGradeToExec() << ". Target: " << this->target_ << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &Another) {
	if (this != &Another)
	{
		AForm::operator=(Another);
		this->target_ = Another.target_;
		std::cout << "Presidential form " << AForm::getName() << " copy-assigned from " << Another.getName() << ", but status has been changed only (the rest are const). New status: " << AForm::getStatus() << std::endl;
	}
	return (*this);
}

void	PresidentialPardonForm::execute2() const {
	std::cout << "Execution: " << this->target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential form " << AForm::getName() << ". Grade to sign: " << AForm::getGradeToSign() << ", to execute: " << AForm::getGradeToExec() << ", signed: (" << std::boolalpha << AForm::getStatus() << ") - was shredered" << std::endl;
}
