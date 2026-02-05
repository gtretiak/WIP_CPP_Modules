#include "AWrongAnimal.hpp"
#include <string>
#include <iostream>

AWrongAnimal::AWrongAnimal() : type_("AWrongAnimal") {
	std::cout << "AWrongAnimal fake-abstract construction" << std::endl;
}

AWrongAnimal::AWrongAnimal(std::string name) : type_(name) {
	std::cout << "AWrongAnimal fake-abstract creation, defined type: " << name << std::endl;
}

AWrongAnimal::AWrongAnimal(const AWrongAnimal &Another) : type_(Another.type_) {
	std::cout << "AWrongAnimal fake-abstract copying" << std::endl;
}

AWrongAnimal	&AWrongAnimal::operator=(const AWrongAnimal &Another) {
	std::cout << "AWrongAnimal fake-abstract assignment" << std::endl;
	if (this != &Another)
		this->type_ = Another.type_;
	return (*this);
}

std::string	AWrongAnimal::getType(void) const {
	return (this->type_);
}

void		AWrongAnimal::makeSound(void) const {
	std::cout << "*** Weird sound ***" << std::endl;
}

void	AWrongAnimal::purevirtual(void) const {
	std::cout << "This function does nothing" << std::endl;
}

AWrongAnimal::~AWrongAnimal() {
	std::cout << "AWrongAnimal fake-abstract destruction" << std::endl;
}
