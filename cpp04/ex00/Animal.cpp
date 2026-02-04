#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() : type_("Animal") {
	std::cout << "Animal was born." << std::endl;
}

Animal::Animal(std::string type) : type_(type) {
	std::cout << "Animal with defined type was born." << std::endl;
}

Animal::Animal(const Animal &Another) : type_(Another.type_) {
	std::cout << "Animal cloned." << std::endl;
}

Animal	&Animal::operator=(const Animal &Another) {
	std::cout << "Animal reborn." << std::endl;
	if (this != &Another)
		this->type_ = Another.type_;
	return (*this);
}

std::string	Animal::getType(void) const {
	return (this->type_);
}

void		Animal::makeSound(void) const {
	std::cout << "Animal makes sound." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal died." << std::endl;
}
