#include "RobotomyRequestForm.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), target_(target) {
	std::cout << "Robotomy form " << AForm::getName() << " printed. Grade to sign: " << AForm::getGradeToSign() << ". Grade to execute: " << AForm::getGradeToExec() << ". Target: " << this->target_ << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Another) : AForm(Another), target_(Another.target_) {
	std::cout << "Robotomy form " << AForm::getName() << " copied and filled exactly like an example. Grade to sign: " << AForm::getGradeToSign() << ". Grade to execute: " << AForm::getGradeToExec() << ". Target: " << this->target_ << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &Another) {
	if (this != &Another)
	{
		AForm::operator=(Another);
		this->target_ = Another.target_;
		std::cout << "Robotomy form " << AForm::getName() << " copy-assigned from " << Another.getName() << ", but status has been changed only (the rest are const). New status: " << AForm::getStatus() << std::endl;
	}
	return (*this);
}

void	RobotomyRequestForm::execute2() const {
	std::cout << "Execution: * Vrrrrrrr * whiiiiirrr * clack-clack * whrrrrrrr * clank * bzzzzzzt * " << std::endl;
	if (std::rand() % 2)
		std::cout << this->target_ << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target_ << "'s robotomy failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy form " << AForm::getName() << ". Grade to sign: " << AForm::getGradeToSign() << ", to execute: " << AForm::getGradeToExec() << ", signed: (" << std::boolalpha << AForm::getStatus() << ") - was shredered" << std::endl;
}
