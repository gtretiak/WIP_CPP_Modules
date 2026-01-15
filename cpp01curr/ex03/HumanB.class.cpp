#include "HumanB.class.hpp"
#include "Weapon.class.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {
	std::cout << this->name_ << " with bare hands has stepped onto the arena." << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon_ = &weapon;
	std::cout << this->name_ << " has been armed with the " << this->weapon_->getType() << "." << std::endl;
}

/*std::string	HumanB::getName(void) const {
	return (this->name_);
}
*/
void	HumanB::attack() const {
	std::cout << this->name_ << " attacks with ";
	if (!this->weapon_)
		std::cout << "bare hands." << std::endl;
	else
		std::cout << "their " << this->weapon_->getType() << "." << std::endl;
}

HumanB::~HumanB() {
	std::cout << this->name_ << " has left the arena..." << std::endl;
}
