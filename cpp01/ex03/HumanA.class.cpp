#include "HumanA.class.hpp"
#include "Weapon.class.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon weapon) : name_(name), weapon_(weapon) {}

std::string	HumanA::getName(void) const {
	return (name_);
}

void	HumanA::attack() const {
	std::cout << getName() << " attacks with their " << weapon_.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << getName() << " was murdered..." << std::endl;
}
