#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->health_ = 100;
	this->energy_ = 50;
	this->damage_ = 20;
	std::cout << "Derived class \"Scav\" constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &Another) : ClapTrap(Another) {
	std::cout << "Derived class \"Scav\" copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &Another) {
	std::cout << "Derived class \"Scav\" copy assignment operator called" << std::endl;
	if (this != &Another)
		ClapTrap::operator=(Another); // modifying *this
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	ClapTrap::attack(target);
	std::cout << "ScavTrap has attack bonus \"Merciless\"" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Derived class \"Scav\" destructed" << std::endl;
}
