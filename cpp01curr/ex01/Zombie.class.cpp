#include "Zombie.class.hpp"

#define RED "\033[31m"
#define PURP "\033[35m"
#define CYA "\033[36m"
#define RES "\033[0m"

#include <string>
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name, int num) : name_(name), num_(num) {}

std::string	Zombie::getName(void) const {
	return (this->name_);
}

void	Zombie::setZombie(std::string const name, int const num) {
	this->name_ = name;
	this->num_ = num;
}

int	Zombie::getNum(void) const {
	return (this->num_);
}

void	Zombie::announce(void) const {
	std::cout << getName() << " " << getNum() << ": " 
		PURP"BraiiiiiiinnnzzzZ..." RES << std::endl;
}

Zombie::~Zombie() {
	std::cout << CYA"The zombie " RES << getName() << getNum() << CYA" has been "
		RED"fell to the ground..." RES << std::endl;
}
