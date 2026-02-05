#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain was given to that poor animal" << std::endl;
}

Brain::Brain(const Brain &Another) {
	for (int i = 0; i < 100; i++)
		this->ideas_[i] = Another.ideas_[i];
	std::cout << "Brain with all ideas was copied" << std::endl;
}

std::string	Brain::getIdea(int i) const {
	return (this->ideas_[i]);
}

void		Brain::setIdea(int i, const std::string idea) {
	this->ideas_[i] = idea;
}

Brain	&Brain::operator=(const Brain &Another) {
	std::cout << "Brain replaced entirely" << std::endl;
	if (this != &Another)
	{
		for (int i = 0; i < 100; i++)
			this->ideas_[i] = Another.ideas_[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain-dead" << std::endl;
}
