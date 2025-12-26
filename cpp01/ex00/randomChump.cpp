#include <iostream>
#include "Zombie.class.hpp"
#define YE "\033[33m"
#define CYA "\033[36m"
#define RES "\033[0m"

void	randomChump(std::string name) {
	Zombie	tempZombie(name);
	tempZombie.announce();
	std::cout << CYA"The zombie " RES << tempZombie.getName() << CYA" fell... " <<
		"Apparently, it was too weak to walk and fight... "
		YE"Oh noooo!" RES << std::endl;
}
