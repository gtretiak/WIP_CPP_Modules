#include "Dog.class.hpp"
#include <string>
#include <iostream>

Dog::Dog() {
	std::cout << "Constructor" << std::endl;
}

std::string	Dog::getType(void) {
	return (this->type_);
}

void		Dog::makeSound(void) {
	std::cout << "Sound" << std::endl;
}

Dog::~Dog() {
	std::cout << "Destructor" << std::endl;
}
