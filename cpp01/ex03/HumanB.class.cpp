#include "HumanB.class.hpp"
#include "Weapon.class.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : _name(name) {
	_weapon = setType("bare hands");
}

HumanB::void	setWeapon(Weapon weapon) {
	_weapon = weapon.getType();
}

HumanB::std::string	getName(void) const {
	return (_name);
}

HumanB::void	attack() const {
	std::cout << getName() << " attacks with their " _weapon.getType() << std::endl;
}

HumanB::~HumanB() {
	std::cout << getName() " was murdered..." << std::endl;
}
