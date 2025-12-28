#include "Contact.class.hpp"
#include <string>
/*
Contact::Contact(void) {
	std::cout << "\033[36mContact constructor is called.\033[0m" << std::endl;
}*/

std::string	Contact::getFirst(void) const {
	return firstName_;
}

std::string	Contact::getLast(void) const {
	return lastName_;
}

std::string	Contact::getNick(void) const {
	return nickName_;
}

std::string	Contact::getPhone(void) const {
	return phoneNumber_;
}

std::string	Contact::getSecret(void) const {
	return darkestSecret_;
}

void	Contact::setFirst(const std::string &var) {
	firstName_ = var;
}

void	Contact::setLast(const std::string &var) {
	lastName_ = var;
}

void	Contact::setNick(const std::string &var) {
	nickName_ = var;
}

void	Contact::setPhone(const std::string &var) {
	phoneNumber_ = var;
}

void	Contact::setSecret(const std::string &var) {
	darkestSecret_ = var;
}
/*
Contact::~Contact(void) {
	std::cout << "\033[36mContact destructor is called.\033[0m" << std::endl;
}*/
