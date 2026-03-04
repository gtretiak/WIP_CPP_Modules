#include "MateriaSource.hpp"
#include <string>
#include <iostream>

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource class built" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &Another) {
	for (int i = 0; i < 4; i++)
	{
		if (Another.templates_[i])
			this->templates_[i] = Another.templates_[i]->clone();
	}
	std::cout << "MateriaSource class copied" << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &Another) {
	for (int i = 0; i < 4; i++)
	{
		if (Another.templates_[i])
			this->templates_[i] = Another.templates_[i]->clone();
	}
	std::cout << "MateriaSource class reassigned" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *reference) {
	for (int i = 0; i < 4; i++)
	{
		if (this->templates_[i])
			continue ;
		this->templates_[i] = reference.clone();
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->templates_[i]->type_ != type)
			continue ;
		return (this->templates_[i]->clone());
	}
	return (0);
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource class destroyed" << std::endl;
}
