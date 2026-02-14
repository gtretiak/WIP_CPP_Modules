#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Derived class " << this->name_ << " constructed.";
	this->health_ = 100;
	this->energy_ = 50;
	this->damage_ = 20;
        std::cout << " HP:" << this->health_ << ", EP:" << this->energy_ << ", DP:" << this->damage_ << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &Another) : ClapTrap(Another) {
	std::cout << "Derived class copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &Another) {
	std::cout << "Derived class copy assignment operator called" << std::endl;
	if (this != &Another)
		ClapTrap::operator=(Another); // modifying *this
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	ClapTrap::attack(target);
	std::cout << "Double attack bonus \"Merciless\"" << std::endl;
	ClapTrap::attack(target);
}

void	ScavTrap::guardGate(void) {
	std::cout << this->name_ << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Derived class destructed" << std::endl;
}
