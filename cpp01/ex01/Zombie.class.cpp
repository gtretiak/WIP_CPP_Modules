#include "Zombie.class.hpp"

#define RED "\033[31m"
#define PURP "\033[35m"
#define CYA "\033[36m"
#define RES "\033[0m"

Zombie::Zombie() {}

Zombie::Zombie(std::string name, int num) : _name(name), _num(num) {}

std::string	Zombie::getName(void) const {
	return (_name);
}

void	Zombie::setZombie(std::string const name, int const num) {
	_name = name;
	_num = num;
}

int	Zombie::getNum(void) const {
	return (_num);
}

void	Zombie::announce(void) const {
	std::cout << getName() << " " << getNum() << ": " 
		PURP"BraiiiiiiinnnzzzZ..." RES << std::endl;
}

Zombie::~Zombie() {
	std::cout << CYA"The zombie " RES << getName() << getNum() << CYA" has been "
		RED"killed..." RES << std::endl;
}
