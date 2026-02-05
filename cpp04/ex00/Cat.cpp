#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat was born" << std::endl;
}

Cat::Cat(const Cat &Another) : Animal(Another) {
	std::cout << "Cat cloned" << std::endl;
	// Here we basically call a copy constructor for the base class,
	// passing an instance of 'Cat' converted to Animal.
	// It creates another Cat's instance, based on Animal class
	// then, if needed, we copy into new Cat unique members of old Cat
}

Cat	&Cat::operator=(const Cat &Another) {
	if (this != &Another)
		Animal::operator=(Another);
		// here might be logic for reassigning Cat class's members
	std::cout << "Cat was reborn" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Cat says \"meow\"" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat died" << std::endl;
}
