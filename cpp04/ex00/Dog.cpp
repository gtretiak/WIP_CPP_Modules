#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog() : Animal("Dog") {
	//this->type_ = "Dog";
	std::cout << "Dog was born." << std::endl;
}

Dog::Dog(const Dog &Another) : Animal(Another) {
	std::cout << "Dog cloned." << std::endl;
}

Dog	&Dog::operator=(const Dog &Another) {
	if (this != &Another)
		Animal::operator=(Another);
	std::cout << "Dog was reborn." << std::endl;
	return (*this);
}

std::string	Dog::getType(void) const {
	return (this->type_);
}

void		Dog::makeSound(void) const {
	std::cout << "Dog says \"woof\"." << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog died." << std::endl;
}
