#include "Ice.hpp"
#include <iostream>
#include <string>

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice built" << std::endl;
}

Ice::Ice(const Ice &Another) : AMateria(Another) {
	std::cout << "Ice copy built" << std::endl;
}

Ice	&Ice::operator=(const Ice &Another) {
	if (this != &Another)
		AMateria::operator=(Another);
	std::cout << "Ice copy built" << std::endl;
	return (*this);
}

AMateria	&Ice::clone() const {
	return (new Ice());
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destroyed" << std::endl;
}
