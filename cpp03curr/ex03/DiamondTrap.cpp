#include "DiamondTrap.hpp"
#include <string>

DiamondTrap::DiamondTrap() {
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My name is " << this->name_ << ", but my grandpa's name is " << std::endl;
}
