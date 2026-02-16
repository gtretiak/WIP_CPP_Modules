#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->health_ = 100;
	this->energy_ = 50;
	this->damage_ = 20;
	std::cout << "Derived \"Scav\" class " << this->name_ << " evolved from base model.";
        std::cout << " HP:" << this->health_ << ", EP:" << this->energy_ << ", DP:" << this->damage_ << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &Another) : ClapTrap(Another) {
	std::cout << "Derived \"Scav\" class's copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &Another) {
	std::cout << "Derived \"Scav\" class's copy assignment operator called" << std::endl;
	if (this != &Another)
		ClapTrap::operator=(Another); // modifying *this
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	ClapTrap::attack(target);
	std::cout << "ScavTrap has attack bonus \"Merciless\" (double attack)" << std::endl;
	ClapTrap::attack(target);
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Derived \"Scav\" class destructed" << std::endl;
}
