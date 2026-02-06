#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

AMateria::AMateria() : type_("Raw") {
	std::cout << "AMateria built" << std::endl;
}

AMateria::AMateria(std::string const &type) : type_(type) {
	std::cout << "AMateria type \"" << type << "\" built" << std::endl;
}

AMateria::AMateria(const AMateria &Another) : type_(Another.type_) {
	std::cout << "AMateria copy built" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &Another) {
	if (this != &Another)
		this->type_ = Another.type_;//works if not const only
	std::cout << "AMateria copy built" << std::endl;
	return (*this);
}

std::string const	&AMateria::getType() const {
	return (this->type_);
}

void	AMateria::use(ICharacter &target) {
	std::cout << "Materia not set (can't use)" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria built" << std::endl;
}
