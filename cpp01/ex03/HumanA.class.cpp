#include "HumanA.class.hpp"
#include "Weapon.class.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon) {}

HumanA::std::string	getName(void) const {
	return (_name);
}

HumanA::void	attack() const {
	std::cout << getName() << " attacks with their " _weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << getName() " was murdered..." << std::endl;
}
