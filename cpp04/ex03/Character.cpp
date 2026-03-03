#include "Character.hpp"
#include <iostream>

Character::Character(name) : ICharacter, name_(name) {
	std::cout << "Character named " << this->name_ << " enter the World" << std::endl;
}

Character::Character(const Character &Another) : name_(Another.name_) {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory_[i])
			delete *this->inventory_[i];
		if (Another.inventory_[i])
			*this->inventory_[i] = new Another.inventory_[i];
	}
	std::cout << "Full copy of " << Another.name_ << " was created" << std::endl;
}

Character	&Character::operator=(const Character &Another) {
	if (this != &Another)
	{
		this->name_ = Another.name_;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory_[i])
				delete *this->inventory_[i];
			if (Another.inventory_[i])
				*this->inventory_[i] = new Another.inventory_[i];
		}
	}
	std::cout << this->name_ " reborn as " << Another.name_ << std::endl;
	return (*this);
}

std::string const	&Character::getName() const {
	return (this->name_);
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory_[i])
		{	
			if (*m)
				*this->inventory_[i] = new *m;
			return ;
		}
		continue ;
	}
}

void	Character::unequip(int idx) {
	if (this->inventory_[idx])
		delete *this->inventory_[idx];
}

void	Character::use(int idx, ICharacter &target) {
	*this->inventory_[idx].use(target);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory_[i])
			delete *this->inventory_[i];
	}
	std::cout << "Character destroyed" << std::endl;
}
