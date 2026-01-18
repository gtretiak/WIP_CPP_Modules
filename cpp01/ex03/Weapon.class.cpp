#include "Weapon.class.hpp"
#include <iostream>
#include <string>

Weapon::Weapon(std::string type) : type_(type) {
	std::cout << "The " << this->type_ << " has appeared out of nowhere." << std::endl;
}

const std::string	&Weapon::getType(void) {
	return (this->type_);
}

void	Weapon::setType(std::string const type) {
	std::cout << "The " << this->type_ << " has been replaced by the game master. Now it's the ";
	this->type_ = type;
	std::cout << this->type_ << "." << std::endl;
}

Weapon::~Weapon() {
	std::cout << "Someone has dropped the " << getType() << "." << std::endl;
}
