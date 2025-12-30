#include "Animal.class.hpp"
#include <string>
#include <iostream>

Animal::Animal() {
	std::cout << "Constructor" << std::endl;
}

std::string	Animal::getType(void) {
	return (this->type_);
}

void		Animal::makeSound(void) {
	std::cout << "sound" << std::endl;
}

Animal::~Animal() {
	std::cout << "Destructor" << std::endl;
}
