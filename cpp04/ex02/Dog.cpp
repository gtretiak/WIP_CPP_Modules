#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog() : AAnimal("Dog"), myBrain_(new Brain()) {
	std::cout << "Dog was born" << std::endl;
}

Dog::Dog(const std::string name) : AAnimal(name), myBrain_(new Brain()) {
	std::cout << "Dog with name " << name << " was born" << std::endl;
}

Dog::Dog(const Dog &Another) : AAnimal(Another), myBrain_(new Brain(*Another.myBrain_)) {
	std::cout << "Dog cloned" << std::endl;
}

Dog	&Dog::operator=(const Dog &Another) {
	if (this != &Another)
	{
		AAnimal::operator=(Another);
		*this->myBrain_ = *Another.myBrain_;
	}
	std::cout << "Dog was reborn" << std::endl;
	return (*this);
}

std::string	Dog::getIdea(int i) const {
	return (this->myBrain_->getIdea(i));
}

void	Dog::setIdea(int i, const std::string idea) {
	this->myBrain_->setIdea(i, idea);
}

void	Dog::makeSound(void) const {
	std::cout << "Dog says \"woof\"" << std::endl;
}

Dog::~Dog() {
	delete (this->myBrain_);
	std::cout << "Dog died" << std::endl;
}
