#include "Cure.hpp"
#include <iostream>
#include <string>

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure built" << std::endl;
}

Cure::Cure(const Cure &Another) : AMateria(Another) {
	std::cout << "Cure copy built" << std::endl;
}

Cure	&Cure::operator=(const Cure &Another) {
	if (this != &Another)
		AMateria::operator=(Another);
	std::cout << "Cure copy built" << std::endl;
	return (*this);
}

AMateria	&Cure::clone() const {
	return (new Cure());
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destroyed" << std::endl;
}
