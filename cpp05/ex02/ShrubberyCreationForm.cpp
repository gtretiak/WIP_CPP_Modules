#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), target_(target) {
	std::cout << "Shrubbery form " << AForm::getName() << " printed. Grade to sign: " << AForm::getGradeToSign() << ". Grade to execute: " << AForm::getGradeToExec() << ". Target: " << this->target_ << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Another) : AForm(Another), target_(Another.target_) {
	std::cout << "Shrubbery form " << AForm::getName() << " copied and filled exactly like an example. Grade to sign: " << AForm::getGradeToSign() << ". Grade to execute: " << AForm::getGradeToExec() << ". Target: " << this->target_ << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Another) {
	if (this != &Another)
	{
		AForm::operator=(Another);
		this->target_ = Another.target_;
		std::cout << "Shrubbery form " << AForm::getName() << " copy-assigned from " << Another.getName() << ", but status has been changed only (the rest are const). New status: " << AForm::getStatus() << std::endl;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute2() const {
	std::cout << "Execution: file creating..." << std::endl;
	std::ofstream	outfile((this->target_ + "_shrubbery").c_str());
	if (!outfile)
		return ;
	outfile << "   /\\\n  /**\\\n /****\\\n/******\\\n  |||\n";
	std::cout << "File created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery form " << AForm::getName() << ". Grade to sign: " << AForm::getGradeToSign() << ", to execute: " << AForm::getGradeToExec() << ", signed: (" << std::boolalpha << AForm::getStatus() << ") - was shredered" << std::endl;
}
