#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name) {
	this->health_ = FragTrap::health_;
	this->energy_ = ScavTrap::energy_;
	this->damage_ = FragTrap::damage_;
	std::cout << "The most derived \"Diamond\" class, named " << this->name_ << " evolved from ScavTrap and FragTrap, as well as one common base class (" << ClapTrap::name_;
        std::cout << "). HP:" << this->health_ << ", EP:" << this->energy_ << ", DP:" << this->damage_ << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &Another) : ClapTrap(Another), ScavTrap(Another), FragTrap(Another), name_(Another.name_) {
        std::cout << "The most derived \"Diamond\" class's copy constructor called. New name is " << this->name_ << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &Another) {
        std::cout << "The most derived \"Diamond\" class's copy assignment operator called" << std::endl;
	if (this != &Another)
	{
		ClapTrap::operator=(Another);
		this->name_ = Another.name_;
	}
	std::cout << "New name is " << this->name_ << std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target) {
	std::cout << this->name_ << " inherited attack skills from FragTrap" << std::endl;
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My name is " << this->name_ << ", my the most base class's name is " << ClapTrap::name_ << std::endl;
}

DiamondTrap::~DiamondTrap() {
        std::cout << "The most derived \"Diamond\" class destructed" << std::endl;
}
