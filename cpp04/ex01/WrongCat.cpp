#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat"), myBrain_(new Brain()) {
	std::cout << "Wrong cat was born" << std::endl;
}

WrongCat::WrongCat(const WrongCat &Another) : WrongAnimal(Another), myBrain_(Another.myBrain_) {
	std::cout << "Wrong cat was shallow-cloned" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &Another) {
	if (this != &Another)
	{
		WrongAnimal::operator=(Another);
		this->myBrain_ = Another.myBrain_; // pointer copy
	}
	std::cout << "WrongCat was shallow-reborn" << std::endl;
	return (*this);
}

std::string	WrongCat::getIdea(int i) const {
	return (this->myBrain_->getIdea(i));
}

void	WrongCat::setIdea(int i, const std::string idea) {
	this->myBrain_->setIdea(i, idea);
}

void	WrongCat::makeSound(void) const {
	std::cout << "Wrong cat is yowling" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Wrong cat died and left unfreed brain" << std::endl;
//	Otherwise it'll be invalid pointer on the 2nd free (already freed):
//	delete (this->myBrain_);
}
