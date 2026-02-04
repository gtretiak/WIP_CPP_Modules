#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat() : Animal("Cat") {
	//this->type_ = "Cat";
	std::cout << "Cat was born." << std::endl;
}

Cat::Cat(const Cat &Another) : Animal(Another) {
	std::cout << "Cat cloned." << std::endl;
}

Cat	&Cat::operator=(const Cat &Another) {
	if (this != &Another)
		Animal::operator=(Another);
	std::cout << "Cat was reborn." << std::endl;
	return (*this);
}

std::string	Cat::getType(void) const {
	return (this->type_);
}

void		Cat::makeSound(void) const {
	std::cout << "Cat says \"meow\"." << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat died." << std::endl;
}
