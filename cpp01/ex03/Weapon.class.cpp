#include "Weapon.class.hpp"
#include <iostream>
#include <string>

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::std::string const	&getType(void) {
	return (&_type);
}

Weapon::void	setType(std::string const type) {
	_type = type;
}

Weapon::~Weapon() {
	std::cout << "Human has dropped the " << getType() << std::endl;
}
