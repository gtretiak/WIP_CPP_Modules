#include "AAnimal.hpp"
#include <string>
#include <iostream>

AAnimal::AAnimal() : type_("AAnimal") {
	std::cout << "AAnimal abstract construction" << std::endl;
}

AAnimal::AAnimal(std::string type) : type_(type) {
	std::cout << "AAnimal abstract construction, defined type: " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal &Another) : type_(Another.type_) {
	std::cout << "AAnimal abstract copying" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &Another) {
	std::cout << "AAnimal abstract assignment" << std::endl;
	if (this != &Another)
		this->type_ = Another.type_;
	return (*this);
}

std::string	AAnimal::getType(void) const {
	return (this->type_);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal abstract destruction" << std::endl;
}
