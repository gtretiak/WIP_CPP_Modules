#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "Wrong animal was born." << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (this->type_);
}

void		WrongAnimal::makeSound(void) const {
	std::cout << "Wrong animal makes weird sound." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong animal died." << std::endl;
}
