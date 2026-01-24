#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string	name) : name_(name) {
	this->health_ = 10;
	this->energy_ = 10;
	this->damage_ = 0;
	std::cout << "Robot named " << this->name_ << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &Another) {
	this->name_ = Another.name_;
	this->health_ = Another.health_;
	this->energy_ = Another.energy_;
	this->damage_ = Another.damage_;
	std::cout << "Full copy of " << Another.name_ << " constructed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &Another) {
	std::cout << "Robot " << this->name_ << " reassigned. ";
	this->name_ = Another.name_;
	this->health_ = Another.health_;
	this->energy_ = Another.energy_;
	this->damage_ = Another.damage_;
	std::cout << "New name is " << this->name_ << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	std::cout << "Robot " << this->name_ << " attacks " << target.name_ << ", causing " << this->damage_ << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "Robot " << this->name_ << " take " << amount << " points of damage." << std::endl;
	this->health_ -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "Robot " << this->name_ << " got repaired by " << amount << " points." << std::endl;
	this->health_ += amount;
}

ClapTrap::~ClapTrap() {
	std::cout << "Robot named " << this->name_ << " desctructed" << std::endl;
}
