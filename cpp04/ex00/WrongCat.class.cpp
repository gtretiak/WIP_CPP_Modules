#include "WrongCat.class.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat() {
	std::cout << "Constructor" << std::endl;
}

std::string	WrongCat::getType(void) {
	return (this->type_);
}

void		WrongCat::makeSound(void) {
	std::cout << "Sound" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor" << std::endl;
}
