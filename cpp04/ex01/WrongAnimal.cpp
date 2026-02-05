#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
	std::cout << "WrongAnimal was born" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type_(name) {
	std::cout << "WrongAnimal with defined type " << name << " was born" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &Another) : type_(Another.type_) {
	std::cout << "WrongAnimal was cloned" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &Another) {
	std::cout << "WrongAnimal was reborn" << std::endl;
	if (this != &Another)
		this->type_ = Another.type_;
	return (*this);
}

std::string	WrongAnimal::getType(void) const {
	return (this->type_);
}

void		WrongAnimal::makeSound(void) const {
	std::cout << "*** Weird sound ***" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal died" << std::endl;
}
