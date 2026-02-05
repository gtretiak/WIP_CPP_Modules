#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat() : AAnimal("Cat"), myBrain_(new Brain()) {
	std::cout << "Cat was born" << std::endl;
}

Cat::Cat(const std::string name) : AAnimal(name), myBrain_(new Brain()) {
	std::cout << "Cat with name " << name << " was born" << std::endl;
}

Cat::Cat(const Cat &Another) : AAnimal(Another), myBrain_(new Brain(*Another.myBrain_)) {
	std::cout << "Cat cloned" << std::endl;
}

Cat	&Cat::operator=(const Cat &Another) {
	if (this != &Another)
	{
		AAnimal::operator=(Another);
		*this->myBrain_ = *Another.myBrain_;
	}
	std::cout << "Cat was reborn" << std::endl;
	return (*this);
}

std::string	Cat::getIdea(int i) const {
	return (this->myBrain_->getIdea(i));
}

void	Cat::setIdea(int i, const std::string idea) {
	this->myBrain_->setIdea(i, idea);
}

void	Cat::makeSound(void) const {
	std::cout << "Cat says \"meow\"" << std::endl;
}

Cat::~Cat() {
	delete (this->myBrain_);
	std::cout << "Cat died" << std::endl;
}
