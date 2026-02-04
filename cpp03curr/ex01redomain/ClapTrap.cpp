#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name_(name), health_(10), energy_(10), damage_(0) {
	std::cout << "Robot named " << this->name_ << " constructed.";
	std::cout << " HP:" << health_ << ", EP:" << energy_ << ", DP:" << damage_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &Another) : name_(Another.name_), health_(Another.health_), energy_(Another.energy_), damage_(Another.damage_) {
	std::cout << "Full copy of " << Another.name_ << " constructed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &Another) {
	std::cout << "Robot " << this->name_ << " is re-sleevng into ";
	if (this != &Another)
	{
		this->name_ = Another.name_;
		this->health_ = Another.health_;
		this->energy_ = Another.energy_;
		this->damage_ = Another.damage_;
	}
	std::cout << this->name_ << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	std::cout << "Robot " << this->name_;
	if (!this->energy_)
	{
		std::cout << " has no energy to attack (passed)." << std::endl;
		return ;
	}
	else if (!this->health_)
	{
		std::cout << " has no HP to continue the fight." << std::endl;
		return ;
	}
	std::cout << " draws aggro (damage increased) and attacks " << target << ", causing " << this->damage_ + 10 << " points of damage (mitigated though).";
	this->energy_--;
	std::cout << " EP:" << this->energy_ << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "Robot " << this->name_ << " takes " << amount << " points of damage.";
	this->health_ -= amount;
	std::cout << " HP:" << this->health_ << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "Robot " << this->name_;
      	if (!this->energy_ || !this->health_)
	{
		std::cout << " tries to repair itself, but fails." << std::endl;
		return ;
	}
	std::cout << " repairs itself by " << amount << " points."; 
	this->health_ += amount;
	this->energy_--;
	std::cout << " HP:" << this->health_;
	std::cout << ". EP:" << this->energy_ << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Robot named " << this->name_ << " destroyed" << std::endl;
}
