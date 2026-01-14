#include "HumanA.class.hpp"
#include "Weapon.class.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon) {
	std::cout << this->name_ << " has stepped onto the arena, holding the " << this->weapon_.getType() << "." << std::endl;
}

/*std::string	HumanA::getName(void) const {
	return (this->name_);
}
*/
void	HumanA::attack() const {
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType() << "." << std::endl;
}

HumanA::~HumanA() {
	std::cout << this->name_ << " has left the arena..." << std::endl;
}
