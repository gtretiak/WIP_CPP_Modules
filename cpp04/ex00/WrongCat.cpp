#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat() {
	std::cout << "Wrong cat was born." << std::endl;
}

std::string	WrongCat::getType(void) const {
	return (this->type_);
}

void		WrongCat::makeSound(void) const {
	std::cout << "Wrong cat is yowling." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Wrong cat died." << std::endl;
}
