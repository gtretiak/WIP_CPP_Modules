#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Wrong cat was born" << std::endl;
}

WrongCat::WrongCat(const WrongCat &Another) : WrongAnimal(Another) {
	std::cout << "Wrong cat was cloned" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &Another) {
	std::cout << "WrongCat was reborn" << std::endl;
	if (this != &Another)
		WrongAnimal::operator=(Another);
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "Wrong cat is yowling" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Wrong cat died" << std::endl;
}
