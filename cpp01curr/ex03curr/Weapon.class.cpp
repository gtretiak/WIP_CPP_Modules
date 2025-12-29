#include "Weapon.class.hpp"
#include <iostream>
#include <string>

Weapon::Weapon(std::string type) : type_(type) {}

std::string	&Weapon::getType(void) {
	return (this->type_);
}

void	Weapon::setType(std::string const type) {
	this->type_ = type;
}

Weapon::~Weapon() {
	std::cout << "Human has dropped the " << getType() << std::endl;
}
