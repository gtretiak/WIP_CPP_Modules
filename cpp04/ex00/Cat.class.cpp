#include "Cat.class.hpp"
#include <string>
#include <iostream>

Cat::Cat() {
	std::cout << "Constructor" << std::endl;
}

std::string	Cat::getType(void) {
	return (this->type_);
}

void		Cat::makeSound(void) {
	std::cout << "Sound" << std::endl;
}

Cat::~Cat() {
	std::cout << "Destructor" << std::endl
}
