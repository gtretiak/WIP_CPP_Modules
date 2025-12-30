#include "ClapTrap.class.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string	name) : name_(name) {
	std::cout << "Constructor" << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << this->name_ << " attacks " << target.name_ << ", causing " << this->damage_ << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name_ << " take " << amount << " points of damage." << std::endl;
	this->health_ -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->name_ << " got repaired by " << amount << " points." << std::endl;
	this->health_ += amount;
}
// int		health_;
// int		energy_;
// int		damage_;

ClapTrap::~ClapTrap() {
	std::cout << "desctructor" << std::endl;
}

#endif
