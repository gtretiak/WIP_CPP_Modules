#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->health_ = 100;
	this->energy_ = 100;
	this->damage_ = 30;
	std::cout << "Derived class \"Frag\" constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &Another) : ClapTrap(Another) {
	std::cout << "Derived class \"Frag\" copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &Another) {
	std::cout << "Derived class \"Frag\" copy assignment operator called" << std::endl;
	if (this != &Another)
		ClapTrap::operator=(Another); // modifying *this
	return (*this);
}

void	FragTrap::attack(const std::string &target) {
	ClapTrap::attack(target);
	std::cout << "FragTrap has attack bonus \"Merciless\"" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "Give me a high-five!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Derived class \"Frag\" destructed" << std::endl;
}
