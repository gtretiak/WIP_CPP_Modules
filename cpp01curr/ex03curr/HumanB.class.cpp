#include "HumanB.class.hpp"
#include "Weapon.class.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : name_(name) {
	this->weapon_ = setType("bare hands");
}

void	HumanB::setWeapon(Weapon weapon) {
	this->weapon_ = weapon.getType();
}

std::string	HumanB::getName(void) const {
	return (this->name_);
}

void	HumanB::attack() const {
	std::cout << getName() << " attacks with their " << this->weapon_.getType() << std::endl;
}

HumanB::~HumanB() {
	std::cout << getName() << " was murdered..." << std::endl;
}
