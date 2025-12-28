#include "Contact.class.hpp"
#include <string>

std::string	Contact::getFirst(void) const {
	return this->firstName_;
}

std::string	Contact::getLast(void) const {
	return this->lastName_;
}

std::string	Contact::getNick(void) const {
	return this->nickName_;
}

std::string	Contact::getPhone(void) const {
	return this->phoneNumber_;
}

std::string	Contact::getSecret(void) const {
	return this->darkestSecret_;
}

void	Contact::setFirst(const std::string &var) {
	this->firstName_ = var;
}

void	Contact::setLast(const std::string &var) {
	this->lastName_ = var;
}

void	Contact::setNick(const std::string &var) {
	this->nickName_ = var;
}

void	Contact::setPhone(const std::string &var) {
	this->phoneNumber_ = var;
}

void	Contact::setSecret(const std::string &var) {
	this->darkestSecret_ = var;
}
