#include "WrongAnimal.class.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "Constructor" << std::endl;
}

std::string	WrongAnimal::getType(void) {
	return (this->type_);
}

void		WrongAnimal::makeSound(void) {
	std::cout << "Sound" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor" << std::endl;
}
