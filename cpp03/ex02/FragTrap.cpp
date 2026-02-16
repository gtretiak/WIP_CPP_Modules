#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->health_ = 100;
	this->energy_ = 100;
	this->damage_ = 30;
	std::cout << "Derived \"Frag\" class " << this->name_ << " evolved from base model.";
        std::cout << " HP:" << this->health_ << ", EP:" << this->energy_ << ", DP:" << this->damage_ << std::endl;
}

FragTrap::FragTrap(const FragTrap &Another) : ClapTrap(Another) {
	std::cout << "Derived \"Frag\" class's copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &Another) {
	std::cout << "Derived \"Frag\" class's copy assignment operator called" << std::endl;
	if (this != &Another)
		ClapTrap::operator=(Another); // modifying *this
	return (*this);
}

void	FragTrap::attack(const std::string &target) {
	std::cout << "FragTrap has attack bonus \"Assassin\" (damage double increased)" << std::endl;
	this->damage_ *= 2;
	ClapTrap::attack(target);
	this->damage_ /= 2;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "Give me a high-five!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Derived \"Frag\" class destructed" << std::endl;
}
