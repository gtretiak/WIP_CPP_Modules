#include "Zombie.class.hpp"
#include <string>
#include <iostream>
#define RED "\033[31m"
#define PURP "\033[35m"
#define CYA "\033[36m"
#define RES "\033[0m"

std::string	Zombie::getName(void) const {
	return (name_);
}

Zombie::Zombie(std::string name) : name_(name) {}

void	Zombie::announce(void) const {
	std::cout << getName() << ": " 
		PURP"BraiiiiiiinnnzzzZ..." RES << std::endl;
}

Zombie::~Zombie() {
	std::cout << CYA"The zombie " RES << getName() << CYA" has been "
		RED"killed..." RES << std::endl;
}
