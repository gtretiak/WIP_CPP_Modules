#include "Contact.class.hpp"

Contact::Contact(void) {
	std::cout << "Constructor is called." << std::endl;
}

std::string	Contact::getFirst(void) {
	return _firstName;
}

std::string	Contact::getLast(void) {
	return _lastName;
}

std::string	Contact::getNick(void) {
	return _nickName;
}

std::string	Contact::getPhone(void) {
	return _phoneNumber;
}

std::string	Contact::getSecret(void) {
	return _darkestSecret;
}

void	Contact::setFirst(std::string var) {
	_firstName = var;
}

void	Contact::setLast(std::string var) {
	_lastName = var;
}

void	Contact::setNick(std::string var) {
	_nickName = var;
}

void	Contact::setPhone(std::string var) {
	_phoneNumber = var;
}

void	Contact::setSecret(std::string var) {
	_darkestSecret = var;
}

Contact::~Contact(void) {
	std::cout << "Destructor is called." << std::endl;
}
