#include "Contact.class.hpp"

Contact::Contact(void) {
	std::cout << "\033[36mContact constructor is called.\033[0m" << std::endl;
}

std::string	Contact::getFirst(void) const {
	return _firstName;
}

std::string	Contact::getLast(void) const {
	return _lastName;
}

std::string	Contact::getNick(void) const {
	return _nickName;
}

std::string	Contact::getPhone(void) const {
	return _phoneNumber;
}

std::string	Contact::getSecret(void) const {
	return _darkestSecret;
}

void	Contact::setFirst(const std::string &var) {
	_firstName = var;
}

void	Contact::setLast(const std::string &var) {
	_lastName = var;
}

void	Contact::setNick(const std::string &var) {
	_nickName = var;
}

void	Contact::setPhone(const std::string &var) {
	_phoneNumber = var;
}

void	Contact::setSecret(const std::string &var) {
	_darkestSecret = var;
}

Contact::~Contact(void) {
	std::cout << "\033[36mContact destructor is called.\033[0m" << std::endl;
}
