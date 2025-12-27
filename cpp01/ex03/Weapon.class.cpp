#include "Weapon.class.hpp"
#include <iostream>
#include <string>

Weapon::Weapon(std::string type) : _type(type) {}

std::string	&Weapon::getType(void) {
	return (_type);
}

void	Weapon::setType(std::string const type) {
	_type = type;
}

Weapon::~Weapon() {
	std::cout << "Human has dropped the " << getType() << std::endl;
}
